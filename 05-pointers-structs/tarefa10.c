#include <stdio.h>

// gcc -Wall -pedantic -std=gnu99 -Og -o tarefa10 tarefa10.c && ./tarefa10

void calcula(int h, int w, int *parea, int *pperim){
    *parea = h * w;
    *pperim = 2*(h + w);
}

main(){
    int altura, largura, area, perimetro;

    printf("Digite a altura e largura: ");
    scanf("%d %d", &altura, &largura);

    calcula(altura, largura, &area, &perimetro);

    printf("Area: %d\n", area);
    printf("Perímetro: %d\n", perimetro);

    return 0;
}