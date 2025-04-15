#include "../include/simon.h"
#include <pic16f84a.h>

#define DELAY 1

void to_paralel(char bits){
    unsigned char i;
    for(i = 0; i < 8; i++){
        DATA = (bits & (1<<i)) ? 1 : 0;
        CLK = 1;
        __delay_ms(DELAY);
        CLK = 0;
        __delay_ms(DELAY);
    }
    LATCH = 1;
    __delay_ms(DELAY);
    LATCH = 0;
    __delay_ms(DELAY);
}

char to_bits(unsigned char nivel){
    switch (nivel){
        // O UTIMO bit É IGNORADO
        //   abcdefg-
        // 0b00000000
        default:
            return 0b00000000;
            break;
        case 1:
            // Numero: 1
            return 0b01100000;
            break;
        case 2:
            // Numero: 2
            return 0b11011010;
            break;
        case 3:
            // Numero: 3
            return 0b11110010;
            break;
        case 4:
            // Numero: 4
            return 0b01100110;
            break;
        case 5:
            // Numero: 5
            return 0b10110110;
            break;
        case 6:
            // Numero: 6
            return 0b10111110;
            break;
        case 7:
            // Numero: 7
            return 0b11100000;
            break;
        case 8:
            // Numero: 8
            return 0b11111110;
            break;
        case 9:
            // Numero: 9
            return 0b11100110;
            break;
    };
    return 0b0000000;
}