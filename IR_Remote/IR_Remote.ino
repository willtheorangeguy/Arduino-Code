#include <IRremote.h>
#include <IRremoteInt.h>

#define RECV_PIN  12 //Infrared signal receiving pin
#define LED       13 //define LED pin
#define L         16738455 //Sequence given to IR receiver
#define UNKNOWN_L 1386468383 //Repeat Sequence

bool state = LOW;
unsigned long val; //extended variable for long sequences of numbers

IRrecv irrecv(RECV_PIN); //initializing library
decode_results results; //Define structure type, store as "results"

void stateChange(){
  state = !state;
  digitalWrite(LED, state);
}

void setup() {
  pinMode(LED, OUTPUT); //initialize LED as an output
  Serial.begin(9600);
  irrecv.enableIRIn(); //Start receiving
}

void loop() {
  if (irrecv.decode(&results)){
    val = results.value;
    Serial.println(val);
    irrecv.resume();  //receive the next value
    delay(150);
    if(val == L || val == UNKNOWN_L){  
      stateChange();
    }
   
  }

}
