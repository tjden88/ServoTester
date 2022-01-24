
#include <Servo.h>

int servoPin = 2; // ”правл€ющий пин сервомашинки
int centerLed = 5; // —ветодиод центральной позиции
int potentPin = A5; // ѕин потенциометра


Servo s1;

// the setup function runs once when you press reset or power the board
void setup() {

	s1.attach(servoPin);
	//Serial.begin(9600);
	pinMode(centerLed, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  int potValue = analogRead(potentPin);
  //Serial.println(potValue);
  bool isCenter = potValue > 500 && potValue < 530;
  digitalWrite(centerLed, isCenter);

  int servoAngle = map(potValue, 0, 1023, 0, 180);

  //Serial.println(servoAngle);

  if (isCenter) {
	  s1.write(90);
  }
  else
  {
	  s1.write(servoAngle);
  }

  delay(2);              // wait

}
