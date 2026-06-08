#include <stdio.h>
#include <stdlib.h>

#define ERRO -1

int PesquisaBinaria(int *V, int N, int Chave);

int main(){
    system("cls");

    int Numeros[] = {1,2,3,4,5,6,7,8,10,12,14,16,18,20,21,22};
    int Tamanho = sizeof(Numeros) / sizeof(int);
    int Elemento = 10;

    int Posicao = PesquisaBinaria(Numeros, Tamanho, Elemento);

    if(Posicao != ERRO){
        printf("O elemento %d esta na posicao %d\n",Elemento,Posicao);
    }else{
        printf("O elemento %d nao foi encontrado ou nao existe\n", Elemento);
    }

    return 0;
}

int PesquisaBinaria(int *V, int N, int Chave){
    int Esquerda = 0;
    int Direita = N-1;

    while (Esquerda<=Direita){
        int Meio = (Esquerda + Direita)/2;

        if(V[Meio] == Chave){
            return Meio;
        }else if (V[Meio] < Chave){
            Esquerda = Meio + 1;
        }else{
            Direita = Meio - 1;
        }
        
    }
    
    return ERRO;
}