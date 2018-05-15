/*
 * ros_joy_main.cpp
 *
 *  Created on: May 15, 2018
 *      Author: auto3
 */
#include <iostream>
#include <ros/ros.h>
#include "RosJoyClass.h"

using namespace std;

int main(int argc, char *argv[]){
	bool button_green = false;
	bool button_red = false;
	bool button_blue = false;
	bool button_orange = false;
	bool button_start = false;
	int steer_axis = 0;
	int throttle_axis = 5;
	double steer = 0.0;
	double throttle = 0.0;

	ros::init(argc, argv, "joy_test");
	ros::NodeHandle nh;
	RosJoyClass joy_stick = RosJoyClass(nh);
	ros::Rate loop_rate(10);
	while(ros::ok()){
		steer = joy_stick.get_axis(steer_axis);
		throttle = joy_stick.get_axis(throttle_axis);
		button_start = joy_stick.get_button(7);
		cout << "start: " << button_start << " steer: " << steer << " throttle: " << throttle << endl;
		ros::spinOnce();
		loop_rate.sleep();
	}

	return 0;
}
