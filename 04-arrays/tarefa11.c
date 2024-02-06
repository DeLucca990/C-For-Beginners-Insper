#include <stdio.h>

// $ gcc -Wall -pedantic -std=gnu99 -Og -o tarefa11 tarefa11.c && ./tarefa11

int main(){
    int matriz[5][4];

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 4; j++){
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nSoma de cada coluna:\n");
    int maior_valor = 0;
    int indice_maior = 0;
    for (int j = 0; j < 4; j++){
        int soma = 0;
        for (int i = 0; i < 5; i++){
            soma+=matriz[i][j];
        }
        printf("Coluna %d: %d\n", j, soma);
        if (soma > maior_valor){
            maior_valor = soma;
            indice_maior = j;
        }
    }

    printf("\nÍndice da coluna de maior valor: %d\n", indice_maior);

    return 0;
}