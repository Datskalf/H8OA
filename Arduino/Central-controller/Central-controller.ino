#include <SoftwareSerial.h>

#define LEG1_TX 2
#define LEG1_RX 3

#define LEG2_TX 4
#define LEG2_RX 5

#define LEG3_TX 6
#define LEG3_RX 7

#define LEG4_TX 8
#define LEG4_RX 9

#define LEG5_TX 10
#define LEG5_RX 11

#define LEG6_TX 12
#define LEG6_RX 13

#define PULSE A0


void setup() {
  pinMode(LEG1_TX, OUTPUT);
  pinMode(LEG1_RX, INPUT);

  pinMode(LEG2_TX, OUTPUT);
  pinMode(LEG2_RX, INPUT);
  
  pinMode(LEG3_TX, OUTPUT);
  pinMode(LEG3_RX, INPUT);

  pinMode(LEG4_TX, OUTPUT);
  pinMode(LEG4_RX, INPUT);

  pinMode(LEG5_TX, OUTPUT);
  pinMode(LEG5_RX, INPUT);

  pinMode(LEG6_TX, OUTPUT);
  pinMode(LEG6_RX, INPUT);

  pinMore(PULSE, OUTPUT);


  SoftwareSerial
}

void loop() {

}