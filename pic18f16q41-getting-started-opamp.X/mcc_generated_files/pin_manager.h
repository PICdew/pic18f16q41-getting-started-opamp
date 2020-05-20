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

// get/set LED_D5 aliases
#define LED_D5_TRIS                 TRISAbits.TRISA1
#define LED_D5_LAT                  LATAbits.LATA1
#define LED_D5_PORT                 PORTAbits.RA1
#define LED_D5_WPU                  WPUAbits.WPUA1
#define LED_D5_OD                   ODCONAbits.ODCA1
#define LED_D5_ANS                  ANSELAbits.ANSELA1
#define LED_D5_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define LED_D5_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define LED_D5_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define LED_D5_GetValue()           PORTAbits.RA1
#define LED_D5_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define LED_D5_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define LED_D5_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define LED_D5_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define LED_D5_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define LED_D5_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define LED_D5_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define LED_D5_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set RA2 procedures
#define RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define RA2_GetValue()              PORTAbits.RA2
#define RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define RA2_SetPullup()             do { WPUAbits.WPUA2 = 1; } while(0)
#define RA2_ResetPullup()           do { WPUAbits.WPUA2 = 0; } while(0)
#define RA2_SetAnalogMode()         do { ANSELAbits.ANSELA2 = 1; } while(0)
#define RA2_SetDigitalMode()        do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set LED_D4 aliases
#define LED_D4_TRIS                 TRISAbits.TRISA5
#define LED_D4_LAT                  LATAbits.LATA5
#define LED_D4_PORT                 PORTAbits.RA5
#define LED_D4_WPU                  WPUAbits.WPUA5
#define LED_D4_OD                   ODCONAbits.ODCA5
#define LED_D4_ANS                  ANSELAbits.ANSELA5
#define LED_D4_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define LED_D4_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define LED_D4_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define LED_D4_GetValue()           PORTAbits.RA5
#define LED_D4_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define LED_D4_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define LED_D4_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define LED_D4_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define LED_D4_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define LED_D4_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define LED_D4_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define LED_D4_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set RB4 procedures
#define RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()              PORTBbits.RB4
#define RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()             do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()           do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode()         do { ANSELBbits.ANSELB4 = 1; } while(0)
#define RB4_SetDigitalMode()        do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RC2 procedures
#define RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define RC2_GetValue()              PORTCbits.RC2
#define RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define RC2_SetPullup()             do { WPUCbits.WPUC2 = 1; } while(0)
#define RC2_ResetPullup()           do { WPUCbits.WPUC2 = 0; } while(0)
#define RC2_SetAnalogMode()         do { ANSELCbits.ANSELC2 = 1; } while(0)
#define RC2_SetDigitalMode()        do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set SW_1 aliases
#define SW_1_TRIS                 TRISCbits.TRISC4
#define SW_1_LAT                  LATCbits.LATC4
#define SW_1_PORT                 PORTCbits.RC4
#define SW_1_WPU                  WPUCbits.WPUC4
#define SW_1_OD                   ODCONCbits.ODCC4
#define SW_1_ANS                  ANSELCbits.ANSELC4
#define SW_1_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define SW_1_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define SW_1_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define SW_1_GetValue()           PORTCbits.RC4
#define SW_1_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define SW_1_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define SW_1_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define SW_1_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define SW_1_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define SW_1_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define SW_1_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define SW_1_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set LED_D7 aliases
#define LED_D7_TRIS                 TRISCbits.TRISC5
#define LED_D7_LAT                  LATCbits.LATC5
#define LED_D7_PORT                 PORTCbits.RC5
#define LED_D7_WPU                  WPUCbits.WPUC5
#define LED_D7_OD                   ODCONCbits.ODCC5
#define LED_D7_ANS                  ANSELCbits.ANSELC5
#define LED_D7_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define LED_D7_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define LED_D7_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define LED_D7_GetValue()           PORTCbits.RC5
#define LED_D7_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define LED_D7_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define LED_D7_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define LED_D7_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define LED_D7_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define LED_D7_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define LED_D7_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define LED_D7_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

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


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF4 pin functionality
 * @Example
    IOCCF4_ISR();
 */
void IOCCF4_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF4 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF4 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF4_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF4_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF4 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF4_SetInterruptHandler() method.
    This handler is called every time the IOCCF4 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF4_SetInterruptHandler(IOCCF4_InterruptHandler);

*/
extern void (*IOCCF4_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF4 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF4_SetInterruptHandler() method.
    This handler is called every time the IOCCF4 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF4_SetInterruptHandler(IOCCF4_DefaultInterruptHandler);

*/
void IOCCF4_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/