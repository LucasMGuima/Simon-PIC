#ifndef _SIMON_H
#define _SIMON_H

    #include <builtins.h>
    #include <pic.h>
    #include <pic16f84a.h>
    #include <xc.h>

    // Frequencia do cristal
    #define _XTAL_FREQ 4000000 // 4MHz

    // Pinagem do LED e Botão referente ao LED1
    #define LED1_OUT PORTBbits.RB0
    #define LED1_INP PORTBbits.RB7
    // Pinagem do LED e Botão referente ao LED2
    #define LED2_OUT PORTBbits.RB1
    #define LED2_INP PORTBbits.RB6
    // Pinagem do LED e Botão referente ao LED3
    #define LED3_OUT PORTBbits.RB2
    #define LED3_INP PORTBbits.RB5
    // Pinagem do LED e Botão referente ao LED4
    #define LED4_OUT PORTBbits.RB3
    #define LED4_INP PORTBbits.RB4
    
    // Pinagem do LED referente a perda
    #define LED_LOSE PORTAbits.RA0

    // Pinagem 74HC595
    #define DATA PORTAbits.RA2
    #define CLK PORTAbits.RA1
    #define LATCH PORTAbits.RA3

    // Pisca os LEDs de acordo com a sequencia
    void mostrar_sequencia(unsigned char * sequencia, unsigned char tamanho);
    // Verifica se a sequencia dos botões pressionados é igual a sequencia entrada
    void tratar_entrada(unsigned char * sequencia, unsigned char tamanho);
    // Gera uma nova sequencia de tamanho x
    void gerar_sequencia(unsigned char * sequencia, unsigned char tamanho);
    // Passa a sequencia de serial para paralelo
    void to_paralel(char bits);
    // Converte o nivel para uma sequencia de bits
    char to_bits(unsigned char nivel);

#endif