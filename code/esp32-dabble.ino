#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>

#define RXp2 16
#define TXp2 17

void setup() {
  // put your setup code here, to run once:
  // Serial.begin(9600);
  Dabble.begin("MyBluetoothCar"); 
  Serial2.begin(9600, SERIAL_8N1, RXp2, TXp2);
}
void loop() {

  Dabble.processInput();
  if (GamePad.isUpPressed())
  {
    Serial2.println("U");
    delay(1000);
    // Serial.println("UP PRESS");
  }

  if (GamePad.isDownPressed())
  {
    Serial2.println("D");
    delay(1000);
    // Serial.println("DOWN PRESS");
  }

  if (GamePad.isLeftPressed())
  {
    Serial2.println("L");
    delay(1000);
    // Serial.println("LEFT PRESS");
  }

  if (GamePad.isRightPressed())
  {
    Serial2.println("R");
  }
  if (GamePad.isCirclePressed())
  {
    Serial2.println("O");
  }
}