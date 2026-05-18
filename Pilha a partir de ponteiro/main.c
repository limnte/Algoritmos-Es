#include <stdio.h>
#include <stdlib.h>

//Implementação de fila a partir de ponteiros 

typedef struct Item{
    int Chave; //Valor do item a ser inserido na pilha
    struct Item * Anterior; //Foi inserido ANTES na pilha
} Item;

typedef struct Pilha{
    int Tamanho; //indicar quantos elementos foram inseridos na Pilha
    Item * Topo; //Ponteiro para o ultimo elemento que foi inserido na pilha
} Pilha;


Item * CriarItem(int Chave);
Pilha * CriarPilha();

void Empilhar(Pilha * P, Item * I);
void ExibirPilha(Pilha * P);
void Desimpilhar(Pilha * P);

int main(){
    system("cls");

    Pilha * Exemplo = CriarPilha();
    
    Empilhar(Exemplo, CriarItem(137));
    Empilhar(Exemplo, CriarItem(200));
    Empilhar(Exemplo, CriarItem(234));
    Empilhar(Exemplo, CriarItem(456));
    Empilhar(Exemplo, CriarItem(765));

    printf("Antes de desempilhar:\n");
    ExibirPilha(Exemplo);

    Desimpilhar(Exemplo);

    printf("Depois de desempilhar:\n");
    ExibirPilha(Exemplo);

    return 0;
}

Pilha * CriarPilha(){
    Pilha * P = (Pilha *) malloc(sizeof(Pilha));

    if(P == NULL){
        printf("Erro ao alocar memoria para a pilha");
        return NULL;
    }

    P->Tamanho = 0;
    P->Topo = NULL;

    return P;
}


Item * CriarItem(int Chave){
    Item * I = (Item *) malloc(sizeof(Item));

    if(I == NULL){
        printf("Erro ao alocar memoria para o item");
        return NULL;
    }

    I->Chave = Chave;
    I->Anterior = NULL;

    return I;
}

void Empilhar(Pilha * P, Item * I){
    if( I == NULL || P == NULL) return;
    
    I->Anterior = P->Topo; //O item que foi inserido ANTES do item atual, é o topo da pilha
    P->Topo = I; //O topo da pilha passa a ser o item que foi inserido
    P->Tamanho++; //Aumenta o tamanho da pilha
}

void ExibirPilha(Pilha * P){
    if(P == NULL) return;

    Item * Atual = P->Topo; //Auxiliar para percorrer a pilha

    while(Atual != NULL){ //Enquanto o auxiliar não chegar no final da pilha
        printf("%d\n", Atual->Chave); //Exibe o valor do item
        Atual = Atual->Anterior; //Passa para o próximo item da pilha
    }
    printf("\n");
}

void Desimpilhar(Pilha * P){
    if(P == NULL || P->Topo == NULL) return;

    Item * Aux = P->Topo; //Auxiliar para armazenar o item que será removido
    P->Topo = P->Topo->Anterior; //O topo da pilha passa a ser o item que foi inserido ANTES do item que será removido
    free(Aux); //Libera a memória do item que foi removido
    P->Tamanho--; //Diminui o tamanho da pilha
}