import serial
import keyboard
import time

# Configure the serial port
SERIAL_PORT: str = 'COM3'  # Change this to your serial port
BAUD_RATE: int = 9600

def main() -> None:
    # Open serial port
    ser: serial.Serial = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)  # Set timeout to 0 for non-blocking

    # Initialize variables to store the current key and status
    key: str = None
    status: int = None

    try:
        while True:
            if ser.in_waiting > 0:
                # Read the entire line from the serial buffer
                line: str = ser.readline().decode('utf-8').strip()
                if line:
                    try:
                        # Split the received line into key and status
                        parts: list[str] = line.split()
                        #print(f'First: {parts[0]} Second: {parts[1]}')
                        if len(parts) == 2:
                            data: str = parts[0]
                            value: str = parts[1]
                            # Store the key or status based on data type
                            if data.isalpha():
                                key = data
                            if value.isdigit():
                                status = int(value)
                            # Check if both key and status are available
                            if key is not None and status is not None:
                                if status == 1:
                                    # Press the key
                                    keyboard.press(key)
                                elif status == 0:
                                    # Release the key
                                    keyboard.release(key)
                                
                                # Clear variables after processing
                                key = None
                                status = None
                        else:
                            print(f"Invalid format: {line}")
                    except ValueError:
                        # Handle cases where the line is not formatted correctly
                        print(f"Received invalid data: {line}")

    except KeyboardInterrupt:
        # Gracefully handle script exit
        print("Exiting...")
    finally:
        ser.close()

if __name__ == "__main__":
    main()