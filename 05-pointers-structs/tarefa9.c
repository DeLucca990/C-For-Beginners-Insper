#include <stdio.h>

// gcc -Wall -pedantic -std=gnu99 -Og -o tarefa9 tarefa9.c && ./tarefa9

void sum_sub(int a, int b, int *psum, int *psub){
    *psum = a + b;
    *psub = a - b;
}

int main(){
    int num1, num2, sum, sub;
    printf("Digite dois inteiros: ");
    scanf("%d %d", &num1, &num2);

    sum_sub(num1, num2, &sum, &sub);

    printf("Soma: %d\n", sum);
    printf("Subtração: %d\n", sub);

    return 0;
}