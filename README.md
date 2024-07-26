# Arduino-NFC-Servo
This project uses an Arduino to interface with an NFC reader and a servo motor. The setup allows for controlling the servo based on NFC card authentication and a physical button press.

Description: 
This Arduino project integrates an NFC reader, a servo motor, and LEDs to create a simple access control system. The system operates as follows:

When a specific NFC card is detected, the servo motor turns to 90 degrees, a green LED turns on, and a red LED turns off.
If a physical button is pressed, the servo motor turns to -90 degrees (or 270 degrees if the servo does not support negative values), the red LED turns on, and the green LED turns off.
Components Used
Arduino Board (e.g., Arduino Uno)
MFRC522 NFC Reader Module
Servo Motor
Green LED
Red LED
Push Button
Resistors (220Ω for LEDs, 10kΩ for button pull-up)
Breadboard and Jumper Wires

Libraries Used
MFRC522: For interfacing with the NFC reader. MFRC522 GitHub
Servo: For controlling the servo motor. Servo GitHub

Components and Pin Connections
1. Arduino Board (e.g., Arduino Uno)
2. MFRC522 NFC Reader Module
SDA (SS) → Pin 10 on Arduino
SCK → Pin 13 on Arduino
MOSI → Pin 11 on Arduino
MISO → Pin 12 on Arduino
IRQ → Not connected
GND → GND on Arduino
RST → Pin 9 on Arduino
3.3V → 3.3V on Arduino (or use a 3.3V power supply if required)
3. Servo Motor
Signal (Control) → Pin 6 on Arduino
Power (VCC) → 5V on Arduino (or external 5V power supply if needed)
Ground (GND) → GND on Arduino (or external GND)
4. Green LED
Anode (Long leg) → Pin 3 on Arduino (through a 220Ω resistor)
Cathode (Short leg) → GND on Arduino
5. Red LED
Anode (Long leg) → Pin 4 on Arduino (through a 220Ω resistor)
Cathode (Short leg) → GND on Arduino
6. Push Button
One leg → Pin 5 on Arduino
Other leg → GND on Arduino (with a pull-up resistor)

How to Use
Hardware Setup: Connect the components as per the circuit diagram.
Upload Code: Upload the provided Arduino code to your Arduino board using the Arduino IDE.
Power On: Power on your Arduino setup.
Test: Present an authorized NFC card to the reader. The servo should turn to 90 degrees, the green LED should turn on, and the red LED should turn off. Press the button to turn the servo back to its initial position and switch the LED states.
Troubleshooting
Ensure all connections are secure and correct.
Verify that the NFC card’s UID matches the authorizedUID in the code.
If the servo does not move as expected, check its power supply and range settings.
License
This project is licensed under the MIT License. See the LICENSE file for more details.

Tips
Resistors: Always use a resistor (220Ω) with LEDs to limit the current and prevent damage.
Power Supply: Ensure that the servo and NFC reader receive the correct voltage. Some servos might require an external power supply if they draw more current than the Arduino can provide.
Pull-up Resistor: The push button setup uses the Arduino's internal pull-up resistor. Ensure that INPUT_PULLUP is used in your code.

Contact
For any questions or feedback, please contact v.zannettou@outlook.com.
