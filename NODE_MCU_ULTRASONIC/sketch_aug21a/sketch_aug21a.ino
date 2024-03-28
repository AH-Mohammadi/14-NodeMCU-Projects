#include <Ultrasonic.h>
#define BUZZER_PIN 2


/*
 * Pass as a parameter the trigger and echo pin, respectively,
 * or only the signal pin (for sensors 3 pins), like:
 * Ultrasonic ultrasonic(13);
 */
Ultrasonic ultrasonic(12, 13);
int distance;

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  // Pass INC as a parameter to get the distance in inches
  distance = ultrasonic.read();
  if (distance>15){
    tone(BUZZER_PIN, 500, 220);

  }
  Serial.print("Distance in CM: ");
  Serial.println(distance);
  delay(1000);
}
