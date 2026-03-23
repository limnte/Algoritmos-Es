#ifndef LISTA_H
#define LISTA_H

#define TAM_TITULO 96
#define TAM_RESP 48

// Definições de status
#define A_FAZER 0
#define EM_ANDAMENTO 1
#define FEITO 2

//Estrutura que define uma tarefa
typedef struct{

    char Titulo[TAM_TITULO];
    char Responsavel[TAM_RESP];
    int Status;
    float Progresso; //de 0% (0) até 100% (1)
    int Avaliacao; //inteiro de 1 até 5 (baixa-alta)

} Tarefa;

Tarefa CriarTarefa(char * Titulo, char * Responsavel, int Status, float Progresso, int Avaliacao);
void ExibirTarefa(Tarefa T);

//Estrutura da lista
typedef struct{

    Tarefa * Dados; //Vetor de tarefas
    int Tamanho; //Numero de tarefas insidaras na lista
    int Capacidade; //Numero maximo de tarefas que a lista pode ter

} Lista;

Lista * CriarLista (int C); //Criar uma lista de capacidade C

void DestruirLista (Lista * L);
void AdicionarTarefa (Lista * L, Tarefa T);
void RemoverTarefa(Lista * L, int Indice);
void GerarHTMLTabela(Lista *Lista, char *CaminhoArquivo);


#endif