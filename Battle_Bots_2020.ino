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

// Go Forward at a Slow Speed
void forwardslow(){
  analogWrite(ENA, carSpeed1slow);
  analogWrite(ENB, carSpeed2slow);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("go forward!");
}

// Go Forward at a Fast Speed
void forwardfast(){
  analogWrite(ENA, carSpeed1fast);
  analogWrite(ENB, carSpeed2fast);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("go forward!");
}

// Go Back
void back(){
  analogWrite(ENA, carSpeed1fast);
  analogWrite(ENB, carSpeed2fast);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("go back!");
}

// Turn Left
void left(){
  analogWrite(ENA, carSpeed1slow);
  analogWrite(ENB, carSpeed2slow);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("go left!");
}

// Turn Right
void right(){
  analogWrite(ENA, carSpeed1slow);
  analogWrite(ENB, carSpeed2slow);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW); 
  Serial.println("go right!");
} 

// Stop Car
void Stop(){
   digitalWrite(ENA, LOW);
   digitalWrite(ENB, LOW);
   Serial.println("stop!");
} 

// Attack!
void attack(){
  forwardslow();
  delay(20);
  right();
  delay(2200);
  forwardslow();
  delay(1000);
  left();
  delay(2200);
  forwardfast();
  delay(2000);
  Serial.println("stop!");
}

void setup(){
  Serial.begin(9600);
}

void loop() {
  attack();
}
