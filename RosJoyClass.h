/*
 * RosJoyClass.h
 *
 *  Created on: May 15, 2018
 *      Author: auto3
 */

#ifndef ROSJOYCLASS_H_
#define ROSJOYCLASS_H_

#include <ros/ros.h>
#include <sensor_msgs/Joy.h>

class RosJoyClass{
public:
	enum _buttons { GREEN, RED, BLUE, ORANGE, LB, RB, BACK, START, BTN_UNDEFINED, NUM_BUTTONS };
	enum _axis { LEFT_X, LEFT_Y, LT, RIGHT_X, RIGHT_Y, RT, HAT_X, HAT_Y, AXIS_UNDEFINED, NUM_AXIS };
	RosJoyClass(ros::NodeHandle nh);
	bool get_button(int button_num);
	double get_axis(int axis_num);

private:
	void joy_callback(const sensor_msgs::Joy::ConstPtr &joy);
	bool button[NUM_BUTTONS];
	double axis[NUM_AXIS];
	ros::Subscriber joy_sub_;
};

#endif /* ROSJOYCLASS_H_ */
