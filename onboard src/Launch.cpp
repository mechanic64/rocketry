///****************************************************************
/// @file: Launch.cpp
/// @author: Ben Olson
/// 
/// @details This is a cpp file launching the rocket, looping and collecting data.
/// @details Written for the NCC Rocket Club 2023 
///****************************************************************




#include "Adafruit_GPS.h"
#include "Rocket.cpp"
#include <stdio.h>
#include "IMU.c"
#include <string.h>


using namespace std;

int main(bool a)
{
	bool run = false;
	run = a;

	Rocket rock = new Rocket();
	Adafruit_GPS gps = new Adafruit_GPS();

	//loop setting data to the rocket every set time frame
	while (run)
	{

	}
}
