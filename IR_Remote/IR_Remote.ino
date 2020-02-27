#include <IRremote.h>
#include <IRremoteInt.h>

// Define Pins
#define RECV_PIN 12          // infared signal receiver
#define LED 13               // define LED pin
#define L 16738455           // sequence given to IR receiver
#define UNKNOWN_L 1386468383 // repeat sequence

// Variables
bool state = LOW;  // create a boolean value
unsigned long val; // extended variable for long sequence of numbers

// Initialize IR Remote Library
IRrecv irrecv(RECV_PIN); // initialize library
decode_results results;  // define structure type and store as results

// Redefine the Boolean as Opposite
void stateChange (){
    state = !state;
    digitalWrite(LED, state);
}

void setup() {
    pinMode(LED, OUTPUT); // initialize LED as an OUTPUT
    Serial.begin(9600);   // set serial data rate
    irrecv.enableIRIn();  // start receiving
}

void loop() {
    if (irrecv.decode)
}