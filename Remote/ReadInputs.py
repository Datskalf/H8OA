import signal
from xbox360controller import Xbox360Controller

Xbox360Controller.get_available()

def on_button_pressed(button):
    print(f"Button {button} was pressed")

def on_button_released(button):
    print(f"Button {button} was released")

def on_axis_moved(axis):
    print(f"Axis {axis.name} moved to ({axis.x}, {axis.y})")

try:
    with Xbox360Controller(0, axis_threshold=0.2) as controller:
        controller.button_a.when_pressed = on_button_pressed
        controller.button_b.when_pressed = on_button_pressed
        controller.button_x.when_pressed = on_button_pressed
        controller.button_y.when_pressed = on_button_pressed
        
        controller.axis_l.when_moved = on_axis_moved
        controller.axis_r.when_moved = on_axis_moved

        signal.pause()
except KeyboardInterrupt:
    pass