/**
 * Stepper motor test
 * 
 * @author Sondre Meiland-Flakstad
 * @date 2024-02-14
 */

#include "MotorControl.h"

MotorControl controller(A0, A2, A1, A3, 2, 4, 3, 5, 7, 9, 8, 10);

void setup() {
  // Test code
  controller.rotate_angle(0, 90);
  controller.rotate(1, 1024);

  controller.rotate_all_angles(0, -45, -45);
}

void loop() {

}
