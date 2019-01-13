/*
  Software serial with analog comparator - test
 
 Receives from the hardware serial, sends to software serial.
 Receives from software serial, sends to hardware serial.
 
 The circuit: 
 * RX is digital pin 6 (connect to eBus input via a voltage divider 100k/12k)
 * TX is digital pin 5 (connect to pull down MOSFET/transistor)
 * PWM pin is digital pin 9 (connect to digital pin 7)
 
 Note:
 Not all pins allow PWM output, please refer to:
 https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/
 
 modified by Benjamin Aigner for SoftwareSerialAnalogComp in 01.2019
 
 created back in the mists of time
 modified 25 May 2012
 by Tom Igoe
 based on Mikal Hart's example
 
 This example code is in the public domain.
 
 */

#include "Arduino.h"
#include "SoftwareSerialAnalogComp.h"

SoftwareSerialAnalogComp ebus(9, 5, false, true);
uint8_t incomingByte;

void setup()
{
  //change baud rate of BLE module to 115200
  Serial.begin(9600);
  Serial.write("AT+BAUD 115200\r\n");
  delay(5);
  Serial.begin(115200);
  
  //set bias of PWM to 112, is 1,44V@3V3
  ebus.setBias(112);
  //begin ebus serial with 1200 baud
  ebus.begin(1200);
}

void loop()
{
  //if something is available
  if (ebus.available() > 0) {
		// read the incoming byte & send to serial.
		incomingByte = ebus.read();
		Serial.print(incomingByte);
	}
  //if something is available
  if (Serial.available() > 0) {
		// read the incoming byte & send to serial.
		incomingByte = Serial.read();
		ebus.print(incomingByte);
	}
} 
