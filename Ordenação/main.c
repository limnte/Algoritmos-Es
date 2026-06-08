#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 100000

int main(){
    system("cls");

    clock_t inicio,fim; //conta intruições a partir de certo ponto
    double tempo_gasto;

    int V[TAMANHO];

    srand(time(NULL));

    inicio = clock();
    for(int i = 0; i < TAMANHO; i++) V[i] = rand() % 1000;
    for(int i = 0; i < TAMANHO; i++) printf("%d \t", V[i]);
    fim = clock();

    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("\n\n\ntempo: %.2f seg", tempo_gasto);

    return 0;
}