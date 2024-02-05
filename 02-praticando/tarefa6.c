// Configurações do mutirão. Não mexer.
#include "../macros_correcoes.h"
#define LABNUM "lab2-"
#define SOLUTIONFILE "tarefa6.c"

#include <stdio.h>

// TODO implemente sua função aqui
void fizzbuzz(int n) {
    for (int i = 1; i <= n; i++){
        if (i % 3 !=0 && i % 5 != 0){
            printf("Número: %d -> nenhum\n", i);
        }
        else if (i % 3 ==0 && i % 5 != 0){
            printf("Número: %d -> apenas por três\n", i);
        }
        else if (i % 3 !=0 && i % 5 == 0){
            printf("Número: %d -> apenas por cinco\n", i);
        }
        else if (i % 3 ==0 && i % 5 == 0){
            printf("Número: %d -> por três e por cinco\n", i);
        }
    }
}

// TODO implemente aqui um programa que chama
// a função que você faz, passando como
// parâmetro um inteiro que foi dado pelo usuário
int main() {
    int n;
    printf("Digite um número: ");
    scanf("%d", &n);
    
    fizzbuzz(n);

    return 0;
}
