# Arduino Radar System

## Overview
This project is a real-time radar visualization system built using Arduino, HC-SR04 ultrasonic sensor, servo motor, and Processing IDE.

The radar scans the surroundings and displays detected objects graphically on a radar-style interface. The project also includes serial data logging support for recording radar measurements.

---

## Features
- Real-time object detection
- Radar sweep visualization
- Distance and angle tracking
- Serial communication between Arduino and Processing
- Data logging support
- Interactive radar interface

---

## Components Used
- Arduino UNO
- HC-SR04 Ultrasonic Sensor
- Servo Motor
- Jumper Wires

---

## Software Used
- Arduino IDE
- Processing IDE

---

## Working Principle
The ultrasonic sensor is mounted on a servo motor which rotates from 0° to 180°.

Distance data is collected and transmitted serially to Processing IDE, where the radar interface visualizes object positions in real time.

The measured radar data can also be logged for further analysis.

---

## Project Files
- `Radar.ino` → Arduino source code
- `Radar_Logic.pde` → Processing visualization code
- Hardware setup images
- Radar interface screenshots

---

## Future Improvements
- Object tracking
- Wireless communication
- Improved radar graphics
- Extended sensing range
- Multiple sensor integration
