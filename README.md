# TIM-011B

An updated remake of the TIM-011 computer from Serbia.

![Image of build version 1.3 board in black](https://github.com/Board-Folk/TIM011B/blob/main/images/tim011bv1_3_built_small.png)

This repository contains the BOM, gerbers and Kicad files for a remake of the TIM-011 from the Mihajlo Pupin Institute of Serbia, 1987.

** Currently Being Updated **

Version 1.1 does not deviate from the original board too much so it can still be considered a replica.

Version 1.2 includes 5V only operation, but due to stability issues this has not been published.

Version 1.3 contains improvements including composite video output, updated oscilators and stability fixes and uses a GAL for video sync signals. The initial version of this GAL is incompatible with the original screen, a modified version may be added in the future.

Feel free to fork and make your own mods outside of this repository. Folder Extensions contains add on expansions and adapters for the board. More will follow over time.

The work-in-progress version of the board has been removed from this project. If you're looking to make one, pick the latest version from the Releases folder.

Projects are in Kicad 8.

## Using the board

### Power

Version 1.1, as the original board requires 5V, 12V and -12V power. Power connectors on the board are the original Ei Niš connector P2, but due to the lack of availability of this part we've added P5, a standard 4 pin 3.96mm pin header to the rear of the board. 

Version 1.3 has a centre positive DC barrel jack for only 5V operation also.

### Video

Video original output is not standard, conversion is needed for use on a modern display. We will be posting options for this in the extensions folder. As a technical note, video is provided as 2 TTL signals to provide 4 shades, with a relatively wide horizonal and vertical sync for the original CRT. The horizontal sync is in an awkward position and is more simlar to horizonal drive found on comparible systems with a simple in-build CRT display.

Version 1.3 adds a composite video output for use on standard monitors.

### Keyboard

The keyboard is serial ASCII, 9600 8E1 with a 12V power output on the 5 pin DIN header. Version 1.3 adds the option to switch this to 5V operation. Adapter boards will be added to the extensions folder for this also including modules for v1.3 to contain keyboard conversion within the board footprint.

No operating system is included within the ROM - it needs to boot this from floppy disk or equivalent Gotek or Flash Floppy device. Marko's updated ROM for v1.3, which is backwards compatable adds diagnotics and support to boot from CF cards with the 8 bit CF/IDE expansion board and adapter.

More information to follow.

## TIM011 Resources

Marko Šolajić has put a great page together with a ROM, boot disks, software and other resources to help get the TIM-011 going. Highly recommended. The standard "sys", system ROM is 8KB, this will fit on the currently still manufactured and widely available AT28C64B.

  [TIM011 Resources](https://blog.8bitchip.info/tim011-resources/)

## Revisions

* Version 1.1 Initial Public Release
* Version 1.2 Unreleased
* Version 1.3 Current Release
  
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

## Version 1.2

* 5V Only operation - added DC barrel jack
* Ceramic caps changed to 5.08mm
* Updated silkscreen
* JMP5 5V/12V keyboard selection
* A13,A14,A15 ROM options
* JMP8 No Video jumper
* Change serial to MAX232 (5V)
* RAM change to 44256
* "Half-can" Oscillators for X1 and X2
* JMP9 12V Power selection for expansion bus pin 40
* JMP10 VSYNC selection
* Grounding point
* Support for keyboard modules

## Version 1.3

* Replaced U2 74LS08 with GAL16V8
* Sync signals negative with standard GAL
* Change serial port to 9 pin
* Oscillators now buffered
* R8 reset pullup
* Composite video output

## Links

   [Marko's Blog Post on the TIM 011](https://blog.8bitchip.info/482-tim-011-a-new-life-for-an-old-computer/)

## Credits

PCB Layout by Rob Taylor @peepouk, Ian Cudlip @grandoldian and Marko Šolajić @msolajic. Schematics recreated and modifications by Ian Cudlip and Marko Šolajić. Special thanks to @demerzel, your schematics have helped and saved time.

## Thanks

* Zoltan Pekic
* @demerzel
* The Board Folk Team

## Legal

As the product of this project is a replica of a proprietary product, the the author makes no claim of copyright to the schematics nor PCB layouts and releases these into the public domain, solely for the purposes of study and historical preservation.

You are free to produce PCBs based on this project's designs at your own risk and without limitation, for your own use or for sale and/or repair at a reasonable price. Attribution is appreciated. The authors are not obliged to provide support of any kind. 

Under no circumstances will the authors be held responsible or liable in any way for losses, damages or costs resulting from the use of the information and/or resources of this project. 

The resources are provided "as-is" without warranty of any kind, either expressed or implied, including, but not limited to, the implied warranties of merchantability and fitness for a particular purpose.
