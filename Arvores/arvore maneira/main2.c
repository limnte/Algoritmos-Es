#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int Valor;
    struct No *Esquerda;
    struct No *Direita;
}No;

typedef struct arvore{
    No *Raiz;
    int altura;
    int grau;
    int NumeroFolhas;
    int NumeroNos;
}arvore;

No * criarNo(int valor);
void GerarGraphviz(No *Raiz, FILE *arquivo);

int main(){
    system("cls");

    No *A = criarNo(10);
    No *B = criarNo(12);
    No *C = criarNo(15);
    No *D = criarNo(16);
    No *E = criarNo(18);
    No *F = criarNo(20);

    A->Esquerda = B;
    A->Direita = C;

    B->Esquerda = D;
    B->Direita = E;

    C->Direita = F;    

    GerarGraphviz(A, NULL);

    return 0;
}

No * criarNo(int Valor){
    No* n = (No *) malloc(sizeof(No));

    if(n == NULL){
        printf("ERRO: Não foi possivel alocar memoria para o No %d", n);
        exit(1);
    }

    n -> Valor = Valor;
    n -> Esquerda = NULL;
    n-> Direita = NULL;

    return n;
}

void GerarGraphviz(No *Raiz, FILE *arquivo) {

    int raizInicial = 0;

    if (Raiz == NULL) {
        return;
    }

    if (arquivo == NULL) {

        raizInicial = 1;

        arquivo = fopen("arvore.dot", "w");

        if (arquivo == NULL) {
            printf("Erro ao criar arquivo.\n");
            return;
        }

        fprintf(arquivo, "digraph Arvore {\n");
        fprintf(arquivo, "     node [shape=box, style = filled,color=""#5553ca"", fillcolor=""];;\n\n");
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