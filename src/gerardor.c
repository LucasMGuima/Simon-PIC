#include "../include/simon.h"
#include <stdlib.h>

void limpar_vetor(unsigned char * sequencia, unsigned char tamanho){
    unsigned char cont;
    for(cont = 0; cont < tamanho; cont++){
        sequencia[cont] = 0;
    }
}

void gerar_sequencia(unsigned char * sequencia, unsigned char tamanho){
    unsigned char num;
    unsigned char cont;

    // Certifica que o vetor está limpo
    limpar_vetor(sequencia, tamanho);

    // Gera uma nova sequencia
    for(cont = 0; cont < tamanho; cont++){
        num = (unsigned char) rand() % 4 + 1;
        sequencia[cont] = num;
    }
}