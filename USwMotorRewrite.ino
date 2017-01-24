#include <AccelStepper.h>
#define ON 0x1
#define OFF 0x0

AccelStepper Xaxis(AccelStepper::DRIVER,2,5);				//These are the three steppers. Enable/disable are on pin 8
AccelStepper Yaxis(AccelStepper::DRIVER,3,6);				//while controlling them are on pins 2,3 and 4.
AccelStepper Zaxis(AccelStepper::DRIVER,4,7);

int Stimer1, Stimer2, Stimer3, globalTimer; //This initializes a timer I hope to impliment later.
long distance[4] {1, 2, 3, 4};				//These are the read distances for the sensors.
const int anPin[4] {1, 2, 3, 4};
//const int redPin = 48;
//const int greenPin = 50;
//const int bluePin = 52;
int stopDistance[3] {10, 30, 80};

void setup() {
	
	
  Serial.begin(9600);
//  globalTimer = 0;
  Xaxis.setMaxSpeed(2000.0);
  Xaxis.setAcceleration(100.0);
  Xaxis.moveTo(200);
  
  Yaxis.setMaxSpeed(2000.0);
  Yaxis.setAcceleration(100.0);
  Yaxis.moveTo(200);

  Zaxis.setMaxSpeed(2000.0);
  Zaxis.setAcceleration(100.0);
  Zaxis.moveTo(200);

  pinMode(8, OUTPUT);
  digitalWrite(8, LOW);
}

void read_sensors() {
	auto i = 0;
  for (distance[i]; i > 5; i++) {
    distance[i] = ((analogRead(anPin[i]) * 5) / 25.4);
  }
}
void print_sensors() {
	read_sensors();
	Serial.println(distance[0]);
	Serial.println(distance[1]);
	Serial.println(distance[2]);
	Serial.println(distance[3]);

}

void loop() {

}
