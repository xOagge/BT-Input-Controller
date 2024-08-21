#define BLUETOOTH_BAUD 9600

String command = "";

bool Up = false;
bool Down = false;
bool Left = false;
bool Right = false;

bool X = false;
bool O = false;
bool S = false;
bool T = false;

bool START = true;

char cmdChar; // command char
int cmdCode; //int related to defined command

void setup() {
  // Initialize serial communication with the computer
  Serial.begin(9600);
  
  // Initialize serial communication with the Bluetooth module
  Serial1.begin(BLUETOOTH_BAUD); // Ensure this matches your Bluetooth module's baud rate
  //Serial.println("Bluetooth module is ready.");
  //Serial.println("Available commands:");
  //Serial.println("1. Movement Commands: 'w', 'a', 's', 'd'");
  //Serial.println("2. Action Commands: 'i', 'j', 'k', 'l'");
}

void loop() {
  BluetoothInputs();
  if (command.length() == 1) {
    VerifyIfActivityChange();
    if(START) UpdateController(cmdCode);
    command = "";
  }
}

void BluetoothInputs(){
// Serial1 -> Code
  if (Serial1.available()) {
    char incomingChar = Serial1.read();
    // Add info to command
    if (incomingChar != '\n') {
      command += incomingChar;
      command.trim();
      // Verify if there is new command
    }
  }
}

void VerifyIfActivityChange(){
  cmdChar = command.charAt(0); // Get the single character from the string
  cmdCode = getCommandCode(cmdChar);
  if(cmdCode == 8 || cmdCode == 9){
    switch (cmdCode) {
      case 8: START = true;  break;
      case 9: START = false; break;
      default:break;
    }
  }
}

int getCommandCode(char command) {
  switch (command) {
    case 'w': return 0; // MOVE_UP
    case 'a': return 1; // MOVE_LEFT
    case 's': return 2; // MOVE_DOWN
    case 'd': return 3; // MOVE_RIGHT
    case 'i': return 4; // ACTION_T
    case 'j': return 5; // ACTION_S
    case 'k': return 6; // ACTION_X
    case 'l': return 7; // ACTION_O
    case '+': return 8; // ACTIVITY ON
    case '-': return 9; // ACTIVITY OFF
    default: return -1; // UNKNOWN_COMMAND
  }
}

// Update the controller based on the command
// Usage in UpdateController
void UpdateController(int cmdCode) {
  switch (cmdCode) {
    case 0: ChangeSignal(Up); break;
    case 1: ChangeSignal(Left); break;
    case 2: ChangeSignal(Down); break;
    case 3: ChangeSignal(Right); break;
    case 4: ChangeSignal(T); break;
    case 5: ChangeSignal(S); break;
    case 6: ChangeSignal(X); break;
    case 7: ChangeSignal(O); break;
    default: break; // Handle unknown command if necessary
  }
}

// Toggle the signal of the boolean variable
void ChangeSignal(bool &type) {
  type = !type;
  Serial.print(cmdChar);
  Serial.print(" ");
  Serial.println(type);
}