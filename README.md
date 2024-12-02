# NoNameRoboticsClub


TODO

Primary

RxIn

	This is a class that initializes with parameters for the used PPM input pins (from flysky IS-A6 RX). This needs to convert the PPM signals to an integer or signed float value to be used in the rest of the program. Should include a function that returns an array[6] of these float/int values.
* Reads from 6 PPM pins
* Initializes with definition of pins
* Contains function to return normalized values

PID

	This is a class that creates a PID output. It is initialized with two tuning values. This should contain a function that takes in a signed float and returns a signed float. 
* Initializes with tuning values for gain and damping
* Internally will implement PID control
* Needs to be reusable anywhere a PID controller is needed
* (Optional) take in a direct PPM or PWM input (for servos) and generate a PPM/PWM output.

KALMAN

	This is a class that takes in gyro, accelerometer, and barometer readings and returns filtered values. Initializes with initial values for all sensors (for prediction to converge). Contains a function that reads in gyro/accelerometer or barometer readings and returns their filtered values.
* Use a Kaman algorithm for each dataset
* Build a separate function/initializer for each type of data input 

ServoMixer

	This function takes the signed float values created by the PID controllers (for servos+throttle) and converts it back into PPM signals. Note this isn’t a class.
* Takes in signed float values for roll, pitch, and throttle
* Converts to two servo PPM signals and one throttle PPM signal
* Servo1 = Pitch + Roll
* Servo2 = Pitch - Roll (same signal for pitch as they should match, reversed roll for complementary motion)

FlightLogger

	Class that initializes by creating a new log file on an SD card or non-volatile memory. Saves recorded inputs, PID commands, Kalman outputs, servo-outputs, and raw sensor data. Actively records structured data in timestamps
* Store as CSV file for In The Loop testing

Main

	.INO file that initializes all required functions/classes and passes data to and from them. This is the main loop that will run the drone
* Initialize RxIn, PID, Kalman, FlightLogger.
* Pass data from RxIn and Kalman to PID, and from PID to ServoMixer
* Send all values to FlightLogger


Secondary

Sensor testing

	.INO file to record raw and filtered (using complementary and Kalman filters) data in a structured format. Displays noise and drift for further analysis. Actively shows 3d/2d diagram of current roll/pitch/ yaw


RXTesting

	.INO file to read PPM signals from Rx, convert to signed floats, reconvert to PPM, and send to servos (passthrough). Should also display read values (including switches) to verify functionality.
* Read PPM signals
* Conver to signed float
* Display sliders/switches
* Output PPM signal to servos

ServoTesting

	.INO file to verify correct servo mixing, required working RX first. Will take in raw inputs from Tx and mix for proper servo output
* Read signed float values from RxIn
* Mix according to defined algorithms
* Convert to PPM signal for servos


