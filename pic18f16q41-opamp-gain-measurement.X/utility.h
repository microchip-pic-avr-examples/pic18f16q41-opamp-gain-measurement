/* 
 * File:   utility.h
 * Author: C62081
 *
 * Created on February 26, 2020, 8:58 AM
 */

#ifndef CALIBRATION_H
#define	CALIBRATION_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stdint.h>

    //Transmits a string through the UART
    void sendString(const char* str, uint8_t sendEOL);
    void sendStringSafe(const char* str, int size);
    
    //Transmits a string w/ an (ASCII converted) value of the register
    void printRegisterLine(const char* str, uint8_t rg);
    void printRegisterLineLarge(const char* str, uint16_t rg);
    
    //Sends just the (ASCII converted) value of the register
    void sendLargeHexValue(uint16_t value);
    void sendHexValue(uint8_t value);
        
//End of line transmission macro    
#define END_OF_LINE     sendStringSafe("\n\r", 2)
    
#ifdef	__cplusplus
}
#endif

#endif	/* CALIBRATION_H */

