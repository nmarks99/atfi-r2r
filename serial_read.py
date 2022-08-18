#!/usr/bin/env python

import serial
import os
s = serial.Serial(baudrate=38400,port="COM7")


try:
    while True:
        line = s.readline(16)
        val = line.decode("utf-8")
        os.system("clear")
        print(val)

except KeyboardInterrupt:
    print("Stopped by user!")
