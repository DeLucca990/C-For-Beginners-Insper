/*
 * Escreva seu programa aqui!
 */

// gcc -Wall -pedantic -std=gnu99 -Og -o main main.c && ./main
#include <stdio.h>

int main(){
    int var = 15;
    int *ptr;

    ptr = &var; // ptr está apontando para o endereço de memória de vars

    printf("Conteudo de var = %d\n", var);
    printf("Endereço de var = %p\n", &var);
    printf("Conteúdo apontado por ptr = %d\n", *ptr); // Valor que está guardado no endereço de memória
    printf("Endereço apontado por ptr = %p\n", ptr);
    printf("Endereço de ptr           = %p\n", &ptr);

    *ptr = 73;

    printf("\n\n");
    printf("Conteudo de var = %d\n", var);
    printf("Endereço de var = %p\n", &var);
    printf("Conteúdo apontado por ptr = %d\n", *ptr);
    printf("Endereço apontado por ptr = %p\n", ptr);
    printf("Endereço de ptr           = %p\n", &ptr);

    return 0;
}

// *ptr: o apontado por, conteúdo do endereço da variável que ptr aponta
//  ptr: o endereço da variável
// &ptr: o endereço de ptr