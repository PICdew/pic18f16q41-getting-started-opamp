#ifndef OPASETUP_H
#define	OPASETUP_H

#ifdef	__cplusplus
extern "C" {
#endif
        
/** 
     * <B>clearOPAconfig</B>
     * 
     * Clears all registers in the OPA module.
     *  */
#define CLEAR_OPA_CONFIG do { OPA1CON0 = 0x00; OPA1CON1 = 0x00; OPA1CON2 = 0x00; OPA1CON3 = 0x00; OPA1HWC = 0x00; OPA1ORS = 0x00; } while(0)

    /** 
     * <B>SET_OPA_UNITY_GAIN</B>
     * 
     * Configures the OPA module as a unity gain buffer. 
     */
#define SET_OPA_UNITY_GAIN do { CLEAR_OPA_CONFIG; OPA1CON1 = 0x00; OPA1CON2 = 0x02; OPA1CON3 = 0x02; OPA1HWC = 0x00; OPA1ORS = 0x00; OPA1CON0 = 0x88; } while(0)

    /** <B>SET_OPA_NON_INVERT(GAIN)</B>
     * @param GAIN - resistor configuration
     * 
     * Configures the OPA module into a non-inverting amplifier using the internal resistor ladder.
     */
#define SET_OPA_NON_INVERT(GAIN) do { CLEAR_OPA_CONFIG; OPA1CON1 = 0x3F; OPA1CON2 = 0x12; OPA1CON3 = 0x82; OPA1HWC = 0x00; OPA1ORS = 0x00; OPA1CON1bits.GSEL = GAIN; OPA1CON0 = 0x80; } while(0)

    /** <B>SET_OPA_INVERT(GAIN)</B>
     * @param GAIN - resistor configuration
     * 
     * Configures the OPA module into an inverting amplifier using the internal resistor ladder.
     */
#define SET_OPA_INVERT(GAIN) do { CLEAR_OPA_CONFIG; OPA1CON1 = 0x3A; OPA1CON2 = 0x13; OPA1CON3 = 0x80; OPA1HWC = 0x00; OPA1ORS = 0x00; OPA1CON1bits.GSEL = GAIN; OPA1CON0 = 0x80; } while(0)
    
    /** <B>SET_OPA_EXT_SETUP</B>
     * 
     *  Sets the OPA Module to use the external components for configuration
     */
#define SET_OPA_EXT_SETUP   do{ CLEAR_OPA_CONFIG; OPA1CON1 = 0x00; OPA1CON2 = 0x22; OPA1CON3 = 0x00; OPA1HWC = 0x00; OPA1ORS = 0x00; OPA1CON0 = 0x80; } while(0)

/** <B>SET_OPA_NON_INVERT(GAIN)</B>
     * @param GAIN - resistor configuration 
     * 
     *  Sets the gain of the OPA module using the internal resistor ladder.
     */
#define SET_GAIN(GAIN) do { OPA1CON1bits.GSEL = GAIN; } while(0)
            
    /* Enumeration for setupOPA  */
    typedef enum { UNITY_GAIN = 0, NON_INVERTING,
            INVERTING, CUSTOM_SETUP} OPA_CONFIG;
    
    /** 
     * <B><FONT COLOR=BLUE>void</FONT> setupOPA(<FONT COLOR=BLUE>OPA_CONFIG</FONT> setup)</B>
     * @param setup (OPA_CONFIG) - selects which configuration to switch to.
     * 
     * 
     * Non-Inverting Defaults: Gain = 2
     * 
     * Inverting Defaults: Gain = -1, Vdd/2 = Vbias
     *  */
    void setupOPA(OPA_CONFIG setup);
    
    /** 
     * <B><FONT COLOR=BLUE>void</FONT> clearOPAconfig(<FONT COLOR=BLUE>void</FONT>)</B>
     * 
     * Clears all registers in the OPA module.
     *  */
    void clearOPAconfig(void);
        
    /** 
     * <B><FONT COLOR=BLUE>void</FONT> configureOPA_UnityGain(<FONT COLOR=BLUE>void</FONT>)</B>
     * 
     * Configures the OPA module as a unity gain buffer.
     *  */
    void configureOPA_UnityGain(void);
    
    /** 
     * <B><FONT COLOR=BLUE>void</FONT> configureOPA_NonInverting(<FONT COLOR=BLUE>uint8_t</FONT> gain)</B>
     * @param gain (uint8_t) - resistor configuration 
     * 
     * Configures the OPA module into a non-inverting amplifier using the internal resistor ladder.
     *  */
    void configureOPA_NonInverting(uint8_t gain);
    
    /** 
     * <B><FONT COLOR=BLUE>void</FONT> configureOPA_Inverting(<FONT COLOR=BLUE>uint8_t</FONT> gain)</B>
     * @param gain (uint8_t) - resistor configuration 
     * 
     * Configures the OPA module into an inverting amplifier using the internal resistor ladder.
     *  */
    void configureOPA_Inverting(uint8_t gain);
    
    /** 
     * <B><FONT COLOR=BLUE>void</FONT> configureOPA_External(<FONT COLOR=BLUE>void</FONT>)</B>
     * 
     * Configures the OPA module to use external parts.
     *  */
    void configureOPA_External(void);

#ifdef	__cplusplus
}
#endif

#endif	/* OPASETUP_H */

