# TIM-011B

An updated remake of the TIM-011 computer from Serbia.

![Computer rendered image of board in green](https://github.com/Board-Folk/TIM011B/blob/main/images/TIM-011Bv1_render.png)

This repository contains the BOM, gerbers and Kicad files for a remake of the TIM-011 from the Mihajlo Pupin Institute of Serbia, 1987.

This is as a base point - we're trying not to deviate from the original board too much so it can still be considered a replica. Feel free to fork and make your own mods outside of that. Folder Expansions will contain add on extensions to the board.

## Revisions

  * Version 1 Initial Release
  
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

# Version 1.1

* C42 silkscreen
* Fix J4 and J5 connections
* Silkscreen updates
* ROM A13 to GND
* Increase DB25 mounting point radius to 1.6mm
* Remove hole under C4
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
|5|R2,R3,R4,R5,R7|4K7|Resistor||
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
|7|U19,U20,U21,U22,U26,U27,U28|74LS157|IC||
|1|U35|74LS158|IC||
|1|U18|74LS20|IC||
|2|U14,U44|74LS240|IC||
|1|U42|74LS244|IC||
|2|U11,U12|74LS283|IC||
|1|U31|74LS32|IC||
|5|U4,U5,U6,U40,U41|74LS374|IC||
|4|U7,U10,U15,U25|74LS74|IC||
|1|U16|27C128|IC||
|8|U36,U37,U38,U39,U45,U46,U47,U48|41256 DRAM|IC||
|1|U30|43256 SRAM|IC||
|1|T1|Unknown Reset Switch|Switch|T1 or T2|
|1|T2|RA Momentary Switch|Switch||
|1|J1|DB25 Male Right Angle|Socket||
|1|J2|DB25 Female Right Angle|Socket||
|1|J3|5 pin DIN|Socket|180 degree?|
|2|J4,J5|4 pin header|Header||
|1|JMP1|3 pin header|Header||
|1|JMP2|5 pin header|Header||
|1|JMP3|3 pin header|Header||
|1|JMP4|2 pin header|Header||
|1|P1|5 pin header|Header||
|1|P3|2x20 pin header|Dual Row Header||
|1|P4|2x17 pin header|Dual Row Header||
|1|P2|Unknown 4 pin header|Header||
|1|P3|3.96mm 4 pin header|Header||
|1|Y1|12.288Mhz HC-49U|Crystal||
|1|Y2|8.00Mhz HC-49U|Crystal||

## Credits

PCB Layout by Rob Taylor @peepouk. Schematics recreated and modifications by Ian Cudlip @grandoldian. Special thanks to @demerzel, your schematics have helped and saved time.

## Thanks

* Zoltan Pekic
* Marko Šolajić
* @demerzel
* (OTHERS!)
* The Board Folk Team

## Legal

As the product of this project is a replica of a proprietary product, the the author makes no claim of copyright to the schematics nor PCB layouts and releases these into the public domain, solely for the purposes of study and historical preservation.

You are free to produce PCBs based on this project's designs at your own risk and without limitation, for your own use or for sale and/or repair at a reasonable price. Attribution is appreciated. The authors are not obliged to provide support of any kind. 

Under no circumstances will the authors be held responsible or liable in any way for losses, damages or costs resulting from the use of the information and/or resources of this project. 

The resources are provided "as-is" without warranty of any kind, either expressed or implied, including, but not limited to, the implied warranties of merchantability and fitness for a particular purpose.
