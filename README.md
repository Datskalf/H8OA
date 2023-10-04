# H8OA
### About
H8OA is the temporary name given to an octopod made by Harry Bowker (hab75) and
Sondre Mathias Meiland-Flakstad (som38)

The goal of the robot is to practice:
- Working as a group
- Communication of data between platforms
- Realistic-looking motion of a robot



### Raspberry PI Controller
The Raspberry PI is responsible for:
- Receiving the button state of the controller whenever there is an update.
  - Converting said state into a serial-transferable format
  - Sending said signal over serial to the Arduino
- Providing a demo controller



### Arduino Controller
The Arduino is responsible for:
- Receiving the robot state from serial
- Setting the state of the robot