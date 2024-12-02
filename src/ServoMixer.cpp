/*
	This function takes the signed float values created by the PID controllers (for servos+throttle) and converts it back into PPM signals. Note this isn’t a class.
* Takes in signed float values for roll, pitch, and throttle
* Converts to two servo PPM signals and one throttle PPM signal
* Servo1 = Pitch + Roll
* Servo2 = Pitch - Roll (same signal for pitch as they should match, reversed roll for complementary motion)

*/