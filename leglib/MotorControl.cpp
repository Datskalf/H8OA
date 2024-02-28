/**
 * A library which controls all servos on a specific leg of the H8OA spider bot
 * 
 * @author Sondre Meiland-Flakstad
 * @version 1.0 2024-02-15
 * @date 2024-02-14
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
                            int stepper1_pin1, int stepper1_pin2, int stepper1_pin3, int stepper1_pin4,
                            int stepper1_pin1, int stepper1_pin2, int stepper1_pin3, int stepper1_pin4) {
    
  steppers[0] = MyStepper(stepper1_pin1, stepper1_pin2, stepper1_pin3, stepper1_pin4);
  steppers[0].setLimits(-45, 45);

  steppers[1] = MyStepper(stepper2_pin1, stepper2_pin2, stepper2_pin3, stepper2_pin4);
  steppers[1].setLimits(-45, 45);

  steppers[2] = MyStepper(stepper3_pin1, stepper3_pin2, stepper3_pin3, stepper3_pin4);
  steppers[2].setLimits(-90, 90);
  
}

/**
 * Sets the stepper limit for a given stepper.
 * 
 * 
 * @param stepperIndex  The index of what stepper to set limits of [0-2]
 * @param minAngle      Minimum angle of the stepper
 * @param maxAngle      Maximum angle of the stepper
 */
void setLimits(int stepperIndex, double minAngle, double maxAngle) {
  if (stepperIndex < 0 || stepperIndex > 2) return;

  double angle1 = minAngle < maxAngle ? minAngle : maxAngle;
  double angle2 = maxAngle > minAngle ? maxAngle : minAngle;

  steppers[stepperIndex].setLimits(angle1, angle2);
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
 * @param stepper_select An index [0-2] defining which stepper to rotate
 * @param steps How many steps to rotate the stepper by
 */
void MotorControl::rotate(int stepper_select, int steps) {
  if (stepper_select < 0 || stepper_select > 2) return;

  this->steppers[stepper_select].step(steps);
}

/**
 * Rotates the given stepper by a certain angle
 * 
 * @param stepper_select An index [0-2] defining which stepper to rotate
 * @param angle What angle to rotate the stepper by
 */
void MotorControl::rotate_angle(int stepper_select, double angle) {
  rotate_steps(stepper_select, angle_to_steps(angle));
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
      this->steppers[0].step(1);
      stepper1_steps--;
    }
    else if (stepper1_steps < 0) {
      this->steppers[0].step(-1);
      stepper1_steps++;
    }

    if (stepper2_steps > 0) {
      this->steppers[1].step(1);
      stepper2_steps--;
    }
    else if (stepper2_steps < 0) {
      this->steppers[1].step(-1);
      stepper2_steps++;
    }

    if (stepper3_steps > 0) {
      this->steppers[2].step(1);
      stepper3_steps--;
    }
    else if (stepper3_steps < 0) {
      this->steppers[2].step(-1);
      stepper3_steps++;
    }
  }
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
void rotate_all_angles(double stepper1_angle, double stepper2_angle, double stepper3_angle) {
  this->rotate_all_steps( this->angle_to_steps(stepper1_angle),
                          this->angle_to_steps(stepper2_angle),
                          this->angle_to_steps(stepper3_angle));
}