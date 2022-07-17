#include <Keyboard.h>
int ledWait = 13;
int ledWrite = 12;
int button_pin = 2;

void setup() {
Keyboard.begin(); //this starts the keyboard function
pinMode(ledWait, OUTPUT); // sets digital pin 13 as output
pinMode(ledWrite, OUTPUT); // sets digital pin 12 as output
pinMode(button_pin, INPUT);
}

void loop() {

int button_state = digitalRead(button_pin);
if (button_state == HIGH) {

/*PC waits until bootloader shows
 *check the timing!!!
 */
 
// 50 = seconds (HIGH + LOW equals total delay(1000) = 1 sec)
for (int counter=0; counter <20; counter++) {

digitalWrite(ledWait, HIGH);
Keyboard.write(KEY_BACKSPACE);
delay(500); //1000 = 1 second 10.000 = 10 seconds
digitalWrite(ledWait, LOW);
Keyboard.write(KEY_BACKSPACE);
delay(500);
}

// Arduino macht einen Klick nach oben 
Keyboard.write(KEY_UP_ARROW);
digitalWrite(ledWrite, HIGH);
delay(100);
digitalWrite(ledWrite,LOW);

// in my case the Arduino has to click: <up> <up> <up> <return> to enter the preferred OS to boot  
Keyboard.write(KEY_UP_ARROW);
digitalWrite(ledWrite, HIGH);
delay(100);
digitalWrite(ledWrite,LOW);

Keyboard.write(KEY_UP_ARROW);
digitalWrite(ledWrite, HIGH);
delay(100);
digitalWrite(ledWrite,LOW);

Keyboard.write(KEY_UP_ARROW);
digitalWrite(ledWrite, HIGH);
delay(100);
digitalWrite(ledWrite,LOW);

/*Keyboard.write(KEY_UP_ARROW);
digitalWrite(ledWrite, HIGH);
delay(100);
digitalWrite(ledWrite,LOW);
*/
Keyboard.write(KEY_RETURN);
digitalWrite(ledWrite, HIGH);
delay(100);
digitalWrite(ledWrite,LOW);

// this ends the keyboard function 
Keyboard.end();


// blinks until PC is booted (50 = Sekunden)
for (int counter=0; counter <20; counter++) {

digitalWrite(ledWait, HIGH);
delay(500); //1000 = 1 second 10.000 = 10 seconds
digitalWrite(ledWait, LOW);
delay(500);
}


//exit the loop
//exit(0);

  }
}
