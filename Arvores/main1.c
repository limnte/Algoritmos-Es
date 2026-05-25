#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No * filho[6];
} No;

typedef struct Arvore{
    No * raiz;
    int altura;
    int grau;
    int NumeroFolhas;
    int NumeroNos;
}Arvore;

No * criarNo(int valor);

int main(){
    system("cls");

    No *A = criarNo(125);
    No *B = criarNo(216);
    No *C = criarNo(456);

    A->filho[0] = B;
    A->filho[1] = C;

    return 0;
}

No * criarNo(int valor){
    No * n = (No *) malloc(sizeof(No));

    if(n == NULL){
        printf("Não foi possivel alocar memoria para o No");
        return;
    }


    n->valor = valor;

    for(int i = 0; i < 6; i++){
        n->filho[i] = NULL;
    }

    return n;
}

