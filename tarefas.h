// Código de tarefas.h

#ifndef TAREFAS_H
#define TAREFAS_H

typedef struct Tarefa {
    int id;
    char descricao[50];
    char data[15]; // Adicionando a data da tarefa
    int prioridade; // Adicionando a prioridade da tarefa
    struct Tarefa* proxima;
} Tarefa;

typedef struct {
    Tarefa* topo;
} PilhaTarefas;

void inicializarPilha(PilhaTarefas* pilha);
void adicionarTarefa(PilhaTarefas* pilha, int id, const char* descricao, const char* data, int prioridade);
void concluirTarefa(PilhaTarefas* pilha);
void removerTarefa(PilhaTarefas* pilha);
void listarTarefas(PilhaTarefas* pilha);
void mostrarMaisRecente(PilhaTarefas* pilha);
int pilhaVazia(PilhaTarefas* pilha);
int tamanhoPilha(PilhaTarefas* pilha);
void liberarPilha(PilhaTarefas* pilha);

#endif
