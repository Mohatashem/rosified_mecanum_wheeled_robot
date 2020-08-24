#include "mecanum_base.h"

MecanumBase::MecanumBase(): 
 	// constructor initialization way of initialization variables.
	linear_velocity_x_(0),
	linear_velocity_y_(0),
	angular_velocity_z_(0),
	last_vel_time_(0),
	vel_dt_(0),
	x_pos_(0),
	y_pos_(0),
	heading_(0)

{
	odom_publisher_ = nh_.advertise<nav_msgs::Odometry>("raw_odom", 50);
	velocity_subscriber_ = nh_.subscribe("raw_vel", 50, &MecanumBase::velCallback, this);
}

void MecanumBase::velCallback(const mecanum_msgs::Velocities& vel)
{

	ros::Time current_time = ros::Time::now();

	linear_velocity_x_ = vel.linear_x;
	linear_velocity_y_ = vel.linear_y;
	angular_velocity_z_ = vel.angular_z;

	vel_dt_ = (current_time-last_vel_time_).toSec();
	last_vel_time_ = current_time;

	double delta_heading = angular_velocity_z_ * vel_dt_; // in radians
	double delta_x = (linear_velocity_x_ * cos(heading_) - linear_velocity_y_ * sin(heading_)) * vel_dt_; // in metres
	double delta_y = (linear_velocity_x_ * sin(heading_) + linear_velocity_y_ * cos(heading_)) * vel_dt_; // in metres

	// calculate current position of the robot

	x_pos_ += delta_x;
	y_pos_ += delta_y;
	heading_ += delta_heading;

	// calculation of robots's heading in quaternion form
	// ROS has a function to convert from yaw to quaternion angle

	odom_quat.setRPY(0,0,heading_);

	odom_trans.header.frame_id = "odom"; // these we will be able to visualize in rviz
	odom_trans.child_frame_id = "base_footprint"; // these as well

	//robot's position in x, y and z
	odom_trans.transform.translation.x = x_pos_;
	odom_trans.transform.translation.y = y_pos_;
	odom_trans.transform.translation.z = 0.0;

	//robot's heading in quaternion
	odom_trans.transform.rotation.x = odom_quat.x(); // remember its is geometry_msgs type at core
	odom_trans.transform.rotation.y = odom_quat.y();
	odom_trans.transform.rotation.z = odom_quat.z();
	odom_trans.transform.rotation.w = odom_quat.w();
	odom_trans.header.stamp = current_time;

	//publishes the robot's transform using the odom_trans object
	// odom_broadcaster_send.sendTransform(odom_trans);

	odom.header.stamp = current_time;
	odom.header.frame_id = "odom"; // these we will be able to visualize in rviz
	odom.child_frame_id = "base_footprint"; // these as well

	// robot's position in x, y and z

	odom.pose.pose.position.x = x_pos_;
	odom.pose.pose.position.y = y_pos_;
	odom.pose.pose.position.z = 0.0;

	// robot's heading in quaternion
	odom.pose.pose.orientation.x =  odom_quat.x();
	odom.pose.pose.orientation.y =  odom_quat.y();
	odom.pose.pose.orientation.z =  odom_quat.z();
	odom.pose.pose.orientation.w =  odom_quat.w();
	odom.pose.covariance[0] = 0.001;
	odom.pose.covariance[7] = 0.001;
	odom.pose.covariance[35] = 0.001;

	// linear speed from encoders
	odom.twist.twist.linear.x = linear_velocity_x_;
	odom.twist.twist.linear.y = linear_velocity_y_;
	odom.twist.twist.linear.z = 0.0;

	odom.twist.twist.angular.x = 0.0;
	odom.twist.twist.angular.y = 0.0;
	// angular speed from encoders
	odom.twist.twist.angular.z = angular_velocity_z_;
	odom.twist.covariance[0] = 0.0001;
	odom.twist.covariance[7] = 0.0001;
	odom.twist.covariance[35] = 0.0001;

	odom_publisher_.publish(odom);

}

