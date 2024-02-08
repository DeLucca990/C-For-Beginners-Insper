#include <stdio.h>
#include <stdlib.h>

// gcc -Wall -pedantic -std=gnu99 -Og -o tarefa6 tarefa6.c -lm -lsystemd && ./tarefa6

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

void bordas(Imagem *img_original, Imagem *img_bordas) {
    img_bordas->width = img_original->width;
    img_bordas->height = img_original->height;
    aloca_pixels(img_bordas);

    for (int y = 0; y < img_original->height; y++) {
        for (int x = 0; x < img_original->width; x++){
            int valor_central = img_original->pixels[y][x];
            int soma_vizinhos = 0;

            // Soma Valores dos vizinhos
            if (x < 0) soma_vizinhos += img_original->pixels[y][x-1];
            if (x < img_original->width - 1) soma_vizinhos += img_original->pixels[y][x + 1];
            if (y > 0) soma_vizinhos += img_original->pixels[y - 1][x];
            if (y < img_original->height - 1) soma_vizinhos += img_original->pixels[y + 1][x];

            int diferenca = 4 * valor_central - soma_vizinhos;

            // Limite a diferença para estar dentro do intervalo [0, 255]
            diferenca = diferenca < 0 ? 0 : diferenca;
            diferenca = diferenca > 255 ? 255 : diferenca;

            img_bordas->pixels[y][x] = diferenca;
        }
    }
}

int main() {
    Imagem img_original, img_bordas;
    FILE *arq_entrada, *arq_saida;

    arq_entrada = fopen("entrada7.pgm", "r");
    le_imagem(&img_original, arq_entrada);
    fclose(arq_entrada);

    bordas(&img_original, &img_bordas);

    arq_saida = fopen("tarefa6_saida.pgm", "w");
    escreve_imagem(&img_bordas, arq_saida);
    fclose(arq_saida);

    libera_pixels(&img_original);
    libera_pixels(&img_bordas);

    return 0;
}