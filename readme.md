<!-- Please do not change this html logo with link -->
<a href="https://www.microchip.com" rel="nofollow"><img src="images/microchip.png" alt="MCHP" width="300"/></a>

# Gain measurement of the OPA module on PIC18F16Q41
This code example measures the gain of the Operational Amplifier (OPA) module on the PIC18F16Q41. Internally, this project uses the ADCC on the device to sample both the input and the output, and then computes the gain using either fixed point or floating point numbers.

## Related Documentation

<a href="https://www.microchip.com/wwwproducts/en/PIC18F16Q41">PIC18F16Q41 Product Information</a><br>
TBxxxx, "Using Operational Amplifiers in PIC16 and PIC18"<br>

## Software Used

* <a href="http://www.microchip.com/mplab/mplab-x-ide">MPLAB® IDE 5.40 or newer</a>
* <a href="https://www.microchip.com/mplab/compilers">Microchip XC8 Compiler 2.20 or newer</a>
* <a href="https://www.microchip.com/mplab/mplab-code-configurator">MPLAB® Code Configurator (MCC) 3.95.0 or newer</a>
* Serial Terminal

## Hardware Used

* <a href="https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/DM164137"> Microchip Curiosity Development Board (DM164137) </a>
* Power Supply or Potentiometer
  * RC0 on the Curiosity board can be used with a wire from RC0 to RB5.

## Setup
#### External Pins

| Pin | Name     | Description
| --- | -------- | -----------
| RB7 | UART TX  | UART TX (9600 BAUD)
| RB5 | OPA1IN0+ | Input to the OPA module (1).
| RC2 | OPA1OUT  | Output of the operational amplifier

Note:
1. RB5 is used so that the output is equal to gain x input. Input should be < 300mV to properly calculate the 16x range.

#### Curiosity Board Parts

| Pin | Function
| --- | --------
| RA2 | LED D6 - Measuring indicator LED
| RA5 | LED D4 - Timing Indicator (1)
| RC0 | *(if used)* Potentiometer on the Curiosity board

#### Additional Pins

| Pin | Function
| --- | --------
| TX | Curiosity board UART transmit pin. Connect to RB7

**Note**<br>
1. This pin is used as a tool to show that floating points are much slower than fixed point operations. LED is on when division is occurring. Integrate the active time of the waveform to find the difference in time.

## Operation
Out of the box, this program does automatic gain switching to demonstrate the measurements. Every time the program prints the current gain, it changes the gain.

The order of the gains is 1 (Unity Gain), 16/15, 8/7, 4/3 , 2, 8/3, 4, 8, and then 16.

During conversion and printing, LED D6 is on. It should appear as a brief blink every 10 seconds.
The gain calculated is printed through the UART at 9600 baud.

The program can be run in fixed point or floating point mode - in fixed point, resolution is limited is limited to +- 0.0625, but the code is much faster and much smaller. In floating point mode, resolution is much better, but the program is much bigger and slower.

The default configuration is floating point mode.

<img src="images/FloatingPoint.PNG" alt="Floating Point Output"><br>
*Figure 1 - Floating Point Measurement*

<img src="images/FixedPoint.PNG" alt="Fixed Point Output"><br>
*Figure 2 - Fixed Point Measurement*


### Program Defines
There are 2 define statements in this example which can be used to change the behavior of the code example. Both define statements are present in the file "OPAconfig.h".

- **ENABLE_CHANGING_GAIN**
  - This option disables the gain switching demo on the code example. For correct operation, this option **must be disabled** when using external resistors (1). Gain measurement limit is 999.

- **ENABLE_FLOATING_PT**
  - This option selects the use of floating points for gain calculation, rather than fixed point numbers. Enabling this option provides an increase in the accuracy of the gain measurement, however it significantly increases code size and computation time.

**Note:**
  1. To use external gain resistors, a reconfiguration of the OPA module in MCC is required.

### Analog Troubleshooting
#### Incorrect Gains
This program is dependent on RB5's input to determine the gain of the operational amplifier. For proper operation, RB5 should be <300mV to ensure proper operation for the internal gain of 16. User defined gains may have different requirements.

If a source or potentiometer is unavailable, one of the DACs can be repurposed as a substitute for RB5's input.

For further verification, RC2 is always the output of the OPA module if the module is enabled and running. The output should be 1 step above the last printed statement (ex: if gain was estimated around 2, the current gain should be 4).

## Summary
This example shows the programmable gain functionality of the OPA module, and then measures the gain of the amplifier.

<!-- Summarize what the example has shown -->
