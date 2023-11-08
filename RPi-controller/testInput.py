import serial

if __name__ == "__main__":
    ser = serial.Serial("COM7", 9600, timeout=1)
    ser.reset_input_buffer()

    

    while True:
        data = input()
        ser.write(bytes(data, "utf-8"))
        