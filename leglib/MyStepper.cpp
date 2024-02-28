/**
 * A container file defining all features belonging to the custom stepper class.
 * 
 * @author Sondre Meiland-Flakstad
 * @date 2024-02-20
 * @version 0.2 2023-02-21
 */


#include <Stepper.h>
#include "MyStepper.h"

/**
 * Constructor for the custom stepper class
 * 
 * @param pin1 Pin1 for the servo connector
 * @param pin2 Pin2 for the servo connector
 * @param pin3 Pin3 for the servo connector
 * @param pin4 Pin4 for the servo connector
 */
MyStepper::MyStepper(int pin1, int pin2, int pin3, int pin4) {
  _stepper = new Stepper(steps_per_revolution, pin1, pin2, pin3, pin4);
  _stepper->setSpeed(this->default_speed);
  setHome();
  setLimits(-45, 45);
}

/**
 * Sets the upper and lower limit for what step the servo can be at.
 * 
 * @param minStep Lower bound of the stepper servo
 * @param maxStep Upper bound of the stepper servo
 */
void MyStepper::setLimits(int minStep, int maxStep) {
  minSteps = minStep;
  maxSteps = maxStep;
}

/**
 * Resets the current home location of the servo
 */
void MyStepper::setHome() {
  currentStep = 0;
}



/**
 * Rotates the servo by the given angle.
 * Will lock the software until the rotation is complete
 * 
 * @param step total angle to be rotated
 */
void MyStepper::rotateBy_angle(double angle) {
  rotateBy_step(angleToSteps(angle));
}

/**
 * Rotates the servo to the given angle relative to home.
 * Will lock the software until the rotation is complete
 * 
 * @param angle The angle to rotate to
 */
void MyStepper::rotateTo_angle(double angle) {
  rotateTo_step(angleToSteps(angle));
}

/**
 * Steps once towards the given angle.
 * Useful when trying to rotate several steppers at a time.
 * 
 * @param step The angle to rotate towards
 */
void MyStepper::stepTo_angle(double angle) {
  stepTo_step(angleToSteps(angle));
}

/**
 * Rotates the servo by the given amount of steps.
 * Will lock the software until the rotation is complete
 * 
 * @param step total amount of steps to be rotated (pos or neg)
 */
void MyStepper::rotateBy_step(int step) {
  int deltaStep = step;
  limitStep(deltaStep)
  _stepper->step(deltaStep);
}

/**
 * Rotates the servo to the given step location relative to home.
 * Will lock the software until the rotation is complete
 * 
 * @param step The step position to rotate to
 */
void MyStepper::rotateTo_step(int step) {
  int deltaStep = step - currentStep;
  limitStep(deltaStep);
  _stepper->step(deltaStep);
}

/**
 * Steps once towards the given step location.
 * Useful when trying to rotate several steppers at a time.
 * 
 * @param step The step position to rotate towards
 */
void MyStepper::stepTo_step(int step) {
  int deltaStep = step - currentStep;
  if (deltaStep > 0) deltaStep = 1;
  else if (deltaStep < 0) deltaStep = -1;
  limitStep(deltaStep);
  _stepper->step(deltaStep);
}



/**
 * Takes the given step count, and limits the range the servo can move to.
 * 
 * @param deltaStep takes a reference to the change in steps, and caps it to prevent overturning.
 */
void MyStepper::limitStep(int& deltaStep) {
  if (currentStep + deltaStep > maxSteps) {
    deltaStep = maxSteps - currentStep;
  }
  else if (currentStep + deltaStep < minSteps) {
    deltaStep = minSteps - currentStep;
  }
}

/**
 * Converts the given angle to the right amount of steps.
 * 
 * @param angle The angle to convert
 * @return Step count
 */
int angleToSteps(double angle) {
  return (int)((angle / 360) * steps_per_revolution);
}

/**
 * Rotates the stepper to its home location.
 */
void rotateToHome() {
  rotateTo_step(0);
}

/**
 * Steps the stepper once towards its home location.
 */
void stepToHome() {
  stepTo_step(0);
}