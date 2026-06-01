#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int Valor;
    struct No * Esquerda;
    struct No * Direita;
} No;

No * CriarNo (int Valor);
No * InserirNo(No * Raiz, int Valor);

void PreOrdem(No * Raiz);
void PosOrdem(No * Raiz);
void OrdemCentral(No * Raiz);

void GerarGraphviz(No *Raiz, FILE *arquivo);

int main() {

    system("cls");

    No * Raiz = CriarNo(50);

    InserirNo(Raiz, 30);
    InserirNo(Raiz, 70);
    InserirNo(Raiz, 20);
    InserirNo(Raiz, 40);
    InserirNo(Raiz, 60);
    InserirNo(Raiz, 80);

    printf("\nPercurso em Pre-Ordem: ");
    PreOrdem(Raiz);

    printf("\nPercurso em Pos-Ordem: ");
    PosOrdem(Raiz);

    printf("\nPercurso em Ordem Central: ");
    OrdemCentral(Raiz);

    GerarGraphviz(Raiz, NULL);

    return 0;
}

No * CriarNo (int Valor) {

    No * N = (No *) malloc (sizeof(No));

    if (N == NULL) {
        printf("ERRO: não há memória para armazenar um nó!\n");
        return NULL;
    }

    N->Valor = Valor;
    N->Esquerda = NULL;
    N->Direita = NULL;

    return N;

}


void GerarGraphviz(No *Raiz, FILE *arquivo) {

    int raizInicial = 0;

    if (Raiz == NULL) return;

    if (arquivo == NULL) {

        raizInicial = 1;

        arquivo = fopen("arvore.dot", "w");

        if (arquivo == NULL) {
            printf("Erro ao criar arquivo.\n");
            return;
        }

        fprintf(arquivo, "digraph Arvore {\n");
        fprintf(arquivo, "    node [shape=box];\n\n");
    }

    fprintf(arquivo,
            "    \"%p\" [label=\"%d\"];\n",
            (void *)Raiz,
            Raiz->Valor);

    if (Raiz->Esquerda != NULL) {

        fprintf(arquivo,
                "    \"%p\" -> \"%p\";\n",
                (void *)Raiz,
                (void *)Raiz->Esquerda);

        GerarGraphviz(Raiz->Esquerda, arquivo);
    }

    if (Raiz->Direita != NULL) {

        fprintf(arquivo,
                "    \"%p\" -> \"%p\";\n",
                (void *)Raiz,
                (void *)Raiz->Direita);

        GerarGraphviz(Raiz->Direita, arquivo);
    }

    if (raizInicial) {

        fprintf(arquivo, "}\n");

        fclose(arquivo);
    }
}

No * InserirNo(No * Raiz, int Valor) {

    if (Raiz == NULL) return CriarNo(Valor);
    if (Valor < Raiz->Valor) Raiz->Esquerda = InserirNo(Raiz->Esquerda, Valor);
    else Raiz->Direita = InserirNo(Raiz->Direita, Valor);
    
    return Raiz;

}

void PreOrdem(No* Raiz){
    if(Raiz != NULL){
        printf("%d \t", Raiz->Valor);
        PreOrdem(Raiz->Esquerda);
        PreOrdem(Raiz->Direita);
    }
}

void PosOrdem(No* Raiz){
    if(Raiz != NULL){
        PosOrdem(Raiz->Esquerda);
        PosOrdem(Raiz->Direita);
        printf("%d \t", Raiz->Valor);
    }
}

void OrdemCentral(No* Raiz){
    if(Raiz != NULL){
        OrdemCentral(Raiz->Esquerda);
        printf("%d \t", Raiz->Valor);
        OrdemCentral(Raiz->Direita);
    }
}