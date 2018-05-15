/*
 * RosJoyClass.cpp
 *
 *  Created on: May 15, 2018
 *      Author: auto3
 */
#include <iostream>
#include "RosJoyClass.h"

using namespace std;

RosJoyClass::RosJoyClass(ros::NodeHandle nh_){
	for(int i = 0; i < NUM_BUTTONS; i++)
		button[i] = false;
	axis[LEFT_X] = 0.0;
	axis[LEFT_Y] = 0.0;
	axis[LT] = 1.0;
	axis[RIGHT_X] = 0.0;
	axis[RIGHT_Y] = 0.0;
	axis[RT] = 1.0;
	axis[HAT_X] = 0.0;
	axis[HAT_Y] = 0.0;
	joy_sub_ = nh_.subscribe<sensor_msgs::Joy>("joy", 10, &RosJoyClass::joy_callback, this);
}

bool RosJoyClass::get_button(int button_num){
	return button[button_num];
}

double RosJoyClass::get_axis(int axis_num){
	return axis[axis_num];
}

void RosJoyClass::joy_callback(const sensor_msgs::Joy::ConstPtr &joy){
	for(int i = 0; i < NUM_BUTTONS; i++)
		button[i] = joy->buttons[i];
	for(int j = 0; j < NUM_AXIS; j++)
		axis[j] = joy->axes[j];

}

