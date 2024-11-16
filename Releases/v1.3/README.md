# TIM-011B v1.3

16/11/2024

![Image of build version 1.3 board in green](https://github.com/Board-Folk/TIM011B/blob/main/images/tim011bv1_3_built_small.png)

## Version 1.3 BOM

There are 3 options for board power, P2, P5 or P7. Ceramic capacitors 5.08mm and resistors 1/4W.

See GAL folder for U2 GAL code. Tested on ATF16V8B-15PC.
See ROM folder for the binary of the updated ROM.
ROM and GAL by Marko Šolajić (@msolajic).

|Qty|Reference(s)|Value|Type|Notes|
|:--:|:--:|:--:|:--:|:--:|
|1|P1|5-7 pin header|Header|Video|
|1|P3|2x20 pin header|Dual Row 2.54mm Header|Expansion|
|1|P4|2x17 pin header|Dual Row 2.54mm Header|Floppy|
|1|P2|Unknown Ei Niš 4 pin header|Header|Power|
|1|P5|3.96mm 4 pin header|3.96mm Header|Alt Power|
|1|P7|DC Barrel Jack||5V Power|
|1|P8|RCA Jack||Composite Output|
|46|C3,C8,C10-C53|100nF|Ceramic Capacitor||
|1|C2|1nF|Ceramic Capacitor||
|1|C4|10uF 16V|Axial or Radial||
|1|C5|2n2|Ceramic Capacitor||
|1|C6|470uF 25V|Axial or Radial||
|8|C54-C57, C58-C61|1uF 16V|Radial||
|1|CX1,CX2|330pF|Ceramic Capacitor||
|1|D1|1N4148|Diode||
|1|D1|3mm LED|LED||
|2|R1,R12|470R|Resistor||
|1|R10|1K5|Resistor||
|1|R11|5K1|Resistor||
|2|R13,R20|1K|Resistor||
|1|R14|220R|Resistor||
|1|R15|10K|Resistor||
|1|R16|68R|Resistor||
|5|R2-R5,R7|4K7|Resistor||
|1|R6|100R|Resistor||
|1|R8|56K|Resistor||
|1|R9|2K2|Resistor||
|2|RP1,RP2|4K7 SIP10 Bussed|Resistor Network||
|1|RP3|330R SIP10 Bussed|Resistor Network||
|1|Q1|BC557|Transistor||
|1|U17|HD64180|IC|CPU|
|1|U43|FDC9266|IC|Floppy Controller|
|2|U8,U9|MAX232|IC|Serial Line Driver/Receiver|
|1|U16|27xxx ROM|IC|System ROM|
|2|U60,U61|44256 DRAM|IC|System RAM|
|1|U30|43256 SRAM|IC|Video RAM|
|1|U2|GAL16V8|IC|Sync Logic|
|1|U1|74LS08|IC||
|2|U11,U12|74LS283|IC||
|2|U14,U44|74LS240|IC||
|1|U18|74LS20|IC||
|7|U19-U22,U26-U28|74LS157|IC||
|1|U23|74LS00|IC||
|1|U24|74LS04|IC||
|1|U29|74HC153|IC||
|2|U3,U13|74HC4040|IC||
|1|U31|74LS32|IC||
|1|U32|74LS139|IC||
|1|U33|74LS07|IC||
|1|U34|74LS06|IC||
|1|U35|74LS158|IC||
|5|U4-U6,U40,U41|74LS374|IC||
|1|U42|74LS244|IC||
|4|U7,U10,U15,U25|74LS74|IC||
|1|T1|Unknown Reset Switch|Switch|T1 or T2|
|1|T2|RA Momentary Switch|Switch||
|1|J1|DB25 Female Right Angle|Socket|Printer|
|1|J3|5 pin DIN|Socket|180 degree / ASCII Keyboard|
|2|J4,J5|4 pin header|2.54mm Header|Alt TTL Serial|
|1|J6|DB9 Male Right Angle|Socket|Serial|
|1|JMP1,JMP3,JMP5-8|3 pin header|2.54mm Header||
|1|JMP2|5 pin header|2.54mm Header||
|1|JMP4|2 pin header|2.54mm Header|Fix Ready/Disk Change|
|1|X1|12.288MHz TTL Osc Can (DIP8)|Oscillator||
|1|X2|8MHz TTL Osc Can (DIP8)|Oscillator||
