///****************************************************************
/// @file: Rocket.cpp
/// @author: Ben Olson
/// 
/// @details This is a cpp file describing what a rocket "looks-like".
/// @details Written for the NCC Rocket Club 2023 
///****************************************************************




#include <stdio.h>
#include <iostream>
#include "IMU.c"
#include "Adafruit_GPS.h"
#include "Adafruit_GPS.cpp"
#include "NMEA_data.h"
#include <string.h>


class Rocket
{
	private:
		float latitude;
		float longitude;
		float velocity;
		float altitude;
		float flightDist;
		float maxAlt;
		char direction;


	public:
		/* Default Constructor*/
		Rocket()
		{
			latitude = 0.0;
			longitude = 0.0;
			velocity = 0.0;
			altitude = 0.0;
			flightDist = 0.0;
			maxAlt = 0.0;
			direction = 'F';
		};


		/// @brief overloaded constructor
		/// @param float a sets latitude
		/// @param float b sets longitude
		/// @param float c sets velocity
		/// @param float d sets altitude
		/// @param float e sets Flight Distance
		/// @param float f sets the Max Altitude
		/// @param char g sets Direction of pointing rocket
		Rocket(float a, float b, float c, float d, float e, float f, char g)
		{
			latitude = a;
			longitude = b;
			velocity = c;
			altitude = d;
			flightDist = e;
			maxAlt = f;
			direction = g;

		}

		/// @brief copy constructor
		/// @param passes a Rocket object to create another Rocket
		Rocket(const Rocket& R)
		{
			longitude = R.getLong();
			latitude = R.getLat();
			velocity = R.getVel();
			altitude = R.getAlt();
			flightDist = R.getFlightDist();
			maxAlt = R.getMaxAlt();
			direction = R.getDirection();
		};

		/** Access Direction
		 * @return The pointing direction of the Rocket
		 */
		float getDirection() { return direction; };

		/** Access Longitude
		 * @return The longitude of the Rocket
		 */
		float getLong() { return logitude; };

		/** Access Latitude
		 * @return The latitude of the Rocket
		 */
		float getLat() { return latitude; };

		/** Access Velocity
		 * @return The velocity of the Rocket
		 */
		float getVel() { return velocity; };

		/** Access Altitude
		 * @return The current altitude of the Rocket
		 */
		float getAlt() { return altitude; };

		/** Access FlightDist
		 * @return The distance of the Rocket's flight
		 */
		float getFlightDist() { return flightDist; };

		/** Access MaxAlt
		 * @return The maximum altitude achieved
		 */
		float getMaxAlt() { return maxAlt; };

		/** Set Direction
		 * @param val New value to set
		 * @post sets val to the Direction
		 */
		void setLong(float val) { longitude = val; };

		/** Set Longitude
		 * @param val New value to set
		 * @post sets val to the longitude
		 */
		void setLong(float val){ longitude = val; };

		/** Set Latitude
		 * @param val New value to set
		 * @post sets val to the latitude
		 */
		void setLat(float val){ latitude = val; };

		/** Set Velocity
		 * @param val New value to set
		 * @post sets val to the velocity
		 */
		void setVel(float val) { velocity = val; };

		/** Set Altitude
		 * @param val New value to set
		 * @post sets val to the altitude
		 */
		void setAlt(float val) { altitude = val; };

		/** Set FlightDist
		 * @param val New value to set
		 * @post sets val to the flightDist
		 */
		void setFlightDist(float val) { flightDist = val; };

		/** Set maxAlt
		 * @param val New value to set
		 * @post sets val to the maxAlt
		 */
		void setMaxAlt(float val) { if (val > maxAlt) { maxAlt = val; } };

		//calibrate: set everything to zero
		void calibrate()
		{
			this->latitude = 0;
			this->longitude = 0;
			this->velocity = 0;
			this->altitude = 0;
			this->flightDist = 0;
			this->maxAlt = 0;
		};

		//calibrate: set everything to zero, pass lat, long and alt then set to current position
		void calibrate(Adafruit_GPS gps)
		{
			this->latitude = gps.latitude;
			this->longitude = gps.longitude;
			this->velocity = 0;
			this->altitude = gps.altitude;
			this->flightDist = 0;
			this->maxAlt = 0;
			this->direction = gps.mag;
		};
		string display()
		{
			String out;

			// Position(Lat by Long) | Altitude | Speed | Direction
			out << "| " << this->latitude << " | " << this->longitude << " | " << this->altitude << " | " << this->velocity << " | " << this->direction << " |";
		}


		//to do:
		//add facing direction in degrees?
		//add interaction with IMU.... calibrate function....
		//add print rocket details function?
		// calculate velocity as a function of distance versus time?
		//write the main file to create rocket object and run tests with IMU

};
