int tregPin =4;
int echoPin = 3;
float distance;
float timeInverval;
int buzzerPin = 13;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(tregPin,OUTPUT);
pinMode(echoPin,INPUT);
pinMode(buzzerPin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(tregPin,LOW);
delayMicroseconds(2);
digitalWrite(tregPin,HIGH);
delayMicroseconds(10);
digitalWrite(tregPin,LOW);
timeInverval = pulseIn(echoPin,HIGH);
distance = timeInverval *(0.000001)*(330);
if(distance > 0.30){
  analogWrite(buzzerPin,63.75);
  

}
if (distance <= 0.30 && distance >= 0.20){
    analogWrite(buzzerPin,127.5);

}
else{
      analogWrite(buzzerPin,255);

}
Serial.println("The distance from the Ultra sound sensor is "+String(distance)+ " m");


}