#include <stdio.h>
#include <stdlib.h>

#define MAX 3 //definindo uma constante

//implementação de fila usando vetor
typedef struct Item{
    int chave;
} Item;

Item criarItem(int chave){
    Item item;
    item.chave = chave;

    return item;
};

int main(){
    system("cls");

    Item V[MAX];

    V[0] = criarItem(137);
    V[1] = criarItem(241);
    V[2] = criarItem(339);

    printf("Lista de itens\n\n");

    for(int i = 0; i < MAX; i++){
        printf("Item %d: %d\n", i, V[i].chave);
    }

    printf("\n");

    return 0;
}

