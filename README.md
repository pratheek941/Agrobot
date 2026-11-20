::: {align="center"}
# 🌱 Agrobot

### Hand Gesture Controlled Smart Agricultural Robot

**Computer Vision • ESP32 • Wireless Robotics • Matrix-Based Field
Navigation**
:::

------------------------------------------------------------------------

## 📖 About the Project

Agrobot is a prototype smart agricultural robot that combines computer
vision, hand-gesture recognition, wireless communication, and a
matrix-based movement concept.

A laptop webcam captures the user's hand gestures. Python, OpenCV, and
MediaPipe recognize the gestures and send movement commands over Wi-Fi
to an ESP32 microcontroller. The ESP32 controls two DC geared motors
through an L298N motor driver.

The project also explores a **row-and-column (matrix) movement system**.
An agricultural field can be represented as a two-dimensional grid,
helping plan systematic movement between crop rows and plant locations.
In the current prototype, movement is controlled by hand gestures;
coordinate-based and autonomous grid navigation are future development
goals.

## 🖼️ Hardware Components

> The images below are representative examples of the components. Your
> exact board or module may look slightly different.

### 1. ESP32 Dev Module

![ESP32-WROOM-32 development
board](https://www.flyrobo.in/image/cache/wp/gj/4600/nodemcu-38-pin-esp32-development-board-with-esp-32e-490-pasted-550x550.webp)

The ESP32 receives movement commands from the laptop over Wi-Fi and
controls the motor driver.

### 2. L298N Dual H-Bridge Motor Driver

![L298N motor driver
module](https://m.media-amazon.com/images/I/61VkNn0PcaL.jpg)

The L298N acts as the interface between the ESP32 control signals and
the two DC motors.

### 3. TT DC Geared Motors

![Yellow TT DC geared
motor](https://m.media-amazon.com/images/I/514kMhQsd7S._AC_UF1000,1000_QL80_.jpg)

Two TT geared motors provide the robot's movement.

### 4. AA Battery Holder

![AA battery
holder](https://robu-prod-media.s3.ap-south-1.amazonaws.com/uploads/2017/06/4-aa-battery-holder-box1-1.jpg)

The battery holder supplies power to the robot's motor system. Use a
power arrangement suitable for the exact motors and driver module.

## 🧰 Hardware Used

-   ESP32 Dev Module
-   L298N dual H-bridge motor driver
-   2 × TT DC geared motors
-   4 × AA batteries with battery holder
-   Robot chassis and wheels
-   Jumper wires
-   Laptop with webcam

## 💻 Software and Technologies

  Technology    Purpose
  ------------- ----------------------------------------------
  Python        Gesture recognition and command transmission
  OpenCV        Webcam capture and image processing
  MediaPipe     Hand landmark detection
  Requests      HTTP communication with the ESP32
  Arduino IDE   ESP32 firmware development
  C++           ESP32 motor-control program
  Wi-Fi         Laptop-to-robot communication

## ✋ Gesture Controls

  Hand gesture         Robot command
  -------------------- ---------------
  👍 Thumbs up         Forward
  👎 Thumbs down       Backward
  ✌️ Peace sign        Left
  ☝️ Index finger up   Right
  🖐️ Open palm         Stop

## ⚙️ How It Works

1.  The laptop webcam captures the user's hand.
2.  MediaPipe detects hand landmarks in the camera frame.
3.  The Python program identifies the gesture.
4.  Python sends the corresponding command to the ESP32 over Wi-Fi.
5.  The ESP32 receives the command and controls the L298N.
6.  The motor driver operates the two motors to move the robot.

## 🗺️ Matrix-Based Movement Concept

The field can be modelled as a two-dimensional grid:

-   **Rows:** represent crop rows or horizontal travel paths.
-   **Columns:** represent positions across the field.
-   **Grid coordinates:** identify planned plant locations or navigation
    points.

This approach is intended to support organized field coverage and future
features such as plant inspection, crop monitoring, and precision
irrigation. Autonomous coordinate navigation is not yet implemented in
the current gesture-controlled prototype.

## 🚀 Getting Started

### 1. Install Python packages

``` bash
py -m pip install opencv-python mediapipe requests
```

### 2. Arrange the project files

``` text
Agrobot/
├── main.py
├── gesture_control.py
├── hand_landmarker.task
├── agrobot.ino
└── README.md
```

### 3. Upload the ESP32 firmware

1.  Open `agrobot.ino` in Arduino IDE.
2.  Enter your Wi-Fi network name and password in the sketch.
3.  Select the correct ESP32 board and COM port.
4.  Verify and upload the firmware.
5.  Open Serial Monitor at **115200 baud** and note the ESP32 IP
    address.

### 4. Configure and run the Python program

Set the ESP32 IP address in `main.py`, then run:

``` bash
py main.py
```

Press **Q** to close the webcam window.

## 🔮 Future Improvements

-   Coordinate-based matrix navigation
-   Autonomous movement along crop rows
-   Obstacle detection and avoidance
-   Soil-moisture monitoring
-   Smart irrigation
-   Plant health and crop monitoring
-   GPS-assisted field navigation
-   AI-based agricultural analysis

## ⚠️ Safety

-   Check the motor driver, battery, ground, and logic-power connections
    before powering the motors.
-   Keep wheels clear of the floor during initial movement tests.
-   Disconnect power if any component or wire becomes unusually hot.
-   Do not connect the battery directly to the ESP32 5V or 3.3V pin.

## 🎯 Project Goal

Agrobot explores how computer vision, embedded systems, and robotics can
be combined to support more systematic agricultural operations. The
prototype provides a foundation for future smart-farming and
precision-agriculture applications.

## 🖼️ Image Credits

The component photographs are sourced from Wikimedia Commons:

-   [ESP32-WROOM-32
    board](https://commons.wikimedia.org/wiki/File:ESP32_DevKitC_V4.jpg)
    --- CC0.
-   [L298N motor
    driver](https://commons.wikimedia.org/wiki/File:M%C3%B3dulo_Driver_de_Motor_Ponte_H_L298N_(Vista_Superior).png)
    --- CC0.
-   [Yellow TT geared
    motor](https://commons.wikimedia.org/wiki/File:Motor_DC_Amarelo_com_Caixa_de_Redu%C3%A7%C3%A3o_(Vista_Frontal-Lateral).png)
    --- see the file page for its license.
-   [AA battery
    holder](https://commons.wikimedia.org/wiki/File:AAbatteryholder.jpg)
    --- CC BY-SA 3.0 / GFDL.

------------------------------------------------------------------------

::: {align="center"}
**Agrobot --- Smart Farming Begins with a Gesture 🌱**
:::
