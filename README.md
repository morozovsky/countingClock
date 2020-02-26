# countingClock
Code, MCAD, and EECAD for Counting Clock Project

## Electrical Assembly Instructions
Almost all of the parts are reverse-polarity sensitive, that is, if you plug them in backwards, they can be damaged.

### Required Tools
* Soldering iron
* Solder (leaded is easy to work with than lead-free, but don't eat it)
* Snips (to trim excess wire leads)

### Bill of Materials

Quantity | Reference Designator on PCB | Part Description | Manufacturer Part Number | Mouser.com Part Number
------------ | ------------- | ------------- | ------------- | -------------
2 | U1, U2 | Counter Shift Registers DIP 16 pins | SN74HC595N | [595-SN74HC595N](https://www.mouser.com/ProductDetail/595-SN74HC595N)
1 | U4 | Buffers & Line Drivers DIP 14 pins | SN74AHCT125N | [595-SN74AHCT125N](https://www.mouser.com/ProductDetail/595-SN74AHCT125N)
2 | R1, R2 | Resistor Networks DIP 16 pins 150 OHMS Isolated | 4116R-1-151LF | [652-4116R-1LF-150](https://www.mouser.com/ProductDetail/652-4116R-1LF-150)
1 | R3 | Resistor Networks SIP 5 pins 120 OHMS Bussed | 4605X-101-121LF | [652-4605X-1LF-120](https://www.mouser.com/ProductDetail/652-4605X-1LF-120)
2 | C1, C2 | Multilayer Ceramic Capacitors - Leaded 0.1uF 50volts 10% X7R 5mm LS | K104K15X7RF53H5 | [594-K104K15X7RF53H5](https://www.mouser.com/ProductDetail/594-K104K15X7RF53H5)
4 | D1, D2, D3, D4 | Through Hole LED 3mm Green | HLMP-1503-C0002 | [630-HLMP-1503-C0002](https://www.mouser.com/ProductDetail/630-HLMP-1503-C0002)
1 | DS1 | LED Display 2 Digit DIP 18 pins | LTD-5623AG | [859-LTD-5623AG](https://www.mouser.com/ProductDetail/859-LTD-5623AG)
2 | J1, J2 | Female header 10 pins

## Mechanical Assembly Instructions
1. Push the tabs in the case towards the edges of the case and slide in the circuit board, make sure to align the LED display and LEDs towards the openings (it will only fit one way).

## Software Instructions
1. Download and install Arduino IDE from: https://www.arduino.cc/en/main/software
1. esp32 board definition https://github.com/espressif/arduino-esp32/blob/master/docs/arduino-ide/boards_manager.md
1. manage libraries: install Time, TinyPICO
1. Connect your computer to the TinyPICO with a USB micro B cable

## Next Steps
Want to take things a step further? Here's a few ideas:
* Modify the code to use different time steps, e.g. {seconds, minutes, hours, days}
* Rewrite the code to turn it into weather display that shows the temperature and indicates {sunny, partly cloudy, cloudy, rain}
* Design and 3D print a back cover
