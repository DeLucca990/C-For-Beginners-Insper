#include <stdio.h>

// gcc -Wall -pedantic -std=gnu99 -Og -o tarefa2 tarefa2.c && ./tarefa2

typedef struct{
    int width;
    int hight;
    int pixels[480][640];
} Imagem;

void escreve_imagem(Imagem *img, FILE *arq){ // Recebe um ponteiro para a estrutura "Imagem" e um ponteiro para o arquivo chamado "arq"
    fprintf(arq, "P2\n");
    fprintf(arq, "%d %d\n", img->width, img->hight); // Escreve a largura e altura da imagem (acessa o membro "width" e "hight" da estrutura "Imagem") (*img).width
    fprintf(arq, "255\n"); // Escreve o valor máximo de um pixel

    for (int i = 0; i < img->hight; i++){
        for (int j = 0; j < img->width; j++){
            fprintf(arq, "%d ", img->pixels[i][j]);
            /* printf("%d\n", img->pixels[i][j]); */
        }
        fprintf(arq, "\n");
    }
}

int main(int argc, char *argv[]){
    Imagem img;
    FILE *arq;

    img.width = 640;
    img.hight = 480;

    for (int i = 0; i < img.hight; i++){
        for (int j = 0; j < img.width; j++){
            img.pixels[i][j] = 255;
        }
    }

    arq = fopen("tarefa2_exemplo.pgm", "w");
    if (arq == NULL){
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    escreve_imagem(&img, arq); // Passa o endereço de memória da variável "img" que é um ponteiro para a estrutura "Imagem"

    fclose(arq);

    return 0;
}