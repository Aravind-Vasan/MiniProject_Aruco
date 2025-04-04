#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image, CameraInfo
from cv_bridge import CvBridge
import cv2
import cv2.aruco as aruco
import numpy as np

class MarkerDetector(Node):
    def __init__(self):
        super().__init__('marker_detector')
        
        # Subscribe to camera image
        self.sub_image = self.create_subscription(
            Image,
            '/mp/rgb_camera/image_raw',  # Your camera topic
            self.image_callback,
            10
        )
        
        # Subscribe to camera info (for calibration)
        self.sub_camera_info = self.create_subscription(
            CameraInfo,
            '/mp/rgb_camera/camera_info',
            self.camera_info_callback,
            10
        )
        
        self.bridge = CvBridge()
        self.aruco_dict = aruco.getPredefinedDictionary(aruco.DICT_4X4_50)
        self.parameters = aruco.DetectorParameters()
        
        # Camera calibration parameters
        self.camera_matrix = None
        self.dist_coeffs = None
        self.marker_size = 0.5  # Adjust to your marker's real size (meters)

    def camera_info_callback(self, msg):
        """Get camera intrinsic parameters from /camera_info"""
        self.camera_matrix = np.array(msg.k).reshape(3, 3)
        self.dist_coeffs = np.array(msg.d)
        self.get_logger().info("Received camera calibration parameters")

    def image_callback(self, msg):
        try:
            # Convert ROS Image to OpenCV
            cv_image = self.bridge.imgmsg_to_cv2(msg, 'bgr8')
            gray = cv2.cvtColor(cv_image, cv2.COLOR_BGR2GRAY)
            
            # Detect ArUco markers
            corners, ids, _ = aruco.detectMarkers(gray, self.aruco_dict, parameters=self.parameters)
            
            if ids is not None:
                # Draw detected markers
                aruco.drawDetectedMarkers(cv_image, corners, ids)
                
                # Pose estimation (if camera is calibrated)
                if self.camera_matrix is not None and self.dist_coeffs is not None:
                    rvecs, tvecs, _ = aruco.estimatePoseSingleMarkers(
                        corners, self.marker_size, self.camera_matrix, self.dist_coeffs
                    )
                    
                    for i in range(len(ids)):
                        # Draw marker axis
                        cv2.drawFrameAxes(
                            cv_image, self.camera_matrix, self.dist_coeffs,
                            rvecs[i], tvecs[i], 0.1
                        )
                        self.get_logger().info(
                            f"Marker {ids[i][0]} detected at position: {tvecs[i][0]}"
                        )
            
            # Display
            cv2.imshow("Marker Detection", cv_image)
            cv2.waitKey(1)
            
        except Exception as e:
            self.get_logger().error(f"Error processing image: {str(e)}")

def main(args=None):
    rclpy.init(args=args)
    node = MarkerDetector()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()