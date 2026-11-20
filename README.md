Agrobot -- Hand Gesture Controlled Agricultural Robot
Agrobot is a prototype agricultural robot that combines computer vision,
hand-gesture recognition, wireless communication, and a grid-based
movement concept.

A laptop webcam captures hand gestures. Python, OpenCV, and MediaPipe
identify the gestures and send movement commands over Wi-Fi to an ESP32.
The ESP32 controls two DC geared motors through an L298N motor driver.
Features
- Webcam-based hand gesture recognition
- Wireless communication between laptop and ESP32
- Forward, backward, left, right, and stop commands
- Two-motor drive system
- Planned matrix-based row-and-column navigation for systematic
  movement through crop fields
Gesture Controls
  Gesture           Command
  Thumbs up         Forward
Thumbs down       Backward
Peace sign        Left
Index finger up   Right
Open palm         Stop
Hardware
- ESP32-WROOM-32 development board
- L298N dual H-bridge motor driver
- Two TT DC geared motors
- Four-AA battery holder and batteries
- Robot chassis, wheels, and connecting wires
- Laptop with a webcam
Software and Technologies
- Python
- OpenCV
- MediaPipe
- Requests (Python HTTP library)
- Arduino IDE
- ESP32 Arduino framework (C++)
- Wi-Fi
How It Works
1. The laptop webcam captures the user's hand.
2. MediaPipe detects hand landmarks and the Python application
   identifies a gesture.
3. Python sends the corresponding command to the ESP32 over Wi-Fi.
4. The ESP32 receives the command and controls the L298N motor driver.
5. The motors move the robot in the selected direction.
Matrix-Based Movement Concept
The agricultural field can be represented as a two-dimensional grid of
rows and columns. This provides a structured way to plan movement
between crop rows and plant locations. The current prototype is
controlled by hand gestures; coordinate-based and autonomous grid
navigation are intended areas for future development.
Project Setup
1. Install Python dependencies
py -m pip install opencv-python mediapipe requests
2. Prepare the project files
Keep the Python scripts and the MediaPipe model file in the same project
folder:
Agrobot/
├── main.py
├── gesture_control.py
└── hand_landmarker.task
3. Configure the ESP32
- Open the ESP32 firmware in Arduino IDE.
- Enter the Wi-Fi network name and password in the sketch.
- Select the correct ESP32 board and COM port.
- Upload the firmware.
- Open Serial Monitor at 115200 baud and note the ESP32 IP address.
4. Configure and run the Python application
Set the ESP32 IP address in main.py, then run:
py main.py
Press Q to exit the webcam application.
Safety Notes
- Verify all motor-driver, battery, ground, and logic-power
  connections before connecting motor power.
- Keep the robot secured and its wheels clear of the floor during
  initial motor tests.
- Disconnect power immediately if the driver or wiring becomes
  unusually hot.
- Do not connect the battery directly to the ESP32 5V or 3.3V pin.
Future Improvements
- Grid-coordinate tracking and autonomous row navigation
- Obstacle detection and avoidance
- Soil-moisture monitoring and smart irrigation
- Plant and crop health monitoring
- GPS-assisted field navigation
- AI-based agricultural analysis
Project Goal
Agrobot explores how accessible robotics and computer-vision
technologies can support more systematic and precise agricultural
operations. The prototype provides a foundation for future smart-farming
features.
