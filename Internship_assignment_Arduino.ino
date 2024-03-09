#include<Arduino.h>
#include<elapsedMillis.h> //library used for the Timer function

const int ledPin = 13; //initialized the inbuilt LED pin
const int sensorTemp = A0; //initialized the pin A0 as the tempSensor pin
const int threshTemp = 30; //created a variable for the threshold temparature
elapsedMillis blinkTimer; //created an instance of the library 

void setup(){
  pinMode(ledPin,OUTPUT); //set the LED to OUTPUT
  pinMode(sensorTemp,INPUT); //set the sensor to INPUT
}

void loop(){
  int temparature = readTemp(); //calling the temparature's value from the function
  if(temparature < threshTemp){
    blinkLed(250); //if the temparature is less than 30, LED blinks in intervals of 250ms
  }
  else{
    blinkLed(500); //if the temparature is less than 30, LED blinks in intervals of 500ms
  }
}

int readTemp(){
  int sensorInput = analogRead(sensorTemp); //reading analog input from sensor
  float voltage = (sensorInput * 5.0)/1024.0; //calculating voltage from analog input
  float temparatureC = voltage * 100; // converting to temparature in degree celsius
  return temparatureC;
}

void blinkLed(int interval){ //function to enable blinking of the LED at intervals specified
  if(blinkTimer >= interval){
    digitalWrite(ledPin,!digitalRead(ledPin));
    blinkTimer = 0; // unsetting the blink interval value
  }
}