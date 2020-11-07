#include <Servo.h>
#include <math.h>  

int servoPin = 3;
int Dist = 0;
double BaseDist = 150;
double CurrentDist;
double ArmLength = 5;
double P = 10;
double Ang;
double czas;
Servo servo;


long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  czas = pulseIn(echoPin, HIGH);
  return 0.01723 * czas;
}

void setup()
{
  Serial.begin(9600);
  servo.attach(servoPin);
  servo.write(0);
}

void loop()
{
  // measure the ping time in cm
  CurrentDist = readUltrasonicDistance(7, 7) - BaseDist;
  Dist = int(CurrentDist / 10) * P;
  Ang = atan(Dist/ArmLength)*180/3.14;
  //Serial.println(Dist);
  Serial.println(Ang);
  servo.write(P*Ang);
}
