int pingPin = 9;
int echoPin = 10;
int outLED = 7;

float threshld = 10.01;
int delayedBy = 100;

void setup() {
  Serial.begin(9600); 
  pinMode(outLED, OUTPUT);
  pinMode(pingPin, OUTPUT);
  pinMode(echoPin, INPUT); 
}

 

void loop() {
  if(detected(threshld)){
    outPut(outLED, 1);
  }
  else{
    outPut(outLED, 0);
  }
  delay(delayedBy);
}

void outPut(int pin, int value){
  digitalWrite(pin, value);
}
  
int detected(float threshold){
 long duration, cm;
 pinMode(pingPin, OUTPUT);
 digitalWrite(pingPin, LOW);
 delayMicroseconds(2);
 digitalWrite(pingPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(pingPin, LOW);
 pinMode(echoPin, INPUT);
 duration = pulseIn(echoPin, HIGH);
 cm = microsecondsToCentimeters(duration);
 Serial.print(cm);
 Serial.print("cm");
 Serial.println();
 if(cm <= threshold){
   return 1;
 }
 return 0;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
