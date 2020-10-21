int buzzer = D2;
int smokeA0 = A0;

// wartosc graniczna
int sensorThres = 600;

void setup() {
 pinMode(buzzer, OUTPUT);
 pinMode(smokeA0, INPUT);
 Serial.begin(9600);
}

void loop() {
 int analogSensor = analogRead(smokeA0);

 Serial.print("Pin A0: ");
 Serial.println(analogSensor);
 if (analogSensor > sensorThres)
 {
   tone(buzzer, 1000, 200);
 }
 else
 {
   noTone(buzzer);
 }
 delay(100);
}
