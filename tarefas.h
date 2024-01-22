// Cabeçalho das tarefas

#ifndef TAREFAS_H
#define TAREFAS_H

//Declarando as variáveis
typedef struct Tarefa {
    int id;
    char descricao[50];
    int dia;
    int mes;
    int ano;
    int prioridade;
    struct Tarefa* proxima;
} Tarefa;

typedef struct {
    Tarefa* topo;
} PilhaTarefas;

void inicializarPilha(PilhaTarefas* pilha);
void adicionarTarefa(PilhaTarefas* pilha, int id, const char* descricao, int dia, int mes, int ano, int prioridade);
void concluirTarefa(PilhaTarefas* pilha);
void removerTarefa(PilhaTarefas* pilha);
void listarTarefas(PilhaTarefas* pilha);
void mostrarMaisRecente(PilhaTarefas* pilha);
int pilhaVazia(PilhaTarefas* pilha);
int tamanhoPilha(PilhaTarefas* pilha);
void liberarPilha(PilhaTarefas* pilha);

#endif
