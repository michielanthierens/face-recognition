#!/usr/bin/env python

# <keyword data-keyword-id="246">Raspberry Pi</keyword> to Arduino I2C Communication
# Python Code
 
import smbus
from time import sleep

I2Cbus = None

# This function converts a string to an array of bytes.
def ConvertStringToBytes(src):
    converted = []
    for b in src:
        converted.append(ord(b))
    
    return converted
 
# Slave Addresses for Arduinos
ARDUINO_ADDRESS = 0x04 # I2C Address of Arduino 1

def init():
    # Create the I2C bus
    global I2Cbus
    I2Cbus = smbus.SMBus(1)

def sendToArduino(name):
    global I2Cbus
    SlaveAddress = ARDUINO_ADDRESS
    name_to_show = 'Welkom ' + name
    BytesToSend = ConvertStringToBytes(name_to_show)
    I2Cbus.write_i2c_block_data(SlaveAddress, 0x00, BytesToSend)
