# SecureLockX – Arduino Smart Door Lock System 🔐

SecureLockX is a tech-driven, Arduino-powered smart door lock simulation created in Proteus. It uses a 4x3 matrix keypad for password entry, an LCD display for user interaction, a servo motor to control the door, and red/green LEDs for access feedback.

## 🚀 Features
- Keypad-based password authentication
- LCD display for real-time instructions and feedback
- Servo motor controlled door lock/unlock system
- Visual feedback using red (denied) and green (granted) LEDs
- Password reset with '*' key
- Secure and user-friendly interface

## 🧰 Tech Stack
- Arduino Uno
- 4x3 Matrix Keypad
- 16x4 LCD Display
- Servo Motor (SG90)
- LEDs (Red & Green)
- Proteus for circuit simulation
- C++ (Arduino code)

## 🛠️ How it Works
1. User is prompted to enter a 4-digit password.
2. Pressing `#` checks the password:
   - ✅ Correct password: Door opens (servo rotates), green LED turns on.
   - ❌ Wrong password: Access denied, red LED turns on.
3. `*` key clears input anytime.

## 📂 File Structure
├── SmartDoorLock.ino # Arduino source code
├── SecureLockX.pdsprj # Proteus simulation file
└── README.md # Project documentation



## 🔐 Default Password
`1234` (can be customized in the code)



## ✨ Future Improvements
- Add keypad lockout after multiple failed attempts
- Integrate RFID or biometric scanner
- IoT-based remote monitoring

---

## 🧠 Author
**Pritam Saha**  
📧 prilectraz4xy@gmail.com  
🔗 [LinkedIn](https://www.linkedin.com/in/prilectro1809)
