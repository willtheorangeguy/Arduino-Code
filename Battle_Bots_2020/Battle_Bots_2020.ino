#include <Servo.h>
Servo myservo;

// Line Tracking IO Define - Black
#define LT_RBlack !digitalRead(10)
#define LT_MBlack !digitalRead(4)
#define LT_LBlack !digitalRead(2)

// Line Tracking IO Define - White
#define LT_RWhite digitalRead(10)
#define LT_MWhite digitalRead(4)
#define LT_LWhite digitalRead(2)

// Define Motor Driver Pins
#define ENB 5
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11
#define ENA 6

#define carSpeed1fast 255 //Right side speed - fast
#define carSpeed2fast 240 //Left side speed - fast
#define carSpeed1slow 155 //Right side speed - fast
#define carSpeed2slow 130 //Left side speed - fast

int attackstart = 0;
int rightDistance = 0, leftDistance = 0, middleDistance = 0;

int Echo = A4;
int Trig = A5;

// Get Distance with SONAR Sensor
int getDistance() {
    digitalWrite(Trig, LOW);
    delayMicroseconds(2);
    digitalWrite(Trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(Trig, LOW);
    return (int)pulseIn(Echo, HIGH) / 58;
    Serial.println("Got distance!");
}

// Go Forward at a Slow Speed
void forwardslow(){
  analogWrite(ENA, carSpeed1slow);
  analogWrite(ENB, carSpeed2slow);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Go forward slowly!");
}

// Go Forward at a Fast Speed
void forwardfast(){
  analogWrite(ENA, carSpeed1fast);
  analogWrite(ENB, carSpeed2fast);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Go forward fast!");
}

// Go Back
void back(){
  analogWrite(ENA, carSpeed1fast);
  analogWrite(ENB, carSpeed2fast);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Go back!");
}

// Turn Left
void left(){
  analogWrite(ENA, carSpeed1fast);
  analogWrite(ENB, carSpeed2fast);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Go left!");
}

// Turn Right
void right(){
  analogWrite(ENA, carSpeed1fast);
  analogWrite(ENB, carSpeed2fast);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW); 
  Serial.println("Go right!");
} 

// Stop Car
void Stop(){
   digitalWrite(ENA, LOW);
   digitalWrite(ENB, LOW);
   Serial.println("Stop!");
} 

// Attack!
void attack(){
  forwardslow();
  delay(20);
  right();
  delay(420);
  forwardslow();
  delay(500);
  left();
  delay(840);
  forwardfast();
  delay(750);
  Serial.println("Attacking!");
}

// Retreat!
void retreat(){
  back();
  delay(2000);
  left();
  delay(380);
  forwardslow();
  delay(200);
  right();
  delay(750);
  Serial.println("Retreating!");
}

// Reposition!
void reposition(){
  back();
  delay(200);
  left();
  delay(1500);
  forwardslow();
  delay(150);
  right();
  delay(420);
  forwardfast();
  delay(100);
  right();
  delay(420);
  attack();
  Serial.println("Repositioning!");
}

void setup(){
  Serial.begin(9600);
}

void loop() {
  attack();
  if(LT_M){
   Stop();
   delay(10);
   back();
   delay(100);
   right();
   delay(1500);
  }
  else if(LT_R){
   Stop();
   delay(10);
   back();
   delay(100);
   right();
   delay(1500);
  }
  else if(LT_L){
   Stop();
   delay(10);
   back();
   delay(100);
   right();
   delay(1500);
  }
  else {
   retreat();
   reposition();
  }
  while(LT_RWhite or LT_MWhite or LT_LWhite){
    myservo.write(90);
    delay(500);
    middleDistance = getDistance();
    if (middleDistance <= 20){
      reposition();
      attack();
    }
    else{
      forwardslow();
      delay(100);
      reposition();
      attack();
    }
  if (LT_M)
  {
    Stop();
    delay(10);
    back();
    delay(100);
    right();
    delay(1500);
  }
  else if (LT_R)
  {
    Stop();
    delay(10);
    back();
    delay(100);
    right();
    delay(1500);
  }
  else (LT_L)
  {
    Stop();
    delay(10);
    back();
    delay(100);
    right();
    delay(1500);
  }
  while (LT_RWhite or LT_MWhite or LT_LWhite){
    myservo.write(90);
    delay(500);
    middleDistance = getDistance();
    if (middleDistance <= 20)
    {
      attack();
    }
    else
    {
      forwardslow();
      delay(100);
      attack();
    }
  }
  Stop();
}
