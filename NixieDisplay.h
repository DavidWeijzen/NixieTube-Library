/*
 *              _____  _____  _    _ _____ _   _  ____           
 *        /\   |  __ \|  __ \| |  | |_   _| \ | |/ __ \          
 *       /  \  | |__) | |  | | |  | | | | |  \| | |  | |         
 *      / /\ \ |  _  /| |  | | |  | | | | | . ` | |  | |         
 *     / ____ \| | \ \| |__| | |__| |_| |_| |\  | |__| |         
 *  _ /_/ ___\_\_|  \_\_____/_\____/|_____|_|_\_|\____/_  ______ 
 * | \ | |_   _\ \ / /_   _|  ____| |__   __| |  | |  _ \|  ____|
 * |  \| | | |  \ V /  | | | |__       | |  | |  | | |_) | |__   
 * | . ` | | |   > <   | | |  __|      | |  | |  | |  _ <|  __|  
 * | |\  |_| |_ / . \ _| |_| |____     | |  | |__| | |_) | |____ 
 * |_| \_|_____/_/ \_\_____|______|    |_|   \____/|____/|______|
 *
 *
 *    Liberary to use on Arduino compatible boards to drive a single nixie tube.
 *    Copyright (C) 2021  David Weijzen
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *     along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

/* 
 *  To use this liberary, create a class with: NixieDisplay name(Driver A, Driver B, Driver C, Driver D, Annode Pin, Decimal point Pin) All of them bytes.
 *  For example: NixieDisplay tube1(A0,A1,A2,A3,9,10); 
 *  In the setup do an initialisation with init()
 *  For example: tube1.init();
 *  Set a number to display with setNumberToDisplay(byte numberToDisplay, bool Decimal Point);
 *  For example: tube1.setNumberToDisplay(7,HIGH);
 *  To turn the tube system off use tubeShutdown();
 *  To turn this tube off but keep the number on the driver use tubeOff();
 *  
 */


#include "Arduino.h"

class NixieDisplay{
  private:
  
  byte numberDisplayed;
  byte driverPinA;
  byte driverPinB;
  byte driverPinC;
  byte driverPinD;
  byte dotPin;
  byte binaryNumberDisplayed;
  byte tubeAnnode;
  byte brightness;
  bool decimalPoint;
  
  public:

  //constructor
  NixieDisplay(byte driverPinA, byte driverPinB, byte driverPinC, byte driverPinD, byte tubeAnnode, byte dotPin);

  //methods
  init();
  setNumberToDisplay(byte setNumberToDisplay, bool decimalPointIn);
  setDriver();
  tubeShutdown();
  tubeOff();
};
