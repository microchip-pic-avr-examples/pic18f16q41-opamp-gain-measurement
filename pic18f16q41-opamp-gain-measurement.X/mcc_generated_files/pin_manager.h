/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.0
        Device            :  PIC18F16Q41
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.10 and above
        MPLAB 	          :  MPLAB X 5.35	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set INDICATION_LED aliases
#define INDICATION_LED_TRIS                 TRISAbits.TRISA2
#define INDICATION_LED_LAT                  LATAbits.LATA2
#define INDICATION_LED_PORT                 PORTAbits.RA2
#define INDICATION_LED_WPU                  WPUAbits.WPUA2
#define INDICATION_LED_OD                   ODCONAbits.ODCA2
#define INDICATION_LED_ANS                  ANSELAbits.ANSELA2
#define INDICATION_LED_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define INDICATION_LED_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define INDICATION_LED_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define INDICATION_LED_GetValue()           PORTAbits.RA2
#define INDICATION_LED_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define INDICATION_LED_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define INDICATION_LED_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define INDICATION_LED_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define INDICATION_LED_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define INDICATION_LED_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define INDICATION_LED_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define INDICATION_LED_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set RA4 procedures
#define RA4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define RA4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define RA4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define RA4_GetValue()              PORTAbits.RA4
#define RA4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define RA4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define RA4_SetPullup()             do { WPUAbits.WPUA4 = 1; } while(0)
#define RA4_ResetPullup()           do { WPUAbits.WPUA4 = 0; } while(0)
#define RA4_SetAnalogMode()         do { ANSELAbits.ANSELA4 = 1; } while(0)
#define RA4_SetDigitalMode()        do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set TIMING_LED aliases
#define TIMING_LED_TRIS                 TRISAbits.TRISA5
#define TIMING_LED_LAT                  LATAbits.LATA5
#define TIMING_LED_PORT                 PORTAbits.RA5
#define TIMING_LED_WPU                  WPUAbits.WPUA5
#define TIMING_LED_OD                   ODCONAbits.ODCA5
#define TIMING_LED_ANS                  ANSELAbits.ANSELA5
#define TIMING_LED_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define TIMING_LED_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define TIMING_LED_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define TIMING_LED_GetValue()           PORTAbits.RA5
#define TIMING_LED_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define TIMING_LED_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define TIMING_LED_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define TIMING_LED_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define TIMING_LED_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define TIMING_LED_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define TIMING_LED_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define TIMING_LED_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set RB7 procedures
#define RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define RB7_GetValue()              PORTBbits.RB7
#define RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define RB7_SetPullup()             do { WPUBbits.WPUB7 = 1; } while(0)
#define RB7_ResetPullup()           do { WPUBbits.WPUB7 = 0; } while(0)
#define RB7_SetAnalogMode()         do { ANSELBbits.ANSELB7 = 1; } while(0)
#define RB7_SetDigitalMode()        do { ANSELBbits.ANSELB7 = 0; } while(0)

// get/set channel_ANC2 aliases
#define channel_ANC2_TRIS                 TRISCbits.TRISC2
#define channel_ANC2_LAT                  LATCbits.LATC2
#define channel_ANC2_PORT                 PORTCbits.RC2
#define channel_ANC2_WPU                  WPUCbits.WPUC2
#define channel_ANC2_OD                   ODCONCbits.ODCC2
#define channel_ANC2_ANS                  ANSELCbits.ANSELC2
#define channel_ANC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define channel_ANC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define channel_ANC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define channel_ANC2_GetValue()           PORTCbits.RC2
#define channel_ANC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define channel_ANC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define channel_ANC2_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define channel_ANC2_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define channel_ANC2_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define channel_ANC2_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define channel_ANC2_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define channel_ANC2_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/