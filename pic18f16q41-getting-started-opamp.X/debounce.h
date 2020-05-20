/* 
 * File:   debounceFSM.h
 * Author: C62081
 *
 * Created on May 11, 2020, 9:33 AM
 */

#ifndef DEBOUNCEFSM_H
#define	DEBOUNCEFSM_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stdint.h>
    
    /** Initializes the Debounce Routine*/
    void initDebounce(void);
    
    /** Updates the key state before debounce */
    void updateKeyState(uint8_t index, uint8_t state);
    
    /** Debounces the key */
    void debounce(void);
        
    /** Change the OPA configuration */
    void changeOPAconfig(void);

#ifdef	__cplusplus
}
#endif

#endif	/* DEBOUNCEFSM_H */

