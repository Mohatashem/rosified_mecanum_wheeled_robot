#include "mecanum_base.h"

int main(int argc, char** argv)
{
	ros::init(argc, argv,"mecanum_base_node");
	MecanumBase mecanum;
	ros::spin();
	return 0;
}
