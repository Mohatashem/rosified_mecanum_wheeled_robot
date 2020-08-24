#include "mecanum_pid/mecanum_pid_core.h"

MecanumPID::MecanumPID()
{
}

MecanumPID::~MecanumPID()
{
}

void MecanumPID::publishMessage(ros::Publisher *pub_message)
{
	mecanum_msgs::PID msg;
	msg.p = p_;
	msg.d = d_;	
	msg.i = i_;	
	pub_message->publish(msg);
}

void MecanumPID::messageCallback(const mecanum_msgs::PID::ConstPtr &msg)
{
	p_ = msg->p;
	d_ = msg->d;
	i_ = msg->i;
	

// echo PID

	ROS_INFO("P:  %f",p_);
	ROS_INFO("D:  %f",d_);	
	ROS_INFO("I:  %f",i_);
	
}

void MecanumPID::configCallback(mecanum_pid::mecanumPIDConfig &config,double level)
{
// for PID Gui
	p_ = config.p;
	d_ = config.d;
	i_ = config.i;
	
}
