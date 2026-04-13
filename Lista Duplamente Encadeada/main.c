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

Item * criarItem (char *  Titulo, char * Autor, int Ano);
void ExibirLista(Item * Inicio);


int main(){
    setlocale(LC_ALL, "Portuguese");

    Musica * D = criarItem("Aquarela","Toquinho", 1983);
    Musica * E = criarItem("Romaria","Renato Teixeira", 1978);
    Musica * F = criarItem("Eu nasci há dez mil anos atrás","Raul Seixas", 1976);
    Musica * G = criarItem("Cálice","Chico Buarque e Gilberto Gil", 1978);
    Musica * H = criarItem("Tempo Perdido","Renato Russo", 1986);

    D->Proximo = E;
    
    E->Proximo = F;
    E->Anterior = D;

    F->Proximo = G;
    F->Anterior = E;

    G->Proximo = H;
    G->Anterior = F;

    H->Proximo = NULL;

    Musica * i = criarItem("Velha Infância","Nando Reis", 2002);
    i->Proximo = D;
    i->Anterior = NULL;
    D->Anterior = i;

    Musica * J = criarItem("É","Gonzaguinha",1990);
    G -> Proximo = J;
    J -> Anterior = G;
    J -> Proximo = H;
    H -> Anterior = J;
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

void ExibirLista(Item * I){
    while ( I != NULL){
       printf("%d \t %s\t %s \n", I->Ano, I->Titulo, I->Autor );
    }
};