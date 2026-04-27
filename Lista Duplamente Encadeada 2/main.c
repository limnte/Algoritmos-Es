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
    Item * Inicio;
    Item * Fim;
}Lista;


Item * criarItem (char *  Titulo, char * Autor, int Ano);
Lista * criarLista();
void exibirLista(Lista * L);
void exibirListaDecrescente(Lista * L);

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
    Musica * I = criarItem("Kelly Key","Yung Lixo", 2019);

    //Encadeamento das musicas em ordem cronologica

    //F, G, E, D, H 

    F->Anterior = NULL;
    F->Proximo = G;

    G->Anterior = F;
    G->Proximo = E;

    E->Anterior = G;
    E->Proximo = D;

    D->Anterior = E;
    D->Proximo = H;

    H->Anterior = D;
    H->Proximo = I;

    I->Anterior = H;
    I->Proximo = NULL;

    Playlist->Inicio = F;
    Playlist->Fim = I;
    Playlist-> Tamanho = 6;

    int op;

    do{
        system("cls");

        printf("1- Exibir a playlist em ordem cronologica\n");
        printf("2- Exibir a playlist em ordem cronoligica decrescente\n");
        printf("0- Sair\n");
        printf("\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &op);

        switch(op){
            case 1:
                system("cls");
                printf("Playlist em ordem cronologica:\n\n");
                exibirLista(Playlist);
                system("pause");
                break;
            case 2:
                system("cls");
                printf("Playlist em ordem cronologica decrescente:\n\n");
                exibirListaDecrescente(Playlist);
                system("pause");
                break;
            case 0:
                printf("Saindo...\n\n");
                exit(0);
            default:
                printf("Opção inválida. Tente novamente.\n\n");
                system("pause");
        }

    }while(op != 0);

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
         printf("Ano: %d\n", Atual->Ano);
         printf("Titulo: %s\n", Atual->Titulo);
         printf("Autor: %s\n", Atual->Autor);
         printf("\n");
         Atual = Atual->Proximo;
    }
}

void exibirListaDecrescente(Lista * L){
    Item * Atual  = L->Fim;

    while(Atual != NULL){
         printf("Ano: %d\n", Atual->Ano);
         printf("Titulo: %s\n", Atual->Titulo);
         printf("Autor: %s\n", Atual->Autor);
         printf("\n");
         Atual = Atual->Anterior;
    }
}