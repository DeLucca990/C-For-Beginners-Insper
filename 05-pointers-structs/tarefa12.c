#include <stdio.h>
#include <math.h> 

// $ gcc -Wall -pedantic -std=gnu99 -Og -o tarefa12 tarefa12.c -lm -lsystemd && ./tarefa12

typedef struct{
    int x;
    int y;
} ponto;

int manhattan(ponto p1, ponto p2){
    int resx = fabs(p1.x - p2.x);
    int resy = fabs(p1.y - p2.y);

    return resx + resy;
}

double euclidiana(ponto p1, ponto p2){
    int resx = p2.x - p1.x;
    int resy = p2.y - p1.y;

    return sqrt(resx*resx + resy*resy);
}

int main(){
    ponto p1, p2;
    printf("Digite a primeira coordenada: ");
    scanf("%d %d", &p1.x, &p1.y);
    printf("Digite a segunda coordenada: ");
    scanf("%d %d", &p2.x, &p2.y);

    printf("Distância de manhattan: %d\n", manhattan(p1, p2));
    printf("Distância euclidiana: %lf\n", euclidiana(p1, p2));
    

    return 0;
}