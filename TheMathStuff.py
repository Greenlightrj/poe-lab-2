import serial

ser = serial.Serial('COM6', 9600)
for i in range(1,100000000):
    print(ser.readline())
