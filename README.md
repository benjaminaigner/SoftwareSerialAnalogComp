## Software serial with the analog comparator

This library is basically the original SoftwareSerial library:

https://github.com/PaulStoffregen/SoftwareSerial

I replaced the pin change interrupts by the analog comparator and
added the possibility to set a bias voltage.

Please note that this library is not fully tested right now.

## Why?

If you have a serial interface which does not use pure binary voltage levels,
you can use this library.
One example is the eBus, which uses 9-12V for logic low and 15-24V for logic high.
See:
https://github.com/benjaminaigner/eBusAdapterArduino

## Notes

Please note that this library has some implications:
* Works only on AVR with analog comparator (all with ATMega328P/ATMega168P)
* The RX pin is ALWAYS pin 6
* You MUST connect the pwm pin to pin 7
* As TX pin, every GPIO can be selected
