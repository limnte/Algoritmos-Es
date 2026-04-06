#include <stdio.h>
#include <stdlib.h>

typedef struct Item{
    int Chave;
    struct Item * Proximo; //endereço de memoria para o proximo item da lista
    
}Item;

typedef struct{
    int Tamanho;
    Item * Inicio;
    Item * Fim;

}Lista;

//funções
Item * CriarItem(int Chave);
void ExibirLista( Item * Inicio, int Tamanho);
int Par(Item * Inicio, int Tamanho);
Lista * CriarLista();

int main(){
    system("cls");

    Item * A = CriarItem(25);
    Item * B = CriarItem(35);
    Item * C = CriarItem(40);
    Item * D = CriarItem(10);
    
    //Construindo o Encadeamento;

    A->Proximo = C;
    C->Proximo = D;
    D->Proximo = B;
    B->Proximo = A;

    printf("\n---------------------------------------\n\n");
    ExibirLista(A, 4);
    Par(A,4);

    return 0;
}

Item * CriarItem(int Chave){
    Item * NovoItem = (Item *) malloc(sizeof(Item));

    if( NovoItem == NULL){
        printf("Erro ao alocar memoria");
        return NULL;
    }

    NovoItem->Chave = Chave;
    NovoItem->Proximo = NULL;

    printf("%X \t %d\t %x \n", NovoItem, NovoItem->Chave, NovoItem->Proximo);

    return NovoItem;
};

void ExibirLista( Item * Inicio, int Tamanho){

    Item * Temp = Inicio;
    
    for(int i = 0; i < Tamanho; i++){
        printf("%X \t %d\t %X \n", Temp, Temp->Chave, Temp->Proximo);
        Temp = Temp->Proximo;
    }

};

int Par(Item * Inicio, int Tamanho){

    Item * Temp = Inicio;
    int Contador = 0;
    
    for(int i = 0; i < Tamanho; i++){
        if(Temp->Chave % 2 == 0){
            Contador++;
        }
        Temp = Temp->Proximo;
    }

    printf("\n\nQuantidade de Elementos pares: %d", Contador);

};

Lista * CriarLista(){
    Lista * NovaLista = (Lista *) malloc(sizeof(Lista));

    if(NovaLista == NULL){
        printf("Erro ao alocar memoria para a lista");
        return NULL;
    }

    NovaLista->Tamanho = 0;
    NovaLista->Inicio = NULL;
    NovaLista->Fim = NULL;

    return NovaLista;
};
