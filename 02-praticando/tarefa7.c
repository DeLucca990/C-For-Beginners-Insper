// Configurações do mutirão. Não mexer.
#include "../macros_correcoes.h"
#define LABNUM "lab2-"
#define SOLUTIONFILE "tarefa7.c"

#include <stdio.h>

// TODO implemente sua função aqui
void arvore(int n) {
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n-i; j++){
            printf(" ");
        }
        for (int k = 1; k <= 2*i-1; k++){
            if (k == i) {
                printf("|");
            } else if (k < i) {
                printf("/");
            } else {
                printf("\\");
            }
        }
        printf("\n");
    }
}

// TODO implemente aqui um programa que chama
// a função que você faz, passando como
// parâmetro um inteiro que foi dado pelo usuário
int main() {
    int n;

    printf("Digite um número: ");
    scanf("%d", &n);
    arvore(n);

    return 0;
}
