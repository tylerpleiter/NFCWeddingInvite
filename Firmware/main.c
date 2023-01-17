/* 
 * File:   main.c
 * Author: tyler
 *
 * Created on 25 November 2021, 8:08 PM
 */

#include "pic16lf15324.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <xc.h>



#pragma config WDTE = OFF
#pragma config FEXTOSC = OFF
#pragma config RSTOSC = 101 // LFINTOSC
#pragma config LVP = ON

uint8_t ledFlag = 0, flashFlag = 0, randFlash = 0;
uint16_t activeLeds = 0b000000011;

void __interrupt() ISR(void) {
    if (TMR0IF) {
        ledFlag = 1;
        TMR0IF = 0;
    }
}
/*
 * 
 */
int main(int argc, char** argv) {

    
    // Setup IO led ports
    ANSELC = 0x00;          // Enable digital drivers
    TRISC = 0b00000000;     // Set all as output
    ODCONC |= 0b00000000;   // Set all as open drain
    SLRCONC = 0b11111111;
    PORTC = 0b00000000;     // Turn on all LEDS
    
    ANSELA &= 0b11001011;   // Enable digital drivers
    TRISA &= 0b11001011;    // Set as output
    ODCONA &= 0b11001011;   // Set as open drain
    PORTA &= 0b11001011;
    PORTA |= 0b00000000;    // Turn on all LEDS
    
    _delay(3000);
    
    PORTC = 0b11111111;     // Turn off all LEDS
    PORTA |= 0b00110100;    // Turn off all LEDS
    
    // Set led timer
    T0CON0 &= 0b01000000;
    T0CON0 |= 0b00000000;   // Enable 16-bit mode
    T0CON1 = 0;
    T0CON1 |= 0b10000001;   // Select LFINTOSC, 1:4 prescaler
    PIE0 |= 0b00100000;     // Enable tmr0 interrupt
    PIR0 &= 0b11011111;     // Clear tmr0 flag
    INTCON |= 0b11000000;  // Enable interrupts
    T0CON0 |= 0b10000000;   // Enable timer
    
    while (1) {
        
        if (ledFlag) {
            
            flashFlag++;
            
            
            
            if (flashFlag >= randFlash) {
                PORTC = (activeLeds ^ 0b111111111) & 0b111111;

                PORTA |= 0b00110100;

                if (activeLeds & 0b001000000) {
                    PORTA &= 0b11111011;
                } 
                if (activeLeds & 0b010000000) {
                    PORTA &= 0b11101111;
                } 
                if (activeLeds & 0b100000000) {
                    PORTA &= 0b11011111;
                }
    //            PORTA &= 0b11001011;
    //            PORTA |= 0b00110100;
                //PORTA ^= 0b00010000;
    //            PORTA |= (((activeLeds ^ 0b111111111) & 0b001000000) >> 4);
    //            PORTA |= (((activeLeds ^ 0b111111111) & 0b010000000) >> 3);
    //            PORTA |= (((activeLeds ^ 0b111111111) & 0b100000000) >> 3);
                _delay(1800);  // uS

                PORTC = 0b11111111;
                PORTA |= 0b00110100;


                _delay(1800);  // uS

                PORTC = (activeLeds ^ 0b111111111) & 0b111111;
                PORTA |= 0b00110100;
                if (activeLeds & 0b001000000) {
                    PORTA &= 0b11111011;
                } 
                if (activeLeds & 0b010000000) {
                    PORTA &= 0b11101111;
                } 
                if (activeLeds & 0b100000000) {
                    PORTA &= 0b11011111;
                }


                _delay(1800);  // uS

                PORTC = 0b11111111;
                PORTA |= 0b00110100;


                _delay(1800);  // uS

                activeLeds = 0b000000000;
                activeLeds |= (0b1 << (rand() % 9));
                activeLeds |= (0b1 << (rand() % 9));

                
                randFlash = rand() % 10;
                
                flashFlag = 0;
            }
            
            ledFlag = 0;
        }
        
    }
    
    
    return (EXIT_SUCCESS);
}

