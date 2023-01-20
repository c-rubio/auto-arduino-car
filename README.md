# THE "OAAC" (Object Avoiding Arduino Car)

<div align = "center">
<img src="https://user-images.githubusercontent.com/98237169/213582819-fb77ec5a-f1be-4fac-a9b3-84206c241eb0.gif" width=80%>
</div>
<br />

The **"OAAC"** is a modest, ultrasonic sensor based object avoiding car. It functions as front wheel drive, with two servo-motorized front wheels and two rear balance wheels. The rear wheels are not necessary, but help with durability of the 3D-printed base and reducing friction. I personally used lego wheels, but YMMV. It can not do complex functions such as lane detection, but these functions could be implemented at a later date with the correct hardware modules.

<br />
</div>

## Requirements
- Arduino IDE
- Microcontroller board compatible with Arduino IDE and Servo.h module
  - Code has been tested and is compatible with Arduino Zero and Arduino Uno
- Two continuous servo motors
- One 180° limited servo motor
- Breadboard
- Two servo motor compatible wheels
- Base to hold breadboard and compatible microcontroller

#### For wireless use:
  - Battery with barrel jack adapter

## Features
- "Smart Direction" decision making
- Distance pinging using HC-SR04
- Driver board *not* required

#### Decision Making Structure
```python
ASSUME: diff = distance left of car - distance right of car.
        note: "distance" refers to the distance of the closest object detected by HC-SR04 sensor.

Object Detected Ahead!
  ↓
  Stop.
  ↓
  Look Left and Look Right.
  ├── if distance ahead < absolute value of diff:
  │   └── Move Backward.
  │
  ├── if absolute value of diff < 5 cm:
  │   └── Move Backward.
  │
  ├── if diff < 0:
  │   ├── Move Backward
  │   │   └── Move Right.
  │   else:
  │   └── Move Backward
  │       └── Move Left.
  ↓
Continue Main Loop.
```
