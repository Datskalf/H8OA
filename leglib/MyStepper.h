/**
 * Header file containing a class definition for a custom stepper container.
 * 
 * @author Sondre Meiland-Flakstad
 * @date 2024-02-20
 * @version 0.2 2024-02-21
 */

#ifndef MY_STEPPER_H
#define MY_STEPPER_H

#include <Stepper.h>

/**
 * A container class for a custom Stepper object.
 * Lets the user rotate to a position, and rotate by a specific amount, both locking and non-locking.
 * 
 * 
 */
class MyStepper {
  public:
    MyStepper(int pin1, int pin2, int pin3, int pin4);
    void setLimits(int minStep, int maxStep);
    void setHome();

    void rotateBy_angle(double angle);
    void rotateBy_step(int step);
    void rotateTo_angle(double angle);
    void rotateTo_step(int step);
    void stepTo_angle(double angle);
    void stepTo_step(int step);

    void limitStep(int& deltaStep);

    void rotateToHome();
    void stepToHome();
    void setSpeed(long speed);

  private:
    const static int default_speed = 15;
    const static int steps_per_revolution = 2048;

    Stepper* _stepper;
    int currentStep;
    int maxSteps;
    int minSteps;

    int angleToSteps(double angle);
};

#endif