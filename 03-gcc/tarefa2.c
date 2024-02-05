#include <stdio.h>

// $ gcc -Wall -pedantic -std=gnu99 -Og -o executavel arquivo.c
// $ ./executavel

int main() {
    int num1, num2;
    printf("Digite dois números inteiros: ");
    scanf("%d %d", &num1, &num2);

    if (num2 == 0) {    
        printf("Erro: O segundo número não pode ser zero.\n");
    } else {
        if (num1 % num2 == 0) {
            printf("%d é múltiplo de %d\n", num1, num2);
        } else {
            printf("%d não é múltiplo de %d\n", num1, num2);
        }
    }

    return 0;
}