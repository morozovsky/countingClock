# countingClock
Code, MCAD, and EECAD for Counting Clock Project

## Electrical Assembly Instructions
Almost all of the parts are reverse-polarity sensitive, that is, if you plug them in backwards, they can be damaged.

### Bill of Materials

Quantity | Reference Designator on PCB | Part Description | Manufacturer Part Number | Mouser.com Part Number
------------ | ------------- | ------------- | ------------- | -------------
2 | U1, U2 | Counter Shift Registers | SN74HC595N | [595-SN74HC595N](https://www.mouser.com/ProductDetail/595-SN74HC595N)
1 | U4 | Buffers & Line Drivers | SN74AHCT125N | [595-SN74AHCT125N](https://www.mouser.com/ProductDetail/595-SN74AHCT125N)
2 | R1, R2
1 | R3
2 | C1, C2
4 | D1, D2, D3, D4
1 | DS1
2 | J1, J2

## Mechanical Assembly Instructions

## Software Instructions
1. Download and install Arduino IDE from: https://www.arduino.cc/en/main/software
1. esp32 board definition https://github.com/espressif/arduino-esp32/blob/master/docs/arduino-ide/boards_manager.md
1. manage libraries: install Time, TinyPICO

## Next Steps
Want to take things a step further? Here's a few ideas:
* Modify the code to use different time steps, e.g. {seconds, minutes, hours, days}
* Rewrite the code to turn it into weather display that shows the temperature and indicates {sunny, partly cloudy, cloudy, rain}
* Design and 3D print a back cover
