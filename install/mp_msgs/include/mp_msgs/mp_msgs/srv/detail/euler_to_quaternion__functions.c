// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from mp_msgs:srv/EulerToQuaternion.idl
// generated code does not contain a copyright notice
#include "mp_msgs/srv/detail/euler_to_quaternion__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
mp_msgs__srv__EulerToQuaternion_Request__init(mp_msgs__srv__EulerToQuaternion_Request * msg)
{
  if (!msg) {
    return false;
  }
  // roll
  // pitch
  // yaw
  return true;
}

void
mp_msgs__srv__EulerToQuaternion_Request__fini(mp_msgs__srv__EulerToQuaternion_Request * msg)
{
  if (!msg) {
    return;
  }
  // roll
  // pitch
  // yaw
}

bool
mp_msgs__srv__EulerToQuaternion_Request__are_equal(const mp_msgs__srv__EulerToQuaternion_Request * lhs, const mp_msgs__srv__EulerToQuaternion_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // roll
  if (lhs->roll != rhs->roll) {
    return false;
  }
  // pitch
  if (lhs->pitch != rhs->pitch) {
    return false;
  }
  // yaw
  if (lhs->yaw != rhs->yaw) {
    return false;
  }
  return true;
}

bool
mp_msgs__srv__EulerToQuaternion_Request__copy(
  const mp_msgs__srv__EulerToQuaternion_Request * input,
  mp_msgs__srv__EulerToQuaternion_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // roll
  output->roll = input->roll;
  // pitch
  output->pitch = input->pitch;
  // yaw
  output->yaw = input->yaw;
  return true;
}

