#!/usr/bin/env python3
import serial
import os, time, sys

port = sys.argv[1].strip()
print("Listening on *", port)
arduino = serial.Serial(port=port, baudrate=9600, timeout=1)

while True:
    try:
        cur = 30 + (int(arduino.readline().decode("utf-8").strip()) * 100) / 255
        os.system("brightnessctl set " + str(cur) + "%")

        if (cur > 40):
            os.system("xwallpaper --zoom $HOME/Pictures/Wallpapers/elephant.png")
        else:
            os.system("xwallpaper --zoom $HOME/Pictures/Wallpapers/elephant-dark.png")
    except:
        pass

    time.sleep(3)
