#ifndef CENTRAL_CONTROLLER_SERIAL_COMMS_H
#define CENTRAL_CONTROLLER_SERIAL_COMMS_H


void send_to_all(char* msg);
void send_to_all(int msg);

void send_to_leg(char* msg, int legID);
void send_to_leg(int msg, int legID);

#endif