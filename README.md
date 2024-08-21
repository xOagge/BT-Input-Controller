# Bluetooth Command Controller

This project enables Bluetooth-controlled keyboard simulation using an Arduino and Python. The Arduino sends commands to a Python script over Bluetooth, which then simulates key presses and releases on a connected computer.

## Components Required

- Arduino Due (or similar)
- Bluetooth module (e.g., HC-05, HC-06)
- Connecting wires and breadboard

## Code Overview

### Arduino Code

- **Serial Communication:** Configures Bluetooth communication to receive commands.
- **Commands:**
  - **Movement:** `w`, `a`, `s`, `d`
  - **Actions:** `i`, `j`, `k`, `l`
  - **Activity Control:** `+` (start), `-` (stop)
- **Functionality:** Processes received commands to toggle internal states and print status.

### Python Script

- **Serial Communication:** Listens to commands from the Arduino over the serial port.
- **Functionality:** Simulates key presses and releases based on the received commands using the `keyboard` library.

## Setup

1. **Upload Arduino Code:** Use the Arduino IDE to upload the provided code to your Arduino board.
2. **Run Python Script:** Execute the Python script on your computer.
3. **Pair Bluetooth Module:** Ensure the Bluetooth module is paired with your computer.
4. **Configure Serial Port:** Update `SERIAL_PORT` in the Python script to match your Bluetooth serial port.

## Commands

- **Movement Commands:** `w`, `a`, `s`, `d`
- **Action Commands:** `i`, `j`, `k`, `l`
- **Activity Control:** `+` to start Python script, `-` to stop Python script

## Usage

1. **Initialize Components:** Connect the Arduino and Bluetooth module.
2. **Send Commands:** Use a Bluetooth-enabled device to send commands to the Arduino.
3. **Monitor Output:** Check the Python script for key simulation based on Arduino commands.

## Troubleshooting

- **No Key Presses:** Ensure the Bluetooth module is properly paired and the correct serial port is configured.
- **Invalid Commands:** Verify commands sent from the Bluetooth device match the expected format.

## License

This project is open-source and licensed under the [MIT License](https://opensource.org/licenses/MIT).
