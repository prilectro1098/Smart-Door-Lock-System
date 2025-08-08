#include <Servo.h>
#include <LiquidCrystal.h>
#include <Keypad.h>

// Initialize the LCD (16x4)
LiquidCrystal lcd(A4, A5, A0, A1, A2, A3);

// Servo motor setup
Servo doorMotor;

// Pin assignments for LEDs
const int redLED = 13;
const int greenLED = 12;

// Password variables
const String correctPassword = "1234";  // Change to your desired password
String enteredPassword = "";

// Keypad setup
const byte ROWS = 4;  // Four rows
const byte COLS = 3;  // Three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {4, 5, 6, 3};  // Connect keypad rows to these Arduino pins
byte colPins[COLS] = {0, 1, 2};     // Connect keypad columns to these Arduino pins
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  // Set up the LCD's number of columns and rows
  lcd.begin(16, 4);
  
  // Servo motor setup
  doorMotor.attach(9);
  
  // Set LEDs as outputs
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  // Initial state: close the door and turn off LEDs
  doorMotor.write(0);  // 0 degrees (closed)
  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, LOW);
  
  lcd.clear();
  lcd.print("Enter password:");
}

void loop() {
  char key = keypad.getKey();
  
  if (key) {
    // If the user presses '#', it checks the entered password
    if (key == '#') {
      if (enteredPassword == correctPassword) {
        // Correct password entered
        lcd.clear();
        lcd.print("Correct Password");
        lcd.setCursor(0, 1);
        lcd.print("Door is open!");
        lcd.setCursor(0, 2);
        lcd.print("Pls Welcome!");
        
        // Open the door and turn on the green LED
        doorMotor.write(90);  // 90 degrees (open)
        digitalWrite(greenLED, HIGH);
        digitalWrite(redLED, LOW);
      } else {
        // Wrong password entered
        lcd.clear();
        lcd.print("Wrong Password");
        lcd.setCursor(0, 1);
        lcd.print("Entry is");
        lcd.setCursor(0, 2);
        lcd.print("prohibited!");
        
        // Keep the door closed and turn on the red LED
        doorMotor.write(0);  // 0 degrees (closed)
        digitalWrite(redLED, HIGH);
        digitalWrite(greenLED, LOW);
      }
      
      delay(3000);  // Pause for 3 seconds
      
      // Reset everything after check
      lcd.clear();
      lcd.print("Enter password:");
      enteredPassword = "";  // Clear entered password
    } else if (key == '*') {
      // If '*' is pressed, clear the current password
      enteredPassword = "";
      lcd.clear();
      lcd.print("Enter password:");
    } else {
      // Add the pressed key to the password
      enteredPassword += key;
      lcd.setCursor(0, 1);
      lcd.print(enteredPassword);
    }
  }
}
