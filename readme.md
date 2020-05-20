<!-- Please do not change this html logo with link -->
<a href="https://www.microchip.com" rel="nofollow"><img src="images/microchip.png" alt="MCHP" width="300"/></a>

# Gain measurement of the OPA module on PIC18F16Q41
This code example measures the gain of the Operational Amplifier (OPA) module on the Q41. To do so, the module utilizes the ADCC with a reference of Vdd and Vss.

<!-- This is where the introduction to the example goes, including mentioning the peripherals used -->

## Related Documentation

<a href="https://www.microchip.com/wwwproducts/en/PIC18F16Q41">PIC18F16Q41 Product Information</a>

<!-- Any information about an application note or tech brief can be linked here. Use unbreakable links!
     In addition a link to the device family landing page and relevant peripheral pages as well:
     - [AN3381 - Brushless DC Fan Speed Control Using Temperature Input and Tachometer Feedback](https://microchip.com/00003381/)
     - [PIC18F-Q10 Family Product Page](https://www.microchip.com/design-centers/8-bit/pic-mcus/device-selection/pic18f-q10-product-family) -->

## Software Used

* <a href="http://www.microchip.com/mplab/mplab-x-ide">MPLAB® IDE 5.40 or newer</a>
* <a href="https://www.microchip.com/mplab/compilers">Microchip XC8 Compiler 2.20 or newer</a>
* <a href="https://www.microchip.com/mplab/mplab-code-configurator">MPLAB® Code Configurator (MCC) 3.95.0 or newer</a>
* Serial Terminal

<!-- All software used in this example must be listed here. Use unbreakable links!
     - MPLAB® X IDE 5.30 or newer [(microchip.com/mplab/mplab-x-ide)](http://www.microchip.com/mplab/mplab-x-ide)
     - MPLAB® XC8 2.10 or a newer compiler [(microchip.com/mplab/compilers)](http://www.microchip.com/mplab/compilers)
     - MPLAB® Code Configurator (MCC) 3.95.0 or newer [(microchip.com/mplab/mplab-code-configurator)](https://www.microchip.com/mplab/mplab-code-configurator)
     - MPLAB® Code Configurator (MCC) Device Libraries PIC10 / PIC12 / PIC16 / PIC18 MCUs [(microchip.com/mplab/mplab-code-configurator)](https://www.microchip.com/mplab/mplab-code-configurator)
     - Microchip PIC18F-Q Series Device Support (1.4.109) or newer [(packs.download.microchip.com/)](https://packs.download.microchip.com/) -->

## Hardware Used

* <a href="https://www.microchip.com/Developmenttools/ProductDetails/ADM00393">MCP2200 USB-UART Evaluation Board (ADM00393)</a>
    * Baud Rate is 9600 for this example
* <a href="https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/DM164137"> Microchip Curiosity Development Board (DM164137) </a>
* Power Supply or Potentiometer
  * RC0 on the Curiosity board can be used with a wire from RC0 to RB5.

## Setup

#### External Pins

| Pin | Name     | Description
| --- | -------- | -----------
| RC2 | OPA1OUT  | Output of the operational amplifier
| RB7 | UART TX  | UART TX
| RB5 | OPA1IN0+ | Input to the OPA module (1).

Note:
1. RB5 is used so that the output is equal to gain x input. Input should be < 300mV to properly calculate the 16x range.

#### Curiosity Board Pins

| Pin | Function
| --- | --------
| RA2 | LED D6 - Measuring indicator LED
| RC0 | *(if used)* Potentiometer on the Curiosity board


## Operation
Out of the box, this program does automatic gain switching to demonstrate the measurements. Every time the program prints the current gain, it changes the gain.

The order of the gains is 1 (Unity Gain), 16/15, 8/7, 4/3 , 2, 8/3, 4, 8, and then 16.

During conversion and printing, LED D6 is on. It should appear as a brief blink every 10 seconds.
The gain calculated is printed through the UART at 9600 baud.

The program can be run in fixed point or floating point mode - in fixed point, resolution is limited is limited to +- 1/16, but the program is faster and much smaller. In floating point mode, resolution is much better, but the program is much bigger and slower. The default configuration is floating point mode.

<img src="images/GainMeasurement_FloatingPoint.png" alt="Output - Floating Point">

*Figure 1 - Floating Point Measurement*

<img src="images/GainMeasurement_FixedPoint.png" alt="Output - Fixed Point">

*Figure 2 - Fixed Point Measurement*


### Program Defines
There are 2 define statements in this example which can be used to change the behavior of the code example. Both define statements are present in the file "OPAconfig.h".

- **ENABLE_CHANGING_GAIN**
  - This option disables the gain switching demo on the code example. For correct operation, this option **must be disabled** when using external resistors. Gain measurement limit is 999.

- **ENABLE_FLOATING_PT**
  - This option selects the use of floating points for gain calculation, rather than fixed point numbers. Enabling this option provides an increase in the accuracy of the gain measurement, however it significantly increases code size and computation time.

### Analog Troubleshooting
#### Incorrect Gains
This program is dependent on RB5's input to determine the gain of the operational amplifier. For proper operation, RB5 should be <300mV to ensure proper operation. If a source or potentiometer is unavailable, one of the DACs can be repurposed as a substitute for RB5's input.

For further verification, RC2 is always the output of the OPA module if the module is enabled and running. The output should be 1 step above the last printed statement (ex: if gain was estimated around 2, the current gain should be 4).

## Summary
This example shows the programmable gain functionality of the OPA module, and then measures the gain of the amplifier.

<!-- Summarize what the example has shown -->