mp_msgs__srv__EulerToQuaternion_Request *
mp_msgs__srv__EulerToQuaternion_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mp_msgs__srv__EulerToQuaternion_Request * msg = (mp_msgs__srv__EulerToQuaternion_Request *)allocator.allocate(sizeof(mp_msgs__srv__EulerToQuaternion_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mp_msgs__srv__EulerToQuaternion_Request));
  bool success = mp_msgs__srv__EulerToQuaternion_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mp_msgs__srv__EulerToQuaternion_Request__destroy(mp_msgs__srv__EulerToQuaternion_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mp_msgs__srv__EulerToQuaternion_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mp_msgs__srv__EulerToQuaternion_Request__Sequence__init(mp_msgs__srv__EulerToQuaternion_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mp_msgs__srv__EulerToQuaternion_Request * data = NULL;

  if (size) {
    data = (mp_msgs__srv__EulerToQuaternion_Request *)allocator.zero_allocate(size, sizeof(mp_msgs__srv__EulerToQuaternion_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mp_msgs__srv__EulerToQuaternion_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mp_msgs__srv__EulerToQuaternion_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
mp_msgs__srv__EulerToQuaternion_Request__Sequence__fini(mp_msgs__srv__EulerToQuaternion_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mp_msgs__srv__EulerToQuaternion_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

mp_msgs__srv__EulerToQuaternion_Request__Sequence *
mp_msgs__srv__EulerToQuaternion_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mp_msgs__srv__EulerToQuaternion_Request__Sequence * array = (mp_msgs__srv__EulerToQuaternion_Request__Sequence *)allocator.allocate(sizeof(mp_msgs__srv__EulerToQuaternion_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mp_msgs__srv__EulerToQuaternion_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mp_msgs__srv__EulerToQuaternion_Request__Sequence__destroy(mp_msgs__srv__EulerToQuaternion_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mp_msgs__srv__EulerToQuaternion_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mp_msgs__srv__EulerToQuaternion_Request__Sequence__are_equal(const mp_msgs__srv__EulerToQuaternion_Request__Sequence * lhs, const mp_msgs__srv__EulerToQuaternion_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mp_msgs__srv__EulerToQuaternion_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mp_msgs__srv__EulerToQuaternion_Request__Sequence__copy(
  const mp_msgs__srv__EulerToQuaternion_Request__Sequence * input,
  mp_msgs__srv__EulerToQuaternion_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mp_msgs__srv__EulerToQuaternion_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mp_msgs__srv__EulerToQuaternion_Request * data =
      (mp_msgs__srv__EulerToQuaternion_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mp_msgs__srv__EulerToQuaternion_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mp_msgs__srv__EulerToQuaternion_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mp_msgs__srv__EulerToQuaternion_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
mp_msgs__srv__EulerToQuaternion_Response__init(mp_msgs__srv__EulerToQuaternion_Response * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // z
  // w
  return true;
}

void
mp_msgs__srv__EulerToQuaternion_Response__fini(mp_msgs__srv__EulerToQuaternion_Response * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // z
  // w
}

bool
mp_msgs__srv__EulerToQuaternion_Response__are_equal(const mp_msgs__srv__EulerToQuaternion_Response * lhs, const mp_msgs__srv__EulerToQuaternion_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // z
  if (lhs->z != rhs->z) {
    return false;
  }
  // w
  if (lhs->w != rhs->w) {
    return false;
  }
  return true;
}

bool
mp_msgs__srv__EulerToQuaternion_Response__copy(
  const mp_msgs__srv__EulerToQuaternion_Response * input,
  mp_msgs__srv__EulerToQuaternion_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // z
  output->z = input->z;
  // w
  output->w = input->w;
  return true;
}

mp_msgs__srv__EulerToQuaternion_Response *
mp_msgs__srv__EulerToQuaternion_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mp_msgs__srv__EulerToQuaternion_Response * msg = (mp_msgs__srv__EulerToQuaternion_Response *)allocator.allocate(sizeof(mp_msgs__srv__EulerToQuaternion_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mp_msgs__srv__EulerToQuaternion_Response));
  bool success = mp_msgs__srv__EulerToQuaternion_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mp_msgs__srv__EulerToQuaternion_Response__destroy(mp_msgs__srv__EulerToQuaternion_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mp_msgs__srv__EulerToQuaternion_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mp_msgs__srv__EulerToQuaternion_Response__Sequence__init(mp_msgs__srv__EulerToQuaternion_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mp_msgs__srv__EulerToQuaternion_Response * data = NULL;

  if (size) {
    data = (mp_msgs__srv__EulerToQuaternion_Response *)allocator.zero_allocate(size, sizeof(mp_msgs__srv__EulerToQuaternion_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mp_msgs__srv__EulerToQuaternion_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mp_msgs__srv__EulerToQuaternion_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
mp_msgs__srv__EulerToQuaternion_Response__Sequence__fini(mp_msgs__srv__EulerToQuaternion_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mp_msgs__srv__EulerToQuaternion_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

mp_msgs__srv__EulerToQuaternion_Response__Sequence *
mp_msgs__srv__EulerToQuaternion_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mp_msgs__srv__EulerToQuaternion_Response__Sequence * array = (mp_msgs__srv__EulerToQuaternion_Response__Sequence *)allocator.allocate(sizeof(mp_msgs__srv__EulerToQuaternion_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mp_msgs__srv__EulerToQuaternion_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mp_msgs__srv__EulerToQuaternion_Response__Sequence__destroy(mp_msgs__srv__EulerToQuaternion_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mp_msgs__srv__EulerToQuaternion_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mp_msgs__srv__EulerToQuaternion_Response__Sequence__are_equal(const mp_msgs__srv__EulerToQuaternion_Response__Sequence * lhs, const mp_msgs__srv__EulerToQuaternion_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mp_msgs__srv__EulerToQuaternion_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mp_msgs__srv__EulerToQuaternion_Response__Sequence__copy(
  const mp_msgs__srv__EulerToQuaternion_Response__Sequence * input,
  mp_msgs__srv__EulerToQuaternion_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mp_msgs__srv__EulerToQuaternion_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mp_msgs__srv__EulerToQuaternion_Response * data =
      (mp_msgs__srv__EulerToQuaternion_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mp_msgs__srv__EulerToQuaternion_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mp_msgs__srv__EulerToQuaternion_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mp_msgs__srv__EulerToQuaternion_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
