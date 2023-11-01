/*
 * This code will control one single leg on the H8OA robot.
 * 
 * Created by Sondre Meiland-Flakstad
 * Date: 2023-10-18
 * Last modified by Sondre Meiland-Flakstad
 * Date: 2023-10-20
 * 
 * Relevant tutorials:
 * https://lastminuteengineers.com/28byj48-stepper-motor-arduino-tutorial/
 */

#include <AccelStepper.h>
#include <SoftwareSerial.h>

#define CENTRAL_RX 2
#define CENTRAL_TX 3

#define MOTOR_INTERFACE_TYPE 4
#define MAX_SPEED 1000.0
#define ACCELERATION 8000.0
#define SPEED 200

SoftwareSerial mySerial(CENTRAL_RX, CENTRAL_TX);
AccelStepper myStepper(MOTOR_INTERFACE_TYPE, 8, 10, 9, 11);


void calibrate() {

}

void read_serial() {

	if (mySerial.available()) {

	}
}





void setup() {
	myStepper.setMaxSpeed(MAX_SPEED);
	myStepper.setAcceleration(ACCELERATION);
	myStepper.setSpeed(SPEED);
	myStepper.moveTo(250);
}

void loop() {
	// Change direction once the motor reaches target position
	if (myStepper.distanceToGo() == 0) 
		myStepper.moveTo(-myStepper.currentPosition());

	// Move the motor one step
	myStepper.run();
}