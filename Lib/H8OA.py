import json


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
        pass

    def handle_command(self, cmd: json) -> None:
        """
        
        """
        print(cmd)