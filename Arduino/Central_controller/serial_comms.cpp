/*
 * Library file for Central_controller.ino
 * 
 * Created by Sondre Meiland-Flakstad
 * Date: 2023-10-20
 * Last modified by Sondre Meiland-Flakstad
 * Date: 2023-10-20
 */

#include "serial_comms.h"

void send_to_all(char* msg) {
  for (int i = 0; i < LEG_COUNT; i++) {
    legs[i].print(msg);
  }
}

void send_to_all(int msg) {
  for (int i = 0; i < LEG_COUNT; i++) {
    legs[i].print(msg);
  }
}

void send_to_leg(char* msg, int legID) {
  legs[legID].print(msg);
}

void send_to_leg(int msg, int legID) {
  legs[legID].print(msg);
}