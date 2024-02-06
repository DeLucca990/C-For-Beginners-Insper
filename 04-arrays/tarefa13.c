#include <stdio.h>
#include <math.h>
// $ gcc -Wall -pedantic -std=gnu99 -Og -o tarefa13 tarefa13.c -lm -lsystemd && ./tarefa13

# define MAX_SIZE 100

double avg(double vetor[], int tamanho){
    double soma = 0.0;
    for (int i = 0; i < tamanho; i++){
        soma += vetor[i];
    }

    return soma / tamanho;
}

double variancia(double vetor[], int tamanho, double media){
    double soma_quadrados = 0.0;
    for (int i = 0; i < tamanho; i++){
        soma_quadrados = pow(vetor[i] - media, 2);
    }

    return soma_quadrados / tamanho;
}

int main(){
    int n;
    double numeros[MAX_SIZE];
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    if (n > 0 && n < 100){
        printf("Digite os %d elementos do vetor: \n", n);
        for (int i = 0; i < n; i++){
            scanf("%lf", &numeros[i]);
        }
        
        // Média
        double media = avg(numeros, n);
        printf("A média dos elementos do vetor é: %.2lf\n", media);
        // Variância
        double var = variancia(numeros, n, media);
        printf("A variância do vetor é: %.2lf\n", var);
    } else {
        printf("Tamanho inválido\n");
    }

    return 0;
}