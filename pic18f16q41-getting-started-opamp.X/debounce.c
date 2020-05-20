#include "mcc_generated_files/mcc.h"

#include "debounce.h"
#include "OPAsetup.h"
#include <xc.h>

// Thank you Keith for the improved debouncing routine!

// Variable definitions for button debounce
union U1
{
    struct S1
    {
        unsigned char	count:4;			// delay couter
        unsigned char	pkey:1;				// present key state
        unsigned char	oldk:1;				// previous debounced key state
        unsigned char	newk:1;				// new debounced key state
        unsigned char	nuse:1;				// unused
    } flags;
    unsigned char	whole;					// used to preset all variables at once
} keys[1];									// one collection of variables for each key

void initDebounce(void)
{
    keys[0].whole = 0x00;
}

void updateKeyState(uint8_t index, uint8_t state)
{
    keys[index].flags.pkey = state;
}

void debounce(void)
{
    uint8_t key_index;
    for(key_index = 0; key_index < 1; key_index++)
	{
		// process key pressed (button pressed and counter < max)
		if((keys[key_index].flags.pkey > 0) && (keys[key_index].flags.count < 0x0F))
		{
			keys[key_index].flags.count++;		// count Keypress

			// if count = hi-hyst keypressed
			if (keys[key_index].flags.count == 0x0C) keys[key_index].flags.newk = 1;

			// of new = 1 and old = 0, then keypress event
			if ((keys[key_index].flags.newk == 1) && (keys[key_index].flags.oldk == 0))
			{                
                changeOPAconfig();
                
				// copy new key into old key
				keys[key_index].flags.oldk = 1;
			}
		}
		// Pressed Key Open (button open and counter > 0)
		if((keys[key_index].flags.pkey == 0) && (keys[key_index].flags.count > 0))
		{
			keys[key_index].flags.count--;		// count keyopen

			// if count = lo-hyst keyopen
			if (keys[key_index].flags.count == 0x04) keys[key_index].flags.newk = 0;

			// of new = 0 and old = 1, then key release event
			if ((keys[key_index].flags.newk == 0) && (keys[key_index].flags.oldk == 1))
			{                
				// copy new key into old key
				keys[key_index].flags.oldk = 0;
			}
		}
	}
}

void changeOPAconfig(void)
{
    static OPA_CONFIG config = NON_INVERTING;
    
    //Change the settings
    setupOPA(config);
        
    //Move to the next config
    if (config == CUSTOM_SETUP)
        config = UNITY_GAIN;
    else
        config++;
}