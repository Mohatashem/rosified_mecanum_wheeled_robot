#include "mecanum_pid/mecanum_pid_core.h"

int main(int argc, char **argv)

{

  ros::init(argc, argv, "pid_listener");
  ros::NodeHandle nh;
  
  int rate;

  ros::NodeHandle pnh("~");
  pnh.param("rate", rate, int(40));
  
  MecanumPID *mecanum_pid = new MecanumPID();

  ros::Subscriber sub_message = nh.subscribe("pid", 1000, &MecanumPID::messageCallback, mecanum_pid);
 
  ros::Rate r(rate);

  //Main loop
  while (nh.ok())
  {
    ros::spinOnce();
    r.sleep();
    }
  return 0;
} 
 




