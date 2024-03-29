/**
 * A library which controls all servos on a specific leg of the H8OA spider bot
 * 
 * @author Sondre Meiland-Flakstad
 * @version 1.2 2024-03-10
 */

#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include <Stepper.h>
#include "MyStepper.h"

/**
 * 
 */
class MotorControl {
  public:
    const static int steps_per_revolution = 2048;

    MotorControl(
      int stepper1_pin1, int stepper1_pin2, int stepper1_pin3, int stepper1_pin4,
      int stepper2_pin1, int stepper2_pin2, int stepper2_pin3, int stepper2_pin4,
      int stepper3_pin1, int stepper3_pin2, int stepper3_pin3, int stepper3_pin4);

    void rotate(unsigned int stepperIndex, int steps);
    void rotate_angle(unsigned int stepperIndex, double angle);
    void rotate_all(int stepper1_steps, int stepper2_steps, int stepper3_steps);
    void rotate_all_angles(double stepper1_angle, double stepper2_angle, double stepper3_angle);

    void setLimits(unsigned int stepperIndex, double minAngle, double maxAngle);
    int angle_to_steps(double angle);

    void setStepperInterval(unsigned int stepperIndex, unsigned int ticksPerStep);

  private:
    MyStepper* steppers[3];
};

#endif