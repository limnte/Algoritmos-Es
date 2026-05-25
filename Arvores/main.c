#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int Valor;
    struct No * Esquerda;
    struct No * Direita;
}No;

typedef struct  Arvore{
    No * Raiz;
    int Altura;  
    int Grau;
    int NumeroNos;
    int NumeroFolhas;
} Arvore;

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
        fprintf(arquivo, "    node [shape=circle];\n\n");
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