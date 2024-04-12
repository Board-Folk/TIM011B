# TIM-011B

An updated remake of the TIM-011 computer from Serbia.

![Image of build version 1 board in green](https://github.com/Board-Folk/TIM011B/blob/main/images/tim011bv1_built_small.png)

This repository contains the BOM, gerbers and Kicad files for a remake of the TIM-011 from the Mihajlo Pupin Institute of Serbia, 1987.

Version 1.1 does not to deviate from the original board too much so it can still be considered a replica. Feel free to fork and make your own mods outside of that. Future releases will contain improvements to this. Folder Extensions contains add on expansions and adapters for the board. More will follow over time.

The root Kicad folder contains the current work-in-progress version of the board. If you're looking to make one, don't use this, pick the latest version from the Releases folder, currently v1.1.

Projects are in Kicad 8.

## Using the board

The board requires 5V, 12V and -12V power. Power connectors on the board are the original Ei Niš connector P2, but due to the lack of availability of this part we've added P5, a standard 4 pin 3.96mm pin header to the rear of the board. 

Video output is not standard, conversion is needed for use on a modern display. We will be posting options for this in the extensions folder. As a technical note, video is provided as 2 TTL signals to provide 4 shades, with a relatively wide horizonal and vertical sync for the original CRT. The horizontal sync is in an awkward position and is more simlar to horizonal drive found on comparible systems with a simple in-build CRT display.

The keyboard is serial ASCII, 9600 8E1 with a 12V power output on the 5 pin DIN header. Adapter boards will be added to the extensions folder for this also.

No operating system is included within the ROM - it needs to boot this from floppy disk or equivalent Gotek or Flash Floppy device.

More information to follow.

## TIM011 Resources

Marko Šolajić has put a great page together with a ROM, boot disks, software and other resources to help get the TIM-011 going. Highly recommended. The standard "sys", system ROM is 8KB, this will fit on the currently still manufactured and widely available AT28C64B.

  [TIM011 Resources](https://blog.8bitchip.info/tim011-resources/)

## Revisions

* Version 1.1 Initial Public Release
  
## Version 1 Modifications from Original

* Fixed VSYNC Buffer
* Fix Strobe Pullup
* CX timing fix capacitor
* P5 3.96mm right angle power pin header 
* XT Keyboard INT0/SCROLL fix modification with JMP3 selection on/off
* Right angle reset momentatary switch within T1 footprint
* Modernise J3 keyboard connector footprint
* J4 and J5 serial pin headers for alternative serial connections
* Added mounting holes
* Power LED

## Version 1.1

* C42 silkscreen
* Fix J4 and J5 connections
* Silkscreen updates
* ROM A13 to GND
* Increase DB25 mounting point radius to 1.6mm
* Add JMP4 drive Ready/Disk Change modification

## Version 1.1 BOM

|Qty|Reference(s)|Value|Type|Notes|
|:--:|:--:|:--:|:--:|:--:|
|47|C3,C8-C53|100nF 7.5mm|Ceramic Capacitor||
|1|C2|1nF 7.5mm|Ceramic Capacitor||
|1|C5|2.2nF 7.5mm|Ceramic Capacitor||
|2|C6,C7|470pF 7.5mm|Ceramic Capacitor||
|1|CX1|330pF 7.5mm|Ceramic Capacitor||
|1|C1|22uF 25V|Electrolytic Capacitor|Axial or Radial|
|1|C4|10uF|Electrolytic Capacitor|Axial or Radial|
|1|D1|1N4148|Diode||
|2|R1,R12|470R|Resistor||
|5|R2-R5,R7|4K7|Resistor||
|1|R6|100R|Resistor||
|4|R8,R10,R13,R15|330R|Resistor||
|4|R9,R11,R14,R16|1K|Resistor||
|2|RP1,RP2|4K7 SIP10 Bussed|Resistor Network||
|1|RP3|330R SIP10 Bussed|Resistor Network||
|1|U17|HD64180|IC||
|1|U43|FDC9266|IC||
|1|U9|MC1488|IC||
|1|U8|MC1489|IC||
|1|U29|74HC153|IC||
|2|U3,U13|74HC4040|IC||
|1|U23|74LS00|IC||
|1|U24|74LS04|IC||
|1|U34|74LS06|IC||
|1|U33|74LS07|IC||
|2|U1,U2|74LS08|IC||
|1|U32|74LS139|IC||
|7|U19-U22,U26-U28|74LS157|IC||
|1|U35|74LS158|IC||
|1|U18|74LS20|IC||
|2|U14,U44|74LS240|IC||
|1|U42|74LS244|IC||
|2|U11,U12|74LS283|IC||
|1|U31|74LS32|IC||
|5|U4-U6,U40,U41|74LS374|IC||
|4|U7,U10,U15,U25|74LS74|IC||
|1|U16|27C128|IC||
|8|U36-U39,U45-U48|41256 DRAM|IC||
|1|U30|43256 SRAM|IC||
|1|T1|Unknown Reset Switch|Switch|T1 or T2|
|1|T2|RA Momentary Switch|Switch||
|1|J1|DB25 Male Right Angle|Socket|Printer|
|1|J2|DB25 Female Right Angle|Socket|Serial|
|1|J3|5 pin DIN|Socket|180 degree / ASCII Keyboard|
|2|J4,J5|4 pin header|2.54mm Header|Alt TTL Serial|
|1|JMP1|3 pin header|2.54mm Header||
|1|JMP2|5 pin header|2.54mm Header||
|1|JMP3|3 pin header|2.54mm Header|XT keyboard mod enable|
|1|JMP4|2 pin header|2.54mm Header|Fix Ready/Disk Change|
|1|P1|5 pin header|Header|Video|
|1|P3|2x20 pin header|Dual Row 2.54mm Header|Expansion|
|1|P4|2x17 pin header|Dual Row 2.54mm Header|Floppy|
|1|P2|Unknown Ei Niš 4 pin header|Header|Power|
|1|P5|3.96mm 4 pin header|3.96mm Header|Alt Power|
|1|Y1|12.288Mhz HC-49U|Crystal||
|1|Y2|8.00Mhz HC-49U|Crystal||

## Credits

PCB Layout by Rob Taylor @peepouk. Schematics recreated and modifications by Ian Cudlip @grandoldian. Special thanks to @demerzel, your schematics have helped and saved time.

## Thanks

* Zoltan Pekic
* Marko Šolajić
* @demerzel
* OTHERS! We need to fully credit sources of information for this project.
* The Board Folk Team

## Legal

As the product of this project is a replica of a proprietary product, the the author makes no claim of copyright to the schematics nor PCB layouts and releases these into the public domain, solely for the purposes of study and historical preservation.

You are free to produce PCBs based on this project's designs at your own risk and without limitation, for your own use or for sale and/or repair at a reasonable price. Attribution is appreciated. The authors are not obliged to provide support of any kind. 

Under no circumstances will the authors be held responsible or liable in any way for losses, damages or costs resulting from the use of the information and/or resources of this project. 

The resources are provided "as-is" without warranty of any kind, either expressed or implied, including, but not limited to, the implied warranties of merchantability and fitness for a particular purpose.
