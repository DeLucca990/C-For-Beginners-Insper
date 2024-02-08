#include <stdio.h>
#include <stdlib.h>

// gcc -Wall -pedantic -std=gnu99 -Og -o tarefa5 tarefa5.c -lm -lsystemd && ./tarefa5

typedef struct {
    int width;
    int height;
    int **pixels; // Alocação dinâmica de memória. Aloca memória para um array bidimensinal de inteiros de forma dinâmica, 
} Imagem;

void aloca_pixels(Imagem *img) {
    img->pixels = (int **)malloc(img->height * sizeof(int *));
    for (int i = 0; i < img->height; i++) {
        img->pixels[i] = (int *)malloc(img->width * sizeof(int));
    }
}

void libera_pixels(Imagem *img) {
    for (int i = 0; i < img->height; i++) {
        free(img->pixels[i]);
    }
    free(img->pixels);
}

void le_imagem(Imagem *img, FILE *arq) {
    char formato[3];

    fscanf(arq, "%s\n", formato);
    fscanf(arq, "%d %d\n", &img->width, &img->height);
    aloca_pixels(img);

    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            fscanf(arq, "%d", &img->pixels[i][j]);
        }
    }
}

void escreve_imagem(Imagem *img, FILE *arq) {
    fprintf(arq, "P2\n");
    fprintf(arq, "%d %d\n", img->width, img->height);
    fprintf(arq, "255\n");

    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            fprintf(arq, "%d ", img->pixels[i][j]);
        }
        fprintf(arq, "\n");
    }
}

void blur(Imagem *img_original, Imagem *img_borrada) {
    img_borrada->width = img_original->width;
    img_borrada->height = img_original->height;
    aloca_pixels(img_borrada);

    for (int y = 0; y < img_original->height; y++) {
        for (int x = 0; x < img_original->width; x++) {
            int soma = 0;
            int total_vizinhos = 0;

            for (int j = -1; j <= 1; j++) {
                for (int i = -1; i <= 1; i++) {
                    int novo_x = x + i;
                    int novo_y = y + j;

                    if (novo_x >= 0 && novo_x < img_original->width && novo_y >= 0 && novo_y < img_original->height) {
                        soma += img_original->pixels[novo_y][novo_x];
                        total_vizinhos++;
                    }
                }
            }

            int media = soma / total_vizinhos;
            img_borrada->pixels[y][x] = media;
        }
    }
}

int main() {
    Imagem img_original, img_borrada;
    FILE *arq_entrada, *arq_saida;

    arq_entrada = fopen("entrada4.pgm", "r");
    le_imagem(&img_original, arq_entrada);
    fclose(arq_entrada);

    blur(&img_original, &img_borrada);

    arq_saida = fopen("tarefa5_saida.pgm", "w");
    escreve_imagem(&img_borrada, arq_saida);
    fclose(arq_saida);

    libera_pixels(&img_original);
    libera_pixels(&img_borrada);

    return 0;
}