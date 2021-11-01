  

#include "NixieDisplay.h"
  
  NixieDisplay::NixieDisplay(byte driverPinA, byte driverPinB, byte driverPinC, byte driverPinD, byte tubeAnnode, byte dotPin){
    this->driverPinA = driverPinA;
    this->driverPinB = driverPinB;
    this->driverPinC = driverPinC;
    this->driverPinD = driverPinD;
    this->tubeAnnode = tubeAnnode;
    this->dotPin = dotPin;
  }
  
  NixieDisplay::setDriver(){
    switch(numberDisplayed){
      case 0: binaryNumberDisplayed = 0b0000;
        break;
      case 1: binaryNumberDisplayed = 0b0001;
        break;
      case 2: binaryNumberDisplayed = 0b0010;
        break;
      case 3: binaryNumberDisplayed = 0b0011;
        break;
      case 4: binaryNumberDisplayed = 0b0100;
        break;
      case 5: binaryNumberDisplayed = 0b0101;
        break;
      case 6: binaryNumberDisplayed = 0b0110;
        break;
      case 7: binaryNumberDisplayed = 0b0111;
        break;
      case 8: binaryNumberDisplayed = 0b1000;
        break;
      case 9: binaryNumberDisplayed = 0b1001;
        break;

      case 69: binaryNumberDisplayed = 0b1111; //Power off
        break;
    }
  digitalWrite(driverPinA, binaryNumberDisplayed & 0b00000001);
  digitalWrite(driverPinB, binaryNumberDisplayed & 0b00000010);
  digitalWrite(driverPinC, binaryNumberDisplayed & 0b00000100);
  digitalWrite(driverPinD, binaryNumberDisplayed & 0b00001000);
  digitalWrite(dotPin, decimalPoint);
  analogWrite(tubeAnnode, brightness);
  }

  NixieDisplay::init(){
  pinMode(driverPinA, OUTPUT);
  pinMode(driverPinB, OUTPUT);
  pinMode(driverPinC, OUTPUT);
  pinMode(driverPinD, OUTPUT);
  pinMode(tubeAnnode, OUTPUT);
  }

  NixieDisplay::setNumberToDisplay(byte setNumberToDisplay, bool decimalPointIn, byte brightnessIn){
    numberDisplayed = setNumberToDisplay;
    brightness = brightnessIn;
    decimalPoint = decimalPointIn;
    setDriver();
  }

  NixieDisplay::tubeShutdown(){
    numberDisplayed = 69; //nice.
    setDriver();
    digitalWrite(tubeAnnode, LOW);
  }

  NixieDisplay::tubeOff(){
    digitalWrite(tubeAnnode, LOW);
    digitalWrite(dotPin, LOW);
  }
