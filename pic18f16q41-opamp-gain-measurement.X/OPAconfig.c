#include "OPAconfig.h"
#include "./mcc_generated_files/mcc.h"

#include <xc.h>
#include <stdio.h>

const char* decStrings4[] = {".0", ".06125" ,".125", ".1875", ".25", 
".3125", ".375", ".4375", ".5", ".5625", ".675", ".6875", ".75", ".8125",
".875", ".9375"};

//Internal Function - Not for other files
//Returns the remainder, and subtracts from the numerator during the division.
uint16_t inline fastDivide(uint16_t* numer, uint16_t divisor)
{
    uint16_t count = 0;
    while (*numer >= divisor)
    {
        *numer -= divisor;
        count++;
    }
    return count;
}

//Internal Function
//Call this function to see the raw value of input and output
void debugOutput(uint16_t signalIn, uint16_t signalOut)
{
    printRegisterLineLarge("Signal In Value: 0x", signalIn);
    printRegisterLineLarge("Signal Out Value: 0x", signalOut);
}

void calculateGain_fixedPT(uint16_t in, uint16_t out)
{
    sendString("Estimated gain: ", 0);
    //Print the Whole Number
    uint16_t wholeNumber = 0, decimalCode = 0;
    
    //If in == 0, then exit.
    if (in == 0)
    {
        sendString("NaN", 1);
        return;
    }
    
    //This is the whole number gain.
    wholeNumber = fastDivide(&out, in);
    
    //Digit to print
    char num;

    //Decimals to print
    if (wholeNumber >= 100)
    {
        //100's place
        num = '0' + fastDivide(&wholeNumber, 100);
        sendStringSafe(&num, 1);
        
        //Always show the 10's place
        num = '0' + fastDivide(&wholeNumber, 10);
        sendStringSafe(&num, 1);
    }
    else if (wholeNumber >= 10)
    {
        //10's place
        num = '0' + fastDivide(&wholeNumber, 10);
        sendStringSafe(&num, 1);
    }
    
    //1's place
    num = '0' + wholeNumber;
    sendStringSafe(&num, 1);
    
    //If there is a remainder, try and find the decimal
    if (out != 0)
    {
        out = out << 4;
        decimalCode = fastDivide(&out, in);
        sendString(decStrings4[decimalCode], 1);
    }
    else
    {
        //Print /n/r
        END_OF_LINE;
    }
    
}

//Changes the gain of the OPA module using a simple state machine
void changeGain(void)
{
    //Starting on UG
    static char gain = 8;
    
    if (gain == 8)
    {
        //Re-add the resistors
        OPA1_SetNegativeChannel(OPA1_negChannel_GSEL);
        
        //Disable unity gain
        OPA1CON0bits.UG = 0;
    }
    
    gain++;
    
    if (gain == 8) 
    {
        //Isolate the resistors - it provides a small improvement
        OPA1_SetNegativeChannel(OPA1_negChannel_No_Connection);
        
        //Move to unity gain
        OPA1_EnableSoftwareUnityGain();
        return;
    }
    else if (gain == 9)
    {
        //Loop back to the correct gain
        gain = 0;
    }
    
    OPA1_SetResistorLadder((OPA1_resistor_select) gain);
}

void calculateGain_floatingPT(uint16_t in, uint16_t out)
{
    float gain = (float) out / in;
    printf("Estimated gain: %3.4f\n\r", gain);
}

//Returns the difference between the gains
void measureGain(void)
{
    uint32_t signalIn, signalOut;
    
    captureADC(channel_OPA1);
    signalIn = ADFLTR;

    //Capture the Output
    captureADC(0x8D);       //ADCC selects OPA1IN0+, and samples OPA1OUT
    signalOut = ADFLTR;
    
    //Print a warning if the ADC is at (or near) measurement limits
    //Other parts and voltages may require tuning
    if (signalOut >= 0x0FF0)
    {
        sendString("[WARNING] Signal is near or at measurement limits.", 1);
    }
    
    //Find and print the gain of the op-amp    
#ifdef ENABLE_FLOATING_PT
    calculateGain_floatingPT(signalIn, signalOut);
#else
    calculateGain_fixedPT(signalIn, signalOut);
#endif
    
    
#ifdef ENABLE_CHANGING_GAIN
    //For testing, go through the internal gains
    changeGain();
#endif
}

void captureADC(adcc_channel_t ch)
{
    //Finish any UART Sends before sleep
    while (!UART1_is_tx_done());
    
    ADCC_StartConversion(ch);
    Sleep();
}