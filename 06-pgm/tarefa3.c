#include <stdio.h>

// gcc -Wall -pedantic -std=gnu99 -Og -o tarefa3 tarefa3.c && ./tarefa3

typedef struct{
    int width;
    int hight;
    int pixels[480][640];
} Imagem;

void le_imagem(Imagem *img, FILE *arq){
    char formato[3];

    fscanf(arq, "%s\n", formato);
    fscanf(arq, "%d %d\n", &img->width, &img->hight);

    for (int i = 0; i < img->hight; i++){
        for (int j = 0; j < img->width; j++){
            fscanf(arq, "%d", &img->pixels[i][j]);
        }
    }
}

void escreve_imagem(Imagem *img, FILE *arq){
    fprintf(arq, "P2\n");
    fprintf(arq, "%d %d\n", img->width, img->hight);
    fprintf(arq, "255\n");

    for (int i = 0; i < img->hight; i++){
        for (int j = 0; j < img->width; j++){
            fprintf(arq, "%d ", img->pixels[i][j]);
        }
        fprintf(arq, "\n");
    }
}

void limiar(Imagem *img, int limiar){
    for (int i = 0; i < img->hight; i++){
        for (int j = 0; j < img->width; j++){
            if (img->pixels[i][j] < limiar){
                img->pixels[i][j] = 0;
            } else {
                img->pixels[i][j] = 255;
            }
        }   
    }
}

int main(int argc, char *argv[]){
    Imagem img;
    FILE *arq, *arq2;

    // Le arquivo
    arq = fopen("cat.pgm", "r");
    /* arq = fopen(argv[1], "r"); */
    if (arq == NULL){
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    // Escreve arquivo
    arq2 = fopen("tarefa3_saida.pgm", "w");
    if (arq2 == NULL){
        printf("Erro ao abrir o arquivo2\n");
        return 1;
    }

    le_imagem(&img, arq);
    fclose(arq);

    limiar(&img, 110);
    escreve_imagem(&img, arq2);
    fclose(arq2);

    return 0;
}