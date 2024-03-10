/**
 * Stepper motor test
 * 
 * @author Sondre Meiland-Flakstad
 * @version 1.2 2024-03-10
 */

#include "MotorControl.h"

MotorControl controller(A3, A1, A2, A0, 2, 4, 3, 5, 7, 9, 8, 10);

void setup() {
  // Test code
  //controller.rotate_all_angles(0, -45, -45);
}

void loop() {
  controller.rotate_all_angles(180, 180, 90);
  delay(500);
}
