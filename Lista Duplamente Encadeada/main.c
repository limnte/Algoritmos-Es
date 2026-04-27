#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct Item{
    char Autor[100];
    char Titulo[100];
    int Ano;
    struct Item * Proximo;
    struct Item * Anterior;

} Item;

typedef Item Musica;

typedef struct Lista{
    int Tamanho;
    struct Item * Inicio;
}Lista;


Item * criarItem (char *  Titulo, char * Autor, int Ano);
Lista * criarLista();
void exibirLista(Lista * L);

int main(){
    setlocale(LC_ALL, "Portuguese");
    
    Lista * Playlist = criarLista(); //Usando a função criarLista para alocar memoria para a variavel Playlist

    if(Playlist == NULL){
        printf("ERRO: SEM MEMORIA PARA A PLAYLIST\n");
        exit(1);
    }

    Musica * D = criarItem("Aquarela","Toquinho", 1983);
    Musica * E = criarItem("Romaria","Renato Teixeira", 1978);
    Musica * F = criarItem("Eu nasci há dez mil anos atrás","Raul Seixas", 1976);
    Musica * G = criarItem("Cálice","Chico Buarque e Gilberto Gil", 1978);
    Musica * H = criarItem("Tempo Perdido","Renato Russo", 1986);

    D->Anterior = NULL;
    D->Proximo = E;
    E->Anterior = D;
    E->Proximo = F;
    F->Anterior = E;
    F->Proximo = G;
    G->Anterior = F;
    G->Proximo = H;
    H->Anterior = G;
    H->Proximo = NULL;

    Playlist->Inicio = D;
    Playlist-> Tamanho = 5;

    exibirLista(Playlist);

    return 0;
}

Item * criarItem(char *  Titulo, char * Autor, int Ano){
    Item * I = (Item *) malloc(sizeof(Item));

    if( I == NULL){
        printf ("Erro");
        return NULL;
    }

    strcpy(I->Titulo, Titulo);
    strcpy(I->Autor, Autor);
    I->Ano = Ano;
    I -> Proximo = NULL;
    I -> Anterior = NULL;

    return I;
}

Lista * criarLista(){
    Lista * L = (Lista *) malloc(sizeof(Lista));

    if( L == NULL){
        printf("ERRO: SEM MEMORIA PARA A LISTA\n");
        return NULL;
    }

    L->Tamanho = 0;
    L->Inicio = NULL; //A lista está vazia, empty, sem nada

    return L;
}

void exibirLista(Lista * L){
   Item * Atual  = L->Inicio;

    while(Atual != NULL){
         printf("Titulo: %s\n", Atual->Titulo);
         printf("Autor: %s\n", Atual->Autor);
         printf("Ano: %d\n", Atual->Ano);
         printf("\n");
         Atual = Atual->Proximo;
    }


}