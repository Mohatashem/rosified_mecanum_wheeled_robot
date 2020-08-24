cmake_minimum_required(VERSION 3.0.2)
project(mecanum_pid)

find_package(catkin REQUIRED COMPONENTS
  dynamic_reconfigure
  message_generation
  roscpp
  std_msgs
  mecanum_msgs
)

generate_messages(
    DEPENDENCIES
    std_msgs
)

generate_dynamic_reconfigure_options(
    cfg/mecanumPID.cfg
)


catkin_package(
       INCLUDE_DIRS include
       CATKIN_DEPENDS dynamic_reconfigure message_runtime roscpp std_msgs mecanum_msgs
)

include_directories(include ${catkin_INCLUDE_DIRS})

# Set the name to use for the executable
set (BINNAME1 pid_configure)
set (BINNAME2 pid_listen)

# Setting the source files to be used with the executable
set (SRCS1 ${SRCS1} src/mecanum_pid_core.cpp)
set (SRCS1 ${SRCS1} src/pid_configure.cpp)
set (SRCS2 ${SRCS2} src/mecanum_pid_core.cpp)
set (SRCS2 ${SRCS2} src/pid_listen.cpp)


# Build executables that will be used to run this node.
add_executable (${BINNAME1} ${SRCS1})
target_link_libraries(${BINNAME1}  ${catkin_LIBRARIES})
add_dependencies(${BINNAME1} ${PROJECT_NAME}_gencfg)
add_executable(${BINNAME2} ${SRCS2})
target_link_libraries(${BINNAME2}  ${catkin_LIBRARIES})
add_dependencies(${BINNAME2} ${PROJECT_NAME}_gencfg)


install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
   FILES_MATCHING PATTERN "*.h"
)



install(TARGETS ${BINNAME1}
RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
)

install(TARGETS ${BINNAME2}
RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
)

install(DIRECTORY LAUNCH ${BINNAME2}
 DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION} 
)















