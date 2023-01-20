# Object Avoiding Arduino Car

<div align = "center">
<img src="https://user-images.githubusercontent.com/98237169/213582819-fb77ec5a-f1be-4fac-a9b3-84206c241eb0.gif" width=80%>
<br />
early revision demo of car
</div>

## Requirements
- Arduino IDE
- Microcontroller board compatible with Arduino IDE and Servo.h module
  - Code has been tested and is compatible with Arduino Zero and Arduino Uno
- Two continuous servo motors
- One 180° limited servo motor
- Breadboard
- Two servo motor compatible wheels

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
