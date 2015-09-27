import serial
import datetime
from math import sin, cos, log, pi
# read serial from Rebecca's computer
ser = serial.Serial('COM6', 9600)
# read serial from Jayce's computer
# ???

# initialize x, y, and z as lists
x = []
y = []
z = []

# get start time for documentation purposes
starttime = datetime.datetime.now()

"""
test code
x = [1, 2, 3, 4, 5, 6]
y = [1, 4, 9, 16, 25, 36]
z = [2, 4, 6, 8, 10, 12]
"""
print ("scanning...")

for i in range(0, 300):
    # serial input in form 'b'R, phi, theta\r\n'
    inp = ser.readline()[:-2]
    #print(inp)
    D = inp.decode("utf-8")
    #print(D)
    Di = D.split(',')
    print(Di)
    Dr = int(Di[-3])
    #print('Dr: ' + str(Dr))
    # unpack inp into angles and distance
    phi = (int(Di[-2]) - 75)* pi/180 - 75
    theta = (int(Di[-1]) -75)* pi/180 -75

    if Dr > 100:
        Ds = -28.0*log((Dr - 100)/810.0)
    else:
        # prevent errors by not trying to take the log of negative numbers
        Ds = 0
    #print('Ds: ' + str(Ds))
    # measurements are in centimeters
    eyepos = (8.5 * cos(theta), -8.5 * sin(theta) - 5.8, 8.5)
    #print(eyepos)
    # diagonal in the horizontal plane
    Da = Ds * cos(phi)
    #    print(Da)
    # positions relative to eye
    Dx = Da * sin(theta)
    Dy = Da * cos(theta)
    Dz = Ds * sin(phi)
    #print('Dy: ' + str(Dy))
    # positions relative to origin
    x.append(eyepos[0] + Dx)
    y.append(eyepos[1] + Dy)
    z.append(eyepos[2] + Dz)

with open('positions.txt', 'w') as f:
    #f.write('Scan at ' + starttime.strftime("%Y-%m-%d %H:%M") + "\n")
    for i in range(0, len(x)):
        f.write(str(x[i]) + ', ' + str(y[i]) + ', ' + str(z[i]) + "\n")
print("done!")

# for later plotting maybe
"""
# #import matplotlib.pyplot as plt
# #from mpl_toolkits.mplot3d import Axes3D
# fig = plt.figure()
# ax = fig.add_subplot(111, projection='3d')
# Axes3D.scatter(x, y, z)
"""
