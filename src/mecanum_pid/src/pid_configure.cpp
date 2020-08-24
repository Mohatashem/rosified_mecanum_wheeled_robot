#include "mecanum_pid/mecanum_pid_core.h"

int main(int argc, char **argv)
{
	
  ros::init(argc,argv,"pid_configure");
  ros::NodeHandle nh;

  MecanumPID *mecanum_pid = new MecanumPID();
  
  dynamic_reconfigure::Server<mecanum_pid::mecanumPIDConfig> dr_srv;
  dynamic_reconfigure::Server<mecanum_pid::mecanumPIDConfig>::CallbackType cb;
  cb = boost::bind(&MecanumPID::configCallback,mecanum_pid,_1,_2);
  dr_srv.setCallback(cb);

  double p;
  double i;
  double d;
  int rate;

  ros::NodeHandle pnh("~");
  pnh.param("p",p,0.6);
  pnh.param("d",i,0.3);
  pnh.param("i",d,0.5);
  pnh.param("rate",rate,1);

  ros::Publisher pub_message = nh.advertise<mecanum_msgs::PID>("pid",10);
  ros::Rate r(rate);

  while(nh.ok())
  {
   mecanum_pid->publishMessage(&pub_message);
   ros::spinOnce();
   r.sleep();


  }
  return 0;
}
