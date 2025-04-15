/** 
 * @file main.c
 * @author Lucas da Mata
 * @date 2025-04-12
 * @brief Main function 
 */

#include "../include/simon.h"

int main(){
    unsigned char nivel;
    unsigned char sequencia[4];
    int cont;
  
    // Configura RB7 a RB4 como entrada
    // e RB0 a RB3 como saida
    TRISB = 0b11110000;
    TRISA = 0b00000000; 

    PORTB = 0b00000000;

    // Gera uma sequencia
    nivel = 1;

    while(1){
      to_paralel(to_bits(nivel));
      __delay_ms(2500);
      // Gera uma nova sequencia
      gerar_sequencia(sequencia, nivel);
      // Mostra sequencia
      mostrar_sequencia(sequencia, nivel);
      // Entrada da sequencia
      tratar_entrada(sequencia, nivel);

      if(LED_LOSE == 1){
        // Se o LED de perda estiver aceso, reinicia o jogo
        nivel = 1;
        LED_LOSE = 0;
        to_paralel(0b00011100);
        __delay_ms(2500);
        to_paralel(0b00000000);
        __delay_ms(2500);
        to_paralel(0b00011100);
        __delay_ms(2500);
        to_paralel(0b00000000);
        __delay_ms(2500);
      }else{
        // Proxima fase
        nivel++;
        if(nivel > 9) nivel = 1; 
        __delay_ms(2500);
      }
    }
};
