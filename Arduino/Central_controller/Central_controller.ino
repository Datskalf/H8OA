#include <SoftwareSerial.h>
#include "serial_comms.h"

#define LEG_COUNT 8

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

SoftwareSerial[] legs {
  SoftwareSerial(LEG1_RX, LEG1_TX);
  SoftwareSerial(LEG2_RX, LEG2_TX);
  SoftwareSerial(LEG3_RX, LEG3_TX);
  SoftwareSerial(LEG4_RX, LEG4_TX);
  SoftwareSerial(LEG5_RX, LEG5_TX);
  SoftwareSerial(LEG6_RX, LEG6_TX);
  SoftwareSerial(LEG7_RX, LEG7_TX);
  SoftwareSerial(LEG8_RX, LEG8_TX);
};



void setup() {
  pinMode(PULSE, OUTPUT);

  for (int i = 0; i < LEG_COUNT; i++) {
    legs[i].begin(9600);
  }

  char* message;
  "Test".toCharArray(message, 5);
  send_to_all(message);
}

void loop() {

}