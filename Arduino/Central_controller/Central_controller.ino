/*
 * This code works as the central controller for the H8OA robot.
 * 
 * The code receives the robot state, and tells each 
 * leg controller what to do.
 * 
 * Created by Sondre Meiland-Flakstad
 * Date: 2023-10-11
 * Last modified by Sondre Meiland-Flakstad
 * Date: 2023-11-08
 */

#include <SoftwareSerial.h>

#define LEG_COUNT 8
#define LED_DELAY 100

#define RPI_RX 0
#define RPI_TX 1
#define LEG1_RX 2
#define LEG1_TX 3
#define LEG2_RX 4
#define LEG2_TX 5
#define LEG3_RX 6
#define LEG3_TX 7
#define LEG4_RX 8
#define LEG4_TX 9
#define LEG5_RX 10
#define LEG5_TX 11
#define LEG6_RX 12
#define LEG6_TX 13
#define LEG7_RX 14
#define LEG7_TX 15
#define LEG8_RX 16
#define LEG8_TX 17
#define PULSE 18

//SoftwareSerial[] legs {
//  SoftwareSerial(LEG1_RX, LEG1_TX);
//  SoftwareSerial(LEG2_RX, LEG2_TX);
//  SoftwareSerial(LEG3_RX, LEG3_TX);
//  SoftwareSerial(LEG4_RX, LEG4_TX);
//  SoftwareSerial(LEG5_RX, LEG5_TX);
//  SoftwareSerial(LEG6_RX, LEG6_TX);
//  SoftwareSerial(LEG7_RX, LEG7_TX);
//  SoftwareSerial(LEG8_RX, LEG8_TX);
//};


void blinkLED(int count) {
  for (; count > 0; count--) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(LED_DELAY);
    digitalWrite(LED_BUILTIN, LOW);
    delay(LED_DELAY);
  }
}


void setup() {
  Serial.begin(9600);
  Serial.setTimeout(100);
  pinMode(LED_BUILTIN, OUTPUT);
  return;
}

void loop() {
  String readCmd = Serial.readStringUntil(' ');
  if (readCmd.length() > 0) {
    float readVal = Serial.parseFloat();

    //Serial.print(readCmd);
    //Serial.print("\t");
    //Serial.println(readVal);


    //if (readCmd == "led") {
    //  digitalWrite(LED_BUILTIN, HIGH);
    //  delay((int)readVal);
    //  digitalWrite(LED_BUILTIN, LOW);
    //}

    if (readCmd == "dPad") {
      blinkLED(1);
    } else if (readCmd == "btn") {
      blinkLED(2);
    } else if (readCmd == "shoulderBtn") {
      blinkLED(4);
    } else if (readCmd == "joystick") {
      blinkLED(8);
    } else if (readCmd == "gyro") {
      blinkLED(16);
    }
    delay(500);
  }
}