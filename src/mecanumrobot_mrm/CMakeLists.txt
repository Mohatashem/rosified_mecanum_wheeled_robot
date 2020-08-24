cmake_minimum_required(VERSION 3.0.2)
project(mecanumrobot_mrm)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  geometry_msgs
  mecanum_msgs
  nav_msgs
  sensor_msgs
  std_msgs
  tf2
  tf2_ros
)


catkin_package(
  INCLUDE_DIRS include
  LIBRARIES mecanumrobot_mrm
  CATKIN_DEPENDS roscpp rospy geometry_msgs mecanum_msgs nav_msgs sensor_msgs std_msgs system_lib tf2 tf2_ros
  DEPENDS system_lib
)


include_directories(
 include
  ${catkin_INCLUDE_DIRS}
)


add_library(mecanum_base src/mecanum_base.cpp)
add_executable(mecanum_base_node src/mecanum_base_node.cpp)
target_link_libraries(mecanum_base_node mecanum_base ${catkin_LIBRARIES})
add_dependencies(mecanum_base mecanum_msgs_generate_messages_cpp)



