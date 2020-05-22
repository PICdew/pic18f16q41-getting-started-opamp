/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.0
        Device            :  PIC18F16Q41
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"

#include "OPAsetup.h"
#include "debounce.h"

/*
 * OPA Module I/O
 * OPA1OUT = RC2
 * In+ = RA2 (Non-Inverting, Unity Gain)
 * In- = RA2 (Inverting)
 * 
 * External only:
 * In+ = RB5 (Custom)
 * In- = RB4 (Custom)
 */

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    
    // Initialize the Debounce Machine
    initDebounce();
    
    // Start TMR2
    TMR2_Start();
        
    uint8_t count = 0;
    while (1)
    {
        // Occurs every 1ms
        if (TMR2_HasOverflowOccured())
        {
            // Increment Timer Counter for LEDs
            count++;
            
            // Update the key state (invert to prevent premature switching)
            updateKeyState(0, !SW_1_GetValue());
            
            // Run debouncing
            debounce();
        }
        
        // Change the LED
        if (count == 250)
        {
            LED_D7_LAT = !LED_D7_LAT;
        }
    }
}
/**
 End of File
*/