#include <stdio.h>

// gcc -Wall -pedantic -std=gnu99 -Og -o main2 main2.c && ./main2

int main(){
    typedef struct {
        int hora;
        int minuto;
        int segundo;
    } horario;

    horario agora, *depois; // Variável agora e um ponteiro (*depois) que aponta para para a estrutura horario;

    depois = &agora; // 'depois' está armazenando o local da memória de 'agora'

    // 'depois' é um ponteiro de 'agora' e está modificando os campos de 'agora'
    depois -> hora = 20;
    depois -> minuto = 10;
    depois -> segundo = 5;

    printf("%d %d %d\n", agora.hora, agora.minuto, agora.segundo);

    return 0;
}