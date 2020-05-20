/* 
 * File:   OPAsetup.h
 * Author: C62081
 *
 * Created on May 11, 2020, 8:57 AM
 */

#ifndef OPASETUP_H
#define	OPASETUP_H

#ifdef	__cplusplus
extern "C" {
#endif
    
    /** Macros (equiv. to functions below) */
    
#define CLEAR_OPA_CONFIG OPA1CON0 = 0x00; OPA1CON1 = 0x00; OPA1CON2 = 0x00; OPA1CON3 = 0x00; OPA1HWC = 0x00; OPA1ORS = 0x00

    /** Sets the OPA Module in Unity Gain using the internal switch */
#define SET_OPA_UNITY_GAIN CLEAR_OPA_CONFIG; OPA1CON1 = 0x00; OPA1CON2 = 0x02; OPA1CON3 = 0x02; OPA1HWC = 0x00; OPA1ORS = 0x00; OPA1CON0 = 0x88

    /** Sets the OPA Module into a non-inverting amplifier with gain*/
#define SET_OPA_NON_INVERT(GAIN) CLEAR_OPA_CONFIG; OPA1CON1 = 0x3F; OPA1CON2 = 0x12; OPA1CON3 = 0x82; OPA1HWC = 0x00; OPA1ORS = 0x00; OPA1CON1bits.GSEL = GAIN; OPA1CON0 = 0x80

    /** Sets the OPA Module into a inverting amplifier with gain*/
#define SET_OPA_INVERT(GAIN) CLEAR_OPA_CONFIG; OPA1CON1 = 0x3A; OPA1CON2 = 0x13; OPA1CON3 = 0x80; OPA1HWC = 0x00; OPA1ORS = 0x00; OPA1CON1bits.GSEL = GAIN; OPA1CON0 = 0x80;
    
    /** Sets the OPA Module to use the I/O pins for configuration*/
#define SET_OPA_EXT_SETUP   CLEAR_OPA_CONFIG; OPA1CON1 = 0x00; OPA1CON2 = 0x22; OPA1CON3 = 0x00; OPA1HWC = 0x00; OPA1ORS = 0x00; OPA1CON0 = 0x80

//Set the gain
#define SET_GAIN(X) OPA1CON1bits.GSEL = X;
            
    /** Enumeration for setupOPA */
    typedef enum { UNITY_GAIN = 0, NON_INVERTING,
            INVERTING, CUSTOM_SETUP} OPA_CONFIG;
    
    /** Selects the configuration function from an input.
     * Non-Inverting Defaults: Gain = 2
     * Inverting Defaults: Gain = -1, Vdd/2 = Vbias
     *  */
    void setupOPA(OPA_CONFIG setup);
    
    /** Clears all registers in the OPA module */
    void clearOPAconfig(void);
        
    /** Sets the OPA module into Unity Gain */
    void configureOPA_UnityGain(void);
    
    /** Sets the OPA module as a non-inverting amplifier */
    void configureOPA_NonInverting(uint8_t gain);
    
    /** Sets the OPA module as an inverting amplifier */
    void configureOPA_Inverting(uint8_t gain);
    
    /** Sets the OPA module to use external parts */
    void configureOPA_External(void);

#ifdef	__cplusplus
}
#endif

#endif	/* OPASETUP_H */

