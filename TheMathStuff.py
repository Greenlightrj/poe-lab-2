import serial
import datetime
#import matplotlib.pyplot as plt
#from mpl_toolkits.mplot3d import Axes3D
from math import sin, cos
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

for i in range(0, 6):
    # serial input in form 'b'R, phi, theta\r\n'
    inp = ser.readline()
    Ds = int(inp)
    print(Ds)
    # unpack inp into angles and distance
    theta = 0
    phi = 0
    #Ds = 0
    # measurements are in centimeters
    eyepos = (8.5 * sin(theta), 8.5 * cos(theta) - 5.8, 8.5)

    # diagonal in the horizontal plane
    Da = Ds * cos(phi)
    # positions relative to eye
    Dx = Da * cos(theta)
    Dy = Da * sin(theta)
    Dz = Ds * sin(phi)

    # positions relative to origin
    x.append(eyepos[0] + Dx)
    y.append(eyepos[1] + Dy)
    z.append(eyepos[2] + Dz)

with open('positions.txt', 'w') as f:
    f.write('Scan at ' + starttime.strftime("%Y-%m-%d %H:%M") + "\n")
    for i in range(0, len(x)):
        f.write(str(x[i]) + ', ' + str(y[i]) + ', ' + str(z[i]) + "\n")


# for later plotting maybe
"""
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
Axes3D.scatter(x, y, z)
"""



