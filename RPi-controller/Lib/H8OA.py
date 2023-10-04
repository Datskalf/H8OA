"""
Container document for the Unnamed Octopod Controller.\n
"""

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
        self.serial = serial.Serial("/dev/ttyACMO", 9600, timeout=1)
        self.serial.reset_input_buffer()
        self.serial.reset_output_buffer()
        self.loop = asyncio.new_event_loop()

    async def _send_state_to_serial(self, state: str) -> None:
        """
        Takes a state string, and sends it over the serial connection.
        """
        while self.serial.out_waiting():
            await asyncio.sleep(0.5)
        self.serial.write(state.encode("ascii"))

    def handle_command(self, state: json) -> None:
        """
        Converts the button states from the controls
        to robot state to be sent to the robot.
        """
        print(state)
        self.loop.create_task(self._send_state_to_serial(state))