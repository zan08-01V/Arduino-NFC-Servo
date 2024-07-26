#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

// Define pins
#define RST_PIN 9
#define SS_PIN 10
#define GREEN_LED_PIN 3
#define RED_LED_PIN 4
#define BUTTON_PIN 5
#define SERVO_PIN 6

// Create objects
MFRC522 mfrc522(SS_PIN, RST_PIN);  //MFRC522 instance
Servo myServo;  //Servo instance

// Define the UID of the authorized NFC card
byte authorizedUID[] = {0xDE, 0xAD, 0xBE, 0xEF}; // Replace with your card's UID

void setup() {
  Serial.begin(9600);
  
  // Initialize MFRC522
  SPI.begin();
  mfrc522.PCD_Init();
  
  // Initialize LEDs
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  
  // Initialize Button
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Using internal pull-up resistor
  
  // Initialize Servo
  myServo.attach(SERVO_PIN);
  myServo.write(0); // Start with servo at 0 degrees
}

void loop() {
  //Check NFC card
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    Serial.println("NFC card detected");
    
    // Check UID 
    if (compareUID(mfrc522.uid.uidByte, authorizedUID)) {
      Serial.println("Authorized card detected");
      
      // Turn servo  90 degrees/change LED
      myServo.write(90);
      digitalWrite(GREEN_LED_PIN, HIGH);
      digitalWrite(RED_LED_PIN, LOW);
      
      delay(2000); // Wait for 2 seconds before checking button
    }
    
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
  }
  
  // Check button
  if (digitalRead(BUTTON_PIN) == LOW) {
    Serial.println("Button pressed");
    
    // Turn servo back to -90 degrees
    myServo.write(270); /Adjust as necessary.
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, HIGH);
    
    delay(1000); // Debounce delay
  }
}

bool compareUID(byte *uid1, byte *uid2) {
  for (byte i = 0; i < 4; i++) {
    if (uid1[i] != uid2[i]) {
      return false;
    }
  }
  return true;
}
