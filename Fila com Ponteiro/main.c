#include <stdio.h>
#include <stdlib.h>

typedef struct Item{
    int chave;
    struct Item * proximo;
} Item;

typedef struct{
    int tamanho;
    Item * inicio;
    Item * fim;
} Fila;

Item criarItem(int chave);
Fila * criarFila();
void exibirFila(Fila * f);
void Enfileirar(Fila * f, Item * I);
void Desinfileirar(Fila * f);

void main(){
    system("cls");

    Item A = criarItem(132);
    Item B = criarItem(216);
    Item C = criarItem(659);
    Item D = criarItem(118);

    Fila * f = criarFila();

    Enfileirar(f, &A);
    Enfileirar(f, &B);
    Enfileirar(f, &C);
    Enfileirar(f, &D);

    exibirFila(f);
    Desinfileirar(f);
    exibirFila(f);
    Desinfileirar(f);
    exibirFila(f);
}

Item criarItem(int chave){
    Item item;
    item.chave = chave;

    return item;
};

Fila * criarFila(){
    Fila * f = (Fila *) malloc(sizeof(Fila));

    if( f == NULL){
        printf("ERRO: SEM MEMORIA PARA A Fila\n");
        return NULL;
    }

    f-> tamanho = 0;
    f-> inicio = NULL; //A lista est� vazia, empty, sem nada
    f-> fim = NULL;

    return f;
}

void exibirFila(Fila * f){
    Item * Temp  = f-> inicio;

    
    printf("Fila: a fila tem %d elementos\n", f->tamanho);

    for(int i = 0; i < f->tamanho; i++){
        printf("%d\n", Temp->chave);
        Temp = Temp->proximo;
    }

    printf("\n");
}

void Enfileirar(Fila * f, Item * I){
    if(f == NULL || I == NULL){
        printf("ERRO: Fila ou Item nulo\n");
        return;
    }

    I->proximo = NULL;

    if(f->tamanho == 0){
        f->inicio = I;
    }else{
        f->fim->proximo = I;
    }

    f->fim = I;
    f->tamanho++;
}

void Desinfileirar(Fila * f){
    if(f == NULL || f->tamanho == 0){
        printf("ERRO: Fila nula ou vazia\n");
        return;
    }

    Item * aux = f->inicio;
    f->inicio = aux -> proximo;

    if(f->inicio == NULL){
        f->fim = NULL;
    }

    f->tamanho--;
    free(aux);
}
