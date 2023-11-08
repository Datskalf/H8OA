import json
import asyncio

import serial


class H8OA:
    """
    This class is the main control portion for the Unnamed Octopod.\n
    The class should be instansiated once, and the resulting object
    is where the controls are interacted with.
    """

    __version__ = "0.0.1a"
    __author__ = "Sondre Flakstad [som38]"
    __credits__ = ["Harry Bowker [hab75]"]
    __status__ = "Development"
    __license__ = "MIT"

    def __init__(self):
        self.serial = serial.Serial("COM7", 9600, timeout=1)
        self.serial.reset_input_buffer()
        self.serial.reset_output_buffer()
        self.loop = asyncio.new_event_loop()

    async def send_to_serial(self, module: str, state: int) -> None:
        """
        Takes a state string, and sends it over the serial connection.
        """
        while self.serial.out_waiting():
            await asyncio.sleep(0.5)
        self.serial.write(module.encode("ascii"))
        self.serial.write(state)

    def handle_command(self, state: json) -> None:
        """
        Converts the button states from the controls
        to robot state to be sent to the robot.
        """
        print(state)

        key = state.keys()[0] if len(state.keys() > 0) else None
        module = None
        data = None

        if key in ["dPadUp", "dPadDown", "dPadLeft", "dPadRight"]:
            module = "dPad"
            data = state[key]
        elif key in ["btnA", "btnB", "btnX", "btnY"]:
            module = "btn"
            data = state[key]
        elif key in ["btnL1", "btnL2", "btnL3", "btnL4", "btnL5", "btnR1", "btnR2", "btnL3", "btnR4", "btnR5"]:
            module = "shoulderBtn"
            data = state[key]
        elif key in ["JoyL", "joyR"]:
            module = "joystick"
            data = f"x={state[key]['x']},y={state[key]['y']}"
        elif key in ["gyro"]:
            module = "gyro"
            data = f"x={state[key]['x']},y={state[key]['y']}"

        self.loop.create_task(self._send_to_serial(module, data))
