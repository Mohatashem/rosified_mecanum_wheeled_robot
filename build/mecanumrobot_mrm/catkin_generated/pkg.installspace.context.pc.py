# generated from catkin/cmake/template/pkg.context.pc.in
CATKIN_PACKAGE_PREFIX = ""
PROJECT_PKG_CONFIG_INCLUDE_DIRS = "${prefix}/include".split(';') if "${prefix}/include" != "" else []
PROJECT_CATKIN_DEPENDS = "roscpp;rospy;geometry_msgs;mecanum_msgs;nav_msgs;sensor_msgs;std_msgs;system_lib;tf2;tf2_ros".replace(';', ' ')
PKG_CONFIG_LIBRARIES_WITH_PREFIX = "-lmecanumrobot_mrm".split(';') if "-lmecanumrobot_mrm" != "" else []
PROJECT_NAME = "mecanumrobot_mrm"
PROJECT_SPACE_DIR = "/home/ubuntu/mecanum_ws/install"
PROJECT_VERSION = "0.0.0"
