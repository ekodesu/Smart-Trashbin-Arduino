**Smart Trashbin Arduino Project**
 
** Project Overview**

The Smart Trashbin Arduino Project is an automated waste disposal system designed to promote hygiene and convenience. The trash bin automatically opens its lid when a hand or object is detected nearby using an ultrasonic sensor. The system is controlled by an Arduino microcontroller and a servo motor.

This project helps reduce physical contact with trash bins, minimizing the spread of germs and encouraging proper waste disposal.

 **Objectives**

Create a touchless trash bin using Arduino.
Detect objects using an ultrasonic sensor.
Automatically open and close the lid using a servo motor.
Improve hygiene and convenience in waste disposal.
 
** Components**

•Arduino Uno
•Ultrasonic Sensor (HC-SR04)
•Servo Motor (SG90)
•Jumper Wires (Male-to-Male)
•Breadboard
•USB Cable
•Trash Bin Structure

** Circuit Connections**

Ultrasonic Sensor (HC-SR04)
VCC → 5V (Arduino)
GND → GND (Arduino)
Trig → Pin 9
Echo → Pin 10
Servo Motor
Red Wire (VCC) → 5V
Brown/Black Wire (GND) → GND
Orange/Yellow Wire (Signal) → Pin 6

**How to Run the Project**

Connect the Arduino board to your computer using a USB cable.
Open the SmartTrashbin.ino file in Arduino IDE.
Select the correct Board and Port from the Tools menu.
Click Upload to upload the code to the Arduino board.
Place your hand in front of the ultrasonic sensor.
The lid will automatically open and close after a few seconds.

**Features Implemented**

Distance detection using ultrasonic sensor
Automatic lid opening when object is detected
Automatic lid closing after delay
Adjustable distance threshold in code
Basic troubleshooting and wiring improvements

** Challenges Encountered**

Inconsistent ultrasonic sensor readings
Servo motor jittering
Loose M-to-M jumper wire connections
Solutions included stabilizing sensor readings in code, checking power supply, and securing jumper wire connections properly.

** Future Improvements**

Add LCD display for status messages
Add buzzer sound when lid opens
Add trash level detection sensor
Improve physical casing and wiring organization
Optimize and clean up code

**Project Files**

Smart-Trashbin-Arduino/
── README.md
── SmartTrashbin.ino
── circuit_diagram.png
── documentation.pdf

**Final project version**
- Cleaned up and commented code
- Verified full system functionality
- Prepared repository for submission

**Group Members:**
Janrey E. Guco
Hanz Mathew W. Manaiz
Kyle Valmorida 
Lemjohn Edelion
Vincent Galamiton
Justine Ravida
