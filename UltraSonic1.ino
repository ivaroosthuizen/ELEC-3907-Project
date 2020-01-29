const int eightPin = 8;
const int ninePin = 9;
float duration, distance;

void setup() {

  //Declaring the Pins on the Board and Setting the Serial Data Transmission Speed
  pinMode(eightPin, OUTPUT);
  pinMode(ninePin, INPUT);
  Serial.begin(9600);  

}

void loop() {

  //Starts and stops the ultrasonic transmitter. Sends out a pulse for 10 microseconds.
  digitalWrite(eightPin, LOW);
  delayMicroseconds(2);
  digitalWrite(eightPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(eightPin, LOW);

  //When the ninePin goes high the reciever has recieved the ultrasonic burst and records
  //the time taken for the wave to travel. Finds Distance.
  duration = pulseIn(ninePin, HIGH);
  distance = (duration*0.0343)/2;
  delay(100);
  
}
