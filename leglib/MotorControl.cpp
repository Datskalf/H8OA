/**
 * A library which controls all servos on a specific leg of the H8OA spider bot
 * 
 * 
 * @author Sondre Meiland-Flakstad
 * @version 1.2 2024-03-10
 */
 
#include "MyStepper.h"
#include "MotorControl.h"

/**
 * General constructor for a motor control object
 * 
 * @param stepper1_pin1 Pin used as the first pin to the first stepper (shoulder stepper)
 * @param stepper1_pin2 Pin used as the second pin to the first stepper (shoulder stepper)
 * @param stepper1_pin3 Pin used as the third pin to the first stepper (shoulder stepper)
 * @param stepper1_pin4 Pin used as the fourth pin to the first stepper (shoulder stepper)
 * 
 * @param stepper2_pin1 Pin used as the first pin to the second stepper (elbow stepper)
 * @param stepper2_pin2 Pin used as the second pin to the second stepper (elbow stepper)
 * @param stepper2_pin3 Pin used as the third pin to the second stepper (elbow stepper)
 * @param stepper2_pin4 Pin used as the fourth pin to the second stepper (elbow stepper)
 * 
 * @param stepper3_pin1 Pin used as the first pin to the third stepper (wrist stepper)
 * @param stepper3_pin2 Pin used as the second pin to the third stepper (wrist stepper)
 * @param stepper3_pin3 Pin used as the third pin to the third stepper (wrist stepper)
 * @param stepper3_pin4 Pin used as the fourth pin to the third stepper (wrist stepper)
 */
MotorControl::MotorControl( int stepper1_pin1, int stepper1_pin2, int stepper1_pin3, int stepper1_pin4,
                            int stepper2_pin1, int stepper2_pin2, int stepper2_pin3, int stepper2_pin4,
                            int stepper3_pin1, int stepper3_pin2, int stepper3_pin3, int stepper3_pin4) {
    
  MyStepper* s = new MyStepper(stepper1_pin1, stepper1_pin2, stepper1_pin3, stepper1_pin4);
  s->setLimits(-45, 45);
  steppers[0] = s;

  s = new MyStepper(stepper2_pin1, stepper2_pin2, stepper2_pin3, stepper2_pin4);
  s->setLimits(-45, 45);
  steppers[1] = s;
  
  s = new MyStepper(stepper3_pin1, stepper3_pin2, stepper3_pin3, stepper3_pin4);
  s->setLimits(-90, 90);
  steppers[2] = s;
  
}

/**
 * Sets the stepper limit for a given stepper.
 * 
 * 
 * @param stepperIndex  The index of what stepper to set limits of [0-2]
 * @param minAngle      Minimum angle of the stepper
 * @param maxAngle      Maximum angle of the stepper
 */
void MotorControl::setLimits(unsigned int stepperIndex, double minAngle, double maxAngle) {
  if (stepperIndex > 2) return;

  double angle1 = minAngle < maxAngle ? minAngle : maxAngle;
  double angle2 = maxAngle > minAngle ? maxAngle : minAngle;

  steppers[stepperIndex]->setLimits(angle1, angle2);
}

/**
 * Converts an angle into step count
 * 
 * @param angle the angle to convert
 * @return Corresponding amount of steps
 */
int MotorControl::angle_to_steps(double angle) {
  return (angle / 360) * this->steps_per_revolution;
}

/**
 * Rotates the given stepper by a certain amount of steps
 * 
 * @param stepperIndex An index [0-2] defining which stepper to rotate
 * @param steps How many steps to rotate the stepper by
 */
void MotorControl::rotate(unsigned int stepperIndex, int steps) {
  if (stepperIndex > 2) return;

  steppers[stepperIndex]->rotateBy_step(steps);
}

/**
 * Rotates the given stepper by a certain angle
 * 
 * @param stepperIndex An index [0-2] defining which stepper to rotate
 * @param angle What angle to rotate the stepper by
 */
void MotorControl::rotate_angle(unsigned int stepperIndex, double angle) {
  if (stepperIndex > 2) return;
  rotate(stepperIndex, angle_to_steps(angle));
}



/**
 * Rotates all steppers in the system by a set of steps.
 * Will rotate them asyncronously to each other.
 * Will not return until all steppers have completed their rotation.
 * 
 * @param stepper1_steps How many steps for stepper 1 to rotate
 * @param stepper2_steps How many steps for stepper 2 to rotate
 * @param stepper3_steps How many steps for stepper 3 to rotate
 */
void MotorControl::rotate_all(int stepper1_steps, int stepper2_steps, int stepper3_steps) {
  while (stepper1_steps || stepper2_steps || stepper3_steps) {

    if (stepper1_steps > 0) {
      this->steppers[0]->rotateBy_step(1);
      stepper1_steps--;
    }
    else if (stepper1_steps < 0) {
      this->steppers[0]->rotateBy_step(-1);
      stepper1_steps++;
    }

    if (stepper2_steps > 0) {
      this->steppers[1]->rotateBy_step(1);
      stepper2_steps--;
    }
    else if (stepper2_steps < 0) {
      this->steppers[1]->rotateBy_step(-1);
      stepper2_steps++;
    }

    if (stepper3_steps > 0) {
      this->steppers[2]->rotateBy_step(1);
      stepper3_steps--;
    }
    else if (stepper3_steps < 0) {
      this->steppers[2]->rotateBy_step(-1);
      stepper3_steps++;
    }
  }
}

/**
 * Sets how many ticks a servo needs until it moves.
 * Will reset the internal tick count on change.
 * 
 * @param stepperIndex Index of the stepper to update.
 * @param ticksPerStep How many ticks the stepper needs.
 */
void MotorControl::setStepperInterval(unsigned int stepperIndex, unsigned int ticksPerStep) {
  if (stepperIndex > 2) return;
  steppers[stepperIndex]->setInterval(ticksPerStep);
}

/**
 * Rotates all steppers in the system by a set of angles.
 * Will rotate them asyncronously to each other.
 * Will not return until all steppers have completed their rotation.
 * 
 * @param stepper1_angle What angle for stepper 1 to rotate
 * @param stepper2_angle What angle for stepper 2 to rotate
 * @param stepper3_angle What angle for stepper 3 to rotate
 */
void MotorControl::rotate_all_angles(double stepper1_angle, double stepper2_angle, double stepper3_angle) {
  rotate_all( angle_to_steps(stepper1_angle), angle_to_steps(stepper2_angle), angle_to_steps(stepper3_angle));
}