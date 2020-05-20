/* 
 * File:   OPAconfig.h
 * Author: C62081
 *
 * Created on April 29, 2020, 1:53 PM
 */

#ifndef OPACONFIG_H
#define	OPACONFIG_H

#include <xc.h>
#include "utility.h"
#include "./mcc_generated_files/mcc.h"

#ifdef	__cplusplus
extern "C" {
#endif
    
/**If defined, enables a rotating gain demo using the internal ladder
 * If undefined, the program will not change the gain of the module.
 * */
#define ENABLE_CHANGING_GAIN
    
/** If set, ENABLE_FLOATING_PT uses floating points to calculate the gain
 *  which improves the resolution of the measurement at the cost of code size 
 *  and speed */
#define ENABLE_FLOATING_PT
    
    /** State machine to go through different gains */
    void changeGain(void);

    /** Acquire the raw input and output */
    void measureGain(void);
    
    /** Calculate the gain and output the result. Uses fiXed Point */
    void calculateGain_fixedPT(uint16_t in, uint16_t out);
    
    /** Calculate the gain and output the result. Uses floating point */
    void calculateGain_floatingPT(uint16_t in, uint16_t out);
    
    /** Capture the ADC - averages 32 samples
     * Part is in sleep during the conversion and will wake when complete */
    void captureADC(adcc_channel_t ch);

#ifdef	__cplusplus
}
#endif

#endif	/* OPACONFIG_H */

