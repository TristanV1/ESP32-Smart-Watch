
#include <BleKeyboard.h>
//Set the name of the bluetooth keyboard (that shows up in the bluetooth menu of your device)
BleKeyboard bleKeyboard("ESP_32_TEST");

const int buttonPin = 0;
//Set the old button state to be LOW/false; which means not pressed
boolean oldPinState = LOW;


void setup() {
  //Start the Serial communication (with the computer at 115200 bits per second)
  Serial.begin(115200);
  //Send this message to the computer
  Serial.println("Starting BLE work!");
  //Begin the BLE keyboard/start advertising the keyboard (so phones can find it)
  bleKeyboard.begin();
  //Make the button pin an INPUT_PULLDOWN pin, which means that it is normally LOW, untill it is pressed/ connected to the 3.3V
  pinMode(buttonPin, INPUT_PULLUP);
}

int state = 0;
int val = 1;
int previousState = 0;
void loop() {

  if (bleKeyboard.isConnected()) {

    if (val == 1){
      Serial.println("CONNECTED!");
      val = 0;
    }

    if (state != previousState && digitalRead(buttonPin) == LOW) {
      bleKeyboard.press(KEY_MEDIA_PLAY_PAUSE);
      Serial.println("Button press!");
    }

  }

  previousState = state;
  state = digitalRead(buttonPin);

  delay(10);
  
}