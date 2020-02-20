// Create Servo Instance
#include <Servo.h> // call Servo libary
Servo myservo;     // create 'myservo' instance

// Line Tracking IO Define - Black
#define LT_RBlack !digitalRead(10) // reverse and get the digital input of pin 10 and assign to a variable
#define LT_MBlack !digitalRead(4)  // reverse and get the digital input of pin 4 and assign to a variable
#define LT_LBlack !digitalRead(2)  // reverse and get the digital input of pin 2 and assign to a variable

// Line Tracking IO Define - White
#define LT_RWhite digitalRead(10) // get the digital input of pin 10 and assign to a variable
#define LT_MWhite digitalRead(4)  // get the digital input of pin 10 and assign to a variable
#define LT_LWhite digitalRead(2)  // get the digital input of pin 10 and assign to a variable

// Define Motor Driver Pins
#define ENB 5  // assign pins to a variable 
#define IN1 7  // assign pins to a variable
#define IN2 8  // assign pins to a variable 
#define IN3 9  // assign pins to a variable
#define IN4 11 // assign pins to a variable
#define ENA 6  // assign pins to a variable

#define carSpeed1fast 230 // assign the fast right side speed to a variable
#define carSpeed2fast 210 // assign the fast left side speed to a variable
#define carSpeed1slow 155 // assign the slow right side speed to a variable
#define carSpeed2slow 130 // assign the slow left side speed to a variable

// Create Variables for Measuring SONAR Distances
int rightDistance = 0, leftDistance = 0, middleDistance = 0; // variables for the getDistance() function
int attackdone = 0           ;                               // variable to check to see if the attack has been finished
int Echo = A4;                                               // variable to output the time it takes for sound waves to travel
int Trig = A5;                                               // variable to send the sonic bursts to be picked up by the sensor

// Get Distance with SONAR Sensor
int getDistance() {
    digitalWrite(Trig, LOW);              // turn off Trig
    delayMicroseconds(2);                 // delay 2 microseconds
    digitalWrite(Trig, HIGH);             // turn on Trig
    delayMicroseconds(10);                // delay 10 microseconds
    digitalWrite(Trig, LOW);              // turn off Trig
    return (int)pulseIn(Echo, HIGH) / 58; // return the interger of the pulse from the SONAR sensor divided by 58
    Serial.println("Got distance!");      // print program status to serial monitor
}

// Go Forward at a Slow Speed
void forwardslow(){
  analogWrite(ENA, carSpeed1slow);      // set right wheels to slow speed
  analogWrite(ENB, carSpeed2slow);      // set left wheels to slow speed
  digitalWrite(IN1, HIGH);              // turn IN1 on
  digitalWrite(IN2, LOW);               // turn IN2 off
  digitalWrite(IN3, LOW);               // turn IN3 off
  digitalWrite(IN4, HIGH);              // turn IN4 on
  Serial.println("Go forward slowly!"); // print program status to serial monitor
}

// Go Forward at a Fast Speed
void forwardfast(){
  analogWrite(ENA, carSpeed1fast);    // set right wheels to fast speed
  analogWrite(ENB, carSpeed2fast);    // set left wheels to fast speed
  digitalWrite(IN1, HIGH);            // turn IN1 on
  digitalWrite(IN2, LOW);             // turn IN2 off
  digitalWrite(IN3, LOW);             // turn IN3 off
  digitalWrite(IN4, HIGH);            // turn IN4 on
  Serial.println("Go forward fast!"); // print program status to serial monitor
}

// Go Back
void back(){
  analogWrite(ENA, carSpeed1fast); // set right wheels to fast speed
  analogWrite(ENB, carSpeed2fast); // set left wheels to fast speed
  digitalWrite(IN1, LOW);          // turn IN1 off
  digitalWrite(IN2, HIGH);         // turn IN2 on
  digitalWrite(IN3, HIGH);         // turn IN3 on
  digitalWrite(IN4, LOW);          // turn IN4 off
  Serial.println("Go back!");      // print program status to serial monitor
}

// Turn Left
void left(){
  analogWrite(ENA, carSpeed1fast); // set right wheels to fast speed
  analogWrite(ENB, carSpeed2fast); // set left wheels to fast speed
  digitalWrite(IN1, LOW);          // turn IN1 off
  digitalWrite(IN2, HIGH);         // turn IN2 on
  digitalWrite(IN3, LOW);          // turn IN3 off
  digitalWrite(IN4, HIGH);         // turn IN4 on
  Serial.println("Go left!");      // print program status to serial monitor
}

