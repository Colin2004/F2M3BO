/*
  ESP8266 Blink by Simon Peter
  Blink the blue LED on the ESP-01 module
  This example code is in the public domain
  The blue LED on the ESP-01 module is connected to GPIO1
  (which is also the TXD pin; so we cannot use Serial.print() at the same time)
  Note that this sketch uses LED_BUILTIN to find the pin with the internal LED
*/
uint8_t Led1 = D3;
uint8_t Led2 = D5;
uint8_t Led3 = D6;

void setup() {
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(Led1, HIGH);   // Turn the LED on (Note that LOW is the voltage level            // Wait for a second
  digitalWrite(Led2, HIGH);
  digitalWrite(Led3, HIGH);
  delay(100);
  digitalWrite(Led1, LOW);   // Turn the LED on (Note that LOW is the voltage level            // Wait for a second
  digitalWrite(Led2, LOW);
  digitalWrite(Led3, LOW);
   delay(100);
  digitalWrite(Led1, HIGH);   // Turn the LED on (Note that LOW is the voltage level            // Wait for a second
  digitalWrite(Led2, LOW);
  digitalWrite(Led3, LOW);
}