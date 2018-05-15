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
	bool button_start = false;
	double steer = 0.0;
	double throttle = 0.0;
	double brake = 0.0;

	ros::init(argc, argv, "joy_test");
	ros::NodeHandle nh;
	RosJoyClass joy_stick = RosJoyClass(nh);
	ros::Rate loop_rate(10);
	while(ros::ok()){
		steer = joy_stick.get_axis(joy_stick.LEFT_X);
		throttle = joy_stick.get_axis(joy_stick.RT);
		brake = joy_stick.get_axis(joy_stick.LT);
		button_start = joy_stick.get_button(joy_stick.START);
		cout << "start: " << button_start << " steer: " << steer << " throttle: " << throttle << " brake: " << brake << endl;
		ros::spinOnce();
		loop_rate.sleep();
	}
	delete joy;
	cout << "joy terminated..." << endl;
	return 0;
}
