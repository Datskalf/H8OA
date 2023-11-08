# H8OA
## About
H8OA is the temporary name given to an octopod made by Harry Bowker (hab75) and Sondre Mathias Meiland-Flakstad (som38)

The goal of the robot is to practice:
- Working as a group
- Communication of data between platforms
- Realistic-looking motion of a robot



## Communication protocols
### HTTP
HTTP communication is utilized as a bridge between the controller and the
Raspberry PI. A JSON object is passed along a POST request to signify the
current state of the remote, whereafter the RPi determines the state the
Octopod should assume. The JSON format is outlined below.

```
{
  "dPadUp": false,
  "dPadDown": false,
  "dPadLeft": false,
  "dPadRight": false,

  "btnA": false,
  "btnB": false,
  "btnX": false,
  "btnY": false,

  "btnL1": false,
  "btnL2": false,
  "btnL3": false,
  "btnL4": false,
  "btnL5": false,

  "btnR1": false,
  "btnR2": false,
  "btnR3": false,
  "btnR4": false,
  "btnR5": false,
  
  "joyL": {
    "x": 0,
    "y": 0
  },

  "joyR": {
    "x": 0,
    "y": 0
  },

  "gyro": {
    "x": 0,
    "y": 0
  }
}
```

### Serial
Serial communication is utilized in between the Raspberry PI and and Arduino.
The communication over this bridge is formatted as state IDs, where one ID
maps to one state. These states are outlined below.

- 0xx: single action
  - 000: No state change, maintain current state on board.
- 1xx: permanent state change
  - 100: Idle
  - 101: Move forwards
  - 102: Move backwards
  - 111: Rotating clockwise
  - 112: Rotating counter clockwise




## Controllers
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