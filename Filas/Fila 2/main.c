#include <stdio.h>
#include <stdlib.h>

//implementação de fila usando vetor
typedef struct Item{
    int chave;
} Item;

typedef struct{
    Item * dados;
    int inicio; //posição do primeiro elemento da fila
    int fim; //posição do próximo elemento a ser inserido na fila
    int tamanho; //quantidade de elementos que foram inseridos na fila
    int capacidade; //quantidade máxima de elementos que a fila pode armazenar
} Fila;

Item criarItem(int chave);
Fila * criarFila(int capacidade);
void destruirFila(Fila * F);
void inserir(Fila * F, Item item);
void exibirFila(Fila * F);
void desenfileirar(Fila * F);

int main(){
    system("cls");

    Fila * ex = criarFila(15);
    
    inserir(ex, criarItem(137));
    inserir(ex, criarItem(230));
    inserir(ex, criarItem(342));

    exibirFila(ex);

    desenfileirar(ex);

    exibirFila(ex);

    destruirFila(ex);

    return 0;
}

Item criarItem(int chave){
    Item item;
    item.chave = chave;

    return item;
}

Fila * criarFila(int capacidade){
    Fila * F = (Fila *) malloc(sizeof(Fila));

    if(F == NULL){
        printf("Erro ao alocar memória para a fila\n");
        return NULL;
    }

    F->capacidade = capacidade;
    F->tamanho = 0;
    F->inicio = -1;
    F->fim = -1;

    F->dados = (Item *) malloc(capacidade * sizeof(Item)); //alocando memória para o vetor de itens

    if(F->dados == NULL){
        printf("Erro ao alocar memória para os dados da fila\n");
        free(F); //liberando a memória alocada para a fila
        return NULL;
    }

    return F;
}

void destruirFila(Fila * F){
    if(F != NULL){
        free(F->dados); //liberando a memória alocada para os dados da fila
        free(F); //liberando a memória alocada para a fila
    }else{
        return;
    }
}

void inserir(Fila * F, Item item){
    if(F == NULL){
        printf("Fila não existe\n");
        return;
    }

    if(F->tamanho == F->capacidade){
        printf("Fila cheia\n");
        return;
    }

    if(F->inicio == -1){ //verificando se a fila está vazia
        F->inicio = 0; //definindo o início da fila como 0
    }

    
    F->fim = F->fim + 1;
    F->dados[F->fim] = item; //inserindo o item na posição do fim da fila
    F->tamanho++; //incrementando o tamanho da fila
}

void exibirFila(Fila * F){
    if(F == NULL){
        printf("Fila não existe\n\n");
        return;
    }

    if(F->tamanho == 0){
        printf("Fila vazia\n\n");
        return;
    }

    printf("Fila:\n");

    for(int i = 0; i < F->tamanho; i++){
        int idx = (F->inicio + i) % F->capacidade;
        printf("%d\n", F->dados[idx].chave);
    }

    printf("\n");
}

void desenfileirar(Fila * F){
    if(F->tamanho == 0){
        printf("Fila vazia\n");
        return;
    }

    F->inicio = (F->inicio + 1) % F->capacidade;
    F->tamanho--;
}