// Turn Right
void right(){
  analogWrite(ENA, carSpeed1fast); // set right wheels to fast speed
  analogWrite(ENB, carSpeed2fast); // set left wheels to fast speed
  digitalWrite(IN1, HIGH);         // turn IN1 on
  digitalWrite(IN2, LOW);          // turn IN2 off
  digitalWrite(IN3, HIGH);         // turn IN3 on
  digitalWrite(IN4, LOW);          // turn IN4 off
  Serial.println("Go right!");     // print program status to serial monitor
} 

// Stop Car
void Stop(){
   digitalWrite(ENA, LOW);  // turn right wheels off
   digitalWrite(ENB, LOW);  // turn left wheels off
   Serial.println("Stop!"); // print program status to serial monitor
} 

// Attack!
void attack(){
  forwardslow();                // call the 'forwardslow()' function
  delay(20);                    // delay for 20 milliseconds
  right();                      // call the 'right()' function
  delay(420);                   // delay for 420 milliseconds
  forwardslow();                // call the 'forwardslow()' function
  delay(500);                   // delay for 500 milliseconds
  left();                       // call the 'left()' function
  delay(840);                   // delay for 840 milliseconds
  forwardfast();                // call the 'forwardfast()' function
  delay(750);                   // delay for 750 milliseconds
  attackdone = 1;               // let the program know the attack has been finished
  Serial.println("Attacking!"); // print program status to serial monitor
}

// Retreat!
void retreat(){
  back();                        // call the 'back()' function
  delay(2000);                   // delay for 2000 milliseconds
  left();                        // call the 'left()' function
  delay(380);                    // delay for 380 milliseconds
  forwardslow();                 // call the 'forwardslow()' function
  delay(200);                    // delay for 200 milliseconds
  right();                       // call the 'right()' function
  delay(750);                    // delay for 750 milliseconds
  Serial.println("Retreating!"); // print program status to serial monitor
}

// Reposition!
void reposition(){
  back();                           // call the 'back()' function
  delay(200);                       // delay for 200 milliseconds
  left();                           // call the 'left()' function
  delay(1500);                      // delay for 1500 milliseconds
  forwardslow();                    // call the 'forwardslow()' function
  delay(150);                       // delay for 150 milliseconds
  right();                          // call the 'right()' function
  delay(420);                       // delay for 420 milliseconds
  forwardfast();                    // call the 'forwardfast()' function
  delay(100);                       // delay for 100 milliseconds
  right();                          // call the 'right()' function
  delay(420);                       // delay for 420 milliseconds
  attack();                         // call the 'attack()' function
  Serial.println("Repositioning!"); // print program status to serial monitor
}

void setup() {
  Serial.begin(9600); // sets the data rate with the serial monitor
}

void loop() {
  forwardfast(); // call the 'attack()' function
  delay(888);
  while (LT_RWhite or LT_MWhite or LT_LWhite){ // start a while loop if LT_RWhite or LT_MWhite or LT_LWhite read white
    forwardfast();
    delay(250);
  if (LT_MBlack){ // start an if statement that will run if LT_MBlack reads black
    Stop();       // call the 'stop()' function
    delay(10);    // delay for 10 milliseconds
    back();       // call the 'back()' function
    delay(100);   // delay for 100 milliseconds
    right();      // call the 'right()' function
    delay(1500);  // delay for 1500 milliseconds
  }
  else if (LT_RBlack){ // start an else if statement that will run if LT_RBlack reads black
    Stop();            // call the 'stop()' function
    delay(10);         // delay for 10 milliseconds
    back();            // call the 'back()' function
    delay(100);        // delay for 100 milliseconds
    right();           // call the 'right()' function
    delay(1500);       // delay for 1500 milliseconds
  }
  else if (LT_LBlack){ // start an else if statement that will run if LT_LBlack reads black
    Stop();            // call the 'stop()' function
    delay(10);         // delay for 10 milliseconds
    back();            // call the 'back()' function
    delay(100);        // delay for 100 milliseconds
    right();           // call the 'right()' function
    delay(1500);       // delay for 1500 milliseconds
  }
  }
}
