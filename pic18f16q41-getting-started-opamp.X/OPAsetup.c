#include "mcc_generated_files/mcc.h"
#include "OPAsetup.h"

#include <xc.h>
#include <stdint.h>

void setupOPA(OPA_CONFIG setup)
{
    switch (setup)
    {
        case UNITY_GAIN:        // Unity Gain 
            LED_D4_SetLow();
            LED_D5_SetLow();
            SET_OPA_UNITY_GAIN;
            break;
        case NON_INVERTING:     // Non-Inverting Amplifier
            LED_D4_SetHigh();
            LED_D5_SetLow();
            SET_OPA_NON_INVERT(0b011);  // Gain of 2
            break;
        case INVERTING:         // Inverting Amplifier
            LED_D4_SetLow();
            LED_D5_SetHigh();
            SET_OPA_INVERT(0b011);      // Gain of -1
            break;
        case CUSTOM_SETUP:      // External Parts (Custom)
            LED_D4_SetHigh();
            LED_D4_SetHigh();
            SET_OPA_EXT_SETUP;
            break;
    }
}

void clearOPAconfig(void)
{
    OPA1CON0 = 0x00;
    OPA1CON1 = 0x00;
    OPA1CON2 = 0x00;
    OPA1CON3 = 0x00;
    
    OPA1HWC = 0x00;
    OPA1ORS = 0x00;
}

void configureOPA_UnityGain(void)
{
    clearOPAconfig();
    
    //GSEL R1 = 15R and R2 = 1R, R2/R1 = 0.07; RESON Disabled; NSS OPA1IN0-; 
    OPA1CON1 = 0x00;

    //NCH No Connection; PCH OPA1IN+; 
    OPA1CON2 = 0x02;

    //FMS No Connection; PSS OPA1IN2+; 
    OPA1CON3 = 0x02;

    //OREN Software Override; HWCH User Defined Feedback; ORPOL Non Inverted; HWCL User Defined Feedback; 
    OPA1HWC = 0x00;

    //ORS LFINTOSC; 
    OPA1ORS = 0x00;    

    //EN Enabled; UG OPA Output; SOC User Defined Feedback; 
    OPA1CON0 = 0x88;

}

void configureOPA_NonInverting(uint8_t gain)
{
    clearOPAconfig();
    
    //GSEL R1 = 8R and R2 = 8R, R2/R1 = 1; RESON Enabled; NSS Vss; 
    OPA1CON1 = 0x3F;

    //NCH GSEL; PCH OPA1IN+; 
    OPA1CON2 = 0x12;

    //FMS OPA1OUT; PSS OPA1IN2+; 
    OPA1CON3 = 0x82;

    //OREN Software Override; HWCH User Defined Feedback; ORPOL Non Inverted; HWCL User Defined Feedback; 
    OPA1HWC = 0x00;

    //ORS LFINTOSC; 
    OPA1ORS = 0x00;    

    OPA1CON1bits.GSEL = gain;
    
    //EN Enabled; UG OPAIN- pin; SOC User Defined Feedback; 
    OPA1CON0 = 0x80;
}

void configureOPA_Inverting(uint8_t gain)
{
    clearOPAconfig();
    
    //GSEL R1 = 8R and R2 = 8R, R2/R1 = 1; RESON Enabled; NSS OPA1IN2-; 
    OPA1CON1 = 0x3A;

    //NCH GSEL; PCH Vdd/2; 
    OPA1CON2 = 0x13;

    //FMS OPA1OUT; PSS OPA1IN0+; 
    OPA1CON3 = 0x80;

    //OREN Software Override; HWCH User Defined Feedback; ORPOL Non Inverted; HWCL User Defined Feedback; 
    OPA1HWC = 0x00;

    //ORS LFINTOSC; 
    OPA1ORS = 0x00;    

    OPA1CON1bits.GSEL = gain;
    
    //EN Enabled; UG OPAIN- pin; SOC User Defined Feedback; 
    OPA1CON0 = 0x80;
}

void configureOPA_External(void)
{
    clearOPAconfig();
    
    //GSEL R1 = 15R and R2 = 1R, R2/R1 = 0.07; RESON Disabled; NSS OPA1IN0-; 
    OPA1CON1 = 0x00;

    //NCH OPA1IN-; PCH OPA1IN+; 
    OPA1CON2 = 0x22;

    //FMS No Connection; PSS OPA1IN0+; 
    OPA1CON3 = 0x00;

    //OREN Software Override; HWCH User Defined Feedback; ORPOL Non Inverted; HWCL User Defined Feedback; 
    OPA1HWC = 0x00;

    //ORS LFINTOSC; 
    OPA1ORS = 0x00;    

    //EN Enabled; UG OPAIN- pin; SOC User Defined Feedback; 
    OPA1CON0 = 0x80;
}