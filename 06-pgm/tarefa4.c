# include <stdio.h>

// gcc -Wall -pedantic -std=gnu99 -Og -o tarefa4 tarefa4.c && ./tarefa4

typedef struct {
    int width;
    int hight;
    int pixels[480][640];
} Imagem;

void le_imagem(Imagem *img, FILE *arq) {
    char formato[3];

    fscanf(arq, "%s\n", formato);
    fscanf(arq, "%d %d\n", &img->width, &img->hight);

    for (int i = 0; i < img->width; i++){
        for (int j = 0; j < img->hight; j++){
            fscanf(arq, "%d", &img->pixels[i][j]);
        }
    }
}

void escreve_imagem(Imagem *img, FILE *arq) {
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

// Receba img_original, img_cortada e as coordenadas dos pontos superior esquerdo e inferior direito
void crop(Imagem *img_original, Imagem *img_cortada, int x1, int y1, int x2, int y2){
    if (x1 < 0) x1 = 0;
    if (y1 < 0) y1 = 0;
    if (x2 >= img_original->width) x2 = img_original->width - 1;
    if (y2 >= img_original->hight) y2 = img_original->hight - 1;

    int nova_largura = x2 - x1 + 1;
    int nova_altura = y2 - y1 + 1;

    img_cortada->width = nova_largura;
    img_cortada->hight = nova_altura;

    for (int i = 0; i < nova_altura; i++){
        for (int j = 0; j < nova_largura; j++){
            img_cortada->pixels[i][j] = img_original->pixels[y1 + i][x1 + j];
        }
    }

}

int main(){
    Imagem img_original, img_cortada;
    FILE *arq_entrada, *arq_saida;
    
    // Arquivo de entrada
    arq_entrada = fopen("entrada7.pgm", "r");
    le_imagem(&img_original, arq_entrada);
    fclose(arq_entrada);

    int x1 = 10, y1 = 10, x2 = 150, y2 = 160;
    crop(&img_original, &img_cortada, x1, y1, x2, y2);

    // Arquivo de saída
    arq_saida = fopen("tarefa4_saida.pgm", "w");
    escreve_imagem(&img_cortada, arq_saida);
    fclose(arq_saida);

    return 0;
}