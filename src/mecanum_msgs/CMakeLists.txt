cmake_minimum_required(VERSION 3.0.2)
project(mecanum_msgs)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  message_generation
  std_msgs
)

add_message_files(
  DIRECTORY msg
  FILES
  Velocities.msg
  PID.msg
  Imu.msg
)

generate_messages(DEPENDENCIES std_msgs geometry_msgs)

catkin_package(CATKIN_DEPENDS message_runtime geometry_msgs)

