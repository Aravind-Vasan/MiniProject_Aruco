import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import numpy as np


class ArucoMarkerDetector(Node):
    def __init__(self):
        super().__init__('aruco_marker_detector')
        self.declare_parameter('camera_topic', '/camera/image_raw')
        self.declare_parameter('aruco_dicts', ['DICT_4X4_50', 'DICT_6X6_250'])  # Multiple dictionaries
        self.declare_parameter('marker_size', 0.02)  # Marker size in meters

        self.camera_topic = self.get_parameter('camera_topic').get_parameter_value().string_value
        self.aruco_dict_names = self.get_parameter('aruco_dicts').get_parameter_value().string_array_value
        self.marker_size = self.get_parameter('marker_size').get_parameter_value().double_value

        self.image_sub = self.create_subscription(Image, self.camera_topic, self.image_callback, 10)
        self.bridge = CvBridge()

        # Load multiple ArUco dictionaries
        self.aruco_dicts = {}
        for dict_name in self.aruco_dict_names:
            try:
                self.aruco_dicts[dict_name] = cv2.aruco.getPredefinedDictionary(getattr(cv2.aruco, dict_name))
            except AttributeError:
                self.get_logger().error(f"Invalid ArUco dictionary name: {dict_name}")

        self.aruco_params = cv2.aruco.DetectorParameters()

        self.get_logger().info(f'ArUco Marker Detector Node Started with dictionaries: {self.aruco_dict_names}')

    def image_callback(self, msg):
        try:
            frame = self.bridge.imgmsg_to_cv2(msg, desired_encoding='rgb8')
        except Exception as e:
            self.get_logger().error(f'Failed to convert image: {e}')
            return

        detected_markers = []

        # Iterate through each dictionary to detect markers
        for dict_name, aruco_dict in self.aruco_dicts.items():
            corners, ids, rejected = cv2.aruco.detectMarkers(frame, aruco_dict, parameters=self.aruco_params)

            if ids is not None:
                detected_markers.append((dict_name, ids.flatten()))
                frame = cv2.aruco.drawDetectedMarkers(frame, corners, ids)

        # Log detected markers from all dictionaries
        if detected_markers:
            for dict_name, ids in detected_markers:
                self.get_logger().info(f'Detected markers from {dict_name}: {ids}')

        # Show the image with detected markers
        cv2.imshow('ArUco Marker Detection', frame)
        cv2.waitKey(1)


def main(args=None):
    rclpy.init(args=args)
    node = ArucoMarkerDetector()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
    cv2.destroyAllWindows()


if __name__ == '__main__':
    main()