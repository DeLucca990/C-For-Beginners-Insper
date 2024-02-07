#include <stdio.h>

// gcc -Wall -pedantic -std=gnu99 -Og -o tarefa1 tarefa1.c && ./tarefa1

typedef struct{
    int width;
    int hight;
    int pixels[480][640];
} Imagem;

void le_imagem(Imagem *img, FILE *arq){
    char formato[3];
    int valor_maximo;

    // Ler cabeçalho PGM
    fscanf(arq, "%s\n", formato);
    fscanf(arq, "%d %d\n", &img->width, &img->hight); // Armazena o endereco de memoria de "width" e "hight"
    fscanf(arq, "%d\n", &valor_maximo); // Armazena o endereco de memoria de "valor_maximo"

    for (int i = 0; i < img->hight; i++){
        for (int j = 0; j < img->width; j++){
            fscanf(arq, "%d", &img->pixels[i][j]); // Armazena o endereco de memoria de "pixels[i][j]"
        }
    }
}

int main(int argc, char *argv[]){
    Imagem img;
    FILE *arq;

    arq = fopen("cat.pgm", "r");
    // arq = fopen(argv[1], "r");
    if (arq == NULL){
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    le_imagem(&img, arq); // Passa o endereço de memória da variável "img"

    printf("Largura: %d\n", img.width);
    printf("Altura: %d\n", img.hight);
    printf("Pixels[0][0]: %d\n", img.pixels[0][0]);

    fclose(arq);

    return 0;
}
