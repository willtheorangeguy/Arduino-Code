//  == MOTOR TRUTH TABLE ==
//  ENA   ENB   IN1   IN2   IN3   IN4   Description
//  HIGH  HIGH  HIGH  LOW   LOW   HIGH  Car is runing forward
//  HIGH  HIGH  LOW   HIGH  HIGH  LOW   Car is runing back
//  HIGH  HIGH  LOW   HIGH  LOW   HIGH  Car is turning left
//  HIGH  HIGH  HIGH  LOW   HIGH  LOW   Car is turning right
//  HIGH  HIGH  LOW   LOW   LOW   LOW   Car is stoped
//  HIGH  HIGH  HIGH  HIGH  HIGH  HIGH  Car is stoped
//  LOW   LOW   N/A   N/A   N/A   N/A   Car is stoped

// define L298n module IO Pin
#define ENB 5
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11
#define ENA 6

// forward function
void forward(){
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  Serial.println("Forward");
}

// backwards function
void back(){
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  Serial.println("Back");
}

// turn left function
void left(){
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  Serial.println("Left");
}

// turn right function
void right(){
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  Serial.println("Right");
}

// stop function
void brake(){
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
}

void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop() {
  forward();
  delay(200);
  right();
  delay(350);
  right();
  delay(200);
  right();
  delay(320);
  brake();
}