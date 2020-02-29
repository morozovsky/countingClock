# countingClock
This repository contains complete code, MCAD, and EECAD for the Counting Clock project. The Counting Clock is an internet-connected thing that displays the amount of time until a specified date and time in the future, or from a specified date and time in the past. The amount of time is displayed in hours, days, weeks, or months, whatever is the smallest unit that fits on a two-digit display (e.g. 48 hours will be displayed instead of 2 days, 52 weeks will be displayed instead of 12 months, etc.). The internet connection is used only to get the current date and time. No data is uploaded from the device. You specify the date and time (and the WiFi login credentials) by downloading a program from your computer to a microcontroller in the device.

## Electrical Assembly Instructions
_Almost all of the parts are reverse-polarity sensitive, that is, __if you plug them in backwards, they can be damaged__. It's also important to install parts on the correct side of the board. See the pictures below for reference._

### Required Tools
* Soldering iron (25+ Watts)
* Solder (leaded is easy to work with than lead-free, but don't eat it)
* Snips (to trim excess wire leads)

<img src="https://github.com/morozovsky/countingClock/blob/master/Images/front.jpg" width="400"><img src="https://github.com/morozovsky/countingClock/blob/master/Images/back.jpg" width="400">

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

### Assembly
1. Solder the 4 green LEDs. The longer of the two leads goes into the round pad, insert them on the side of the board that has the letters H, D, W, M printed (Counting Clock side). Slide the part as far in as you can, although the green plastic will not be flush with the circuit board. Bend the leads apart so that the LEDs don't slide. After you solder, cut off the excess length of the leads.
1. Solder the 5 pin resister network. The dot next to the letter B indicates pin 1 and should go into the square pad on the side of the board that says R3 and has a rectangular outline (nickmo 2019 side).
1. Install the capacitors C1 and C2 on the nickmo 2019 side which has C1 and C2 labeled. For these components, the orientation doesn't matter. Like the LEDs, slide in the components as far as you can and bend the leads to prevent them from sliding out. After you solder, cut off the excess length of the leads.
1. Solder the two two-digit LED display, DS1, on the Counting Clock side of the board. Make sure to line up the decimal places to match the silkscreen printing.
1. Solder U4, the 14 pin integrated circuit (IC), to the nickmo 2019 side of the board. Make sure to align the U-shaped depression on the IC to the U-shaped mark on the silkscreen printing (next to the USB label). This part is not visible in the picture above because it is below the microcontroller.
1. Solder U1 and U2, 16 pin ICs, to the nickmo 2019 side of the board. These parts have the Texas-shaped Texas Instruments logo and the second line of text says "SN74HC595N," they are shorter in height to the other 16 pin ICs (next step). Make sure to align the U-shaped depression on the IC to the U-shaped mark on the silkscreen printing, the two parts have opposite orientations. 
1. Solder R1 and R2, 16 pin ICs, to the nickmo 2019 side of the board. Make sure to align the U-shaped depression on the IC to the U-shaped mark on the silkscreen printing, the two parts have opposite orientations. 
1. The remaining parts are the 10 pin headers to connect the microcontroller board (with the USB port) to the circuit board. Using male and female headers allows you to remove the microcontroller from the circuit board and use it for other projects too.
    1. The female headers (black enclosure with long gold pins) get soldered to the circuit board and the male headers (gold pins with a thin plastic spacer) get soldered to the microcontroller.
    1. Insert the long side of the male headers into the female headers.
    1. Insert the long pins of the female headers into the circuit board from the nickmo 2019 side, where J1 and J2 are labeled.
    1. Align the microcontroller onto the short side of the male headers, which should stick up through the microcontroller enough to solder to. Make sure the USB port of the microcontroller is next to the edge of the circuit board, above where "USB" is printed on silkscreen on the circuit board.
    1. Solder the male header pins (2 x 10 pins) to the microcontroller while making sure that the headers are perpendicular to both the microcontroller and the circuit board. I recommend doing the corner pins first to lock in the alignment.
    1. Solder the female header pins (2 x 10 pins) to the circuit board. Trim the excess length once you're done.
1. With a USB micro cable, plug the microcontroller into a powered USB port. You should see a few LEDs light up on the microcontroller (but not the ones on the circuit board, yet). If you see any magic smoke escape, reconsider the decisions you've made up to this point.
_There's a couple extra connectors in the bag, they are not needed. Do not eat them or the silica gel._

## Mechanical Assembly Instructions
1. Push the tabs in the case towards the edges of the case and slide in the circuit board, make sure to align the LED display and LEDs towards the openings (it will only fit one way).

## Software Instructions
1. Download and install the Arduino IDE from: https://www.arduino.cc/en/main/software
1. esp32 board definition https://github.com/espressif/arduino-esp32/blob/master/docs/arduino-ide/boards_manager.md
1. manage libraries: install Time, TinyPICO
1. Download the code from this GitHub repository to your computer.
1. Modify the values in constants.h to set the second, minute, hour, day, month, and year you want to count down to (or up from) and your WiFi network name (SSID) and password, both are case-sensitive.
1. Connect your computer to the microcontroller with a USB micro B cable.
1. Upload the program to the microcontroller.

## Next Steps
Want to take things a step further? Here's a few ideas:
* Modify the code to use different time steps, e.g. {seconds, minutes, hours, days}
* Rewrite the code to turn it into weather display that shows the temperature and indicates {sunny, partly cloudy, cloudy, rain}
* Design and 3D print a back cover
