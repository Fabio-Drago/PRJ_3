#include "tarefas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializarPilha(PilhaTarefas* pilha) {
    pilha->topo = NULL;
}

void adicionarTarefa(PilhaTarefas* pilha, int id, const char* descricao, const char* data, int prioridade) {
    Tarefa* novaTarefa = (Tarefa*)malloc(sizeof(Tarefa));
    novaTarefa->id = id;
    strcpy(novaTarefa->descricao, descricao);
    strcpy(novaTarefa->data, data);
    novaTarefa->prioridade = prioridade;
    novaTarefa->proxima = pilha->topo;
    pilha->topo = novaTarefa;
}

void concluirTarefa(PilhaTarefas* pilha) {
    if (pilha->topo != NULL) {
        Tarefa* tarefaConcluida = pilha->topo;
        pilha->topo = pilha->topo->proxima;
        free(tarefaConcluida);
        printf("Tarefa concluida com sucesso.\n");
    } else {
        printf("Pilha vazia. Nenhuma tarefa para concluir.\n");
    }
}

void removerTarefa(PilhaTarefas* pilha) {
    if (pilha->topo != NULL) {
        Tarefa* tarefaRemovida = pilha->topo;
        pilha->topo = pilha->topo->proxima;
        free(tarefaRemovida);
    } else {
        printf("Pilha vazia. Nenhuma tarefa para remover.\n");
    }
}

void listarTarefas(PilhaTarefas* pilha) {
    Tarefa* atual = pilha->topo;
    printf("Lista de Tarefas:\n");
    while (atual != NULL) {
        printf("ID: %d, Descricao: %s, Data: %s, Prioridade: %d\n",
               atual->id, atual->descricao, atual->data, atual->prioridade);
        atual = atual->proxima;
    }
}

void mostrarMaisRecente(PilhaTarefas* pilha) {
    if (pilha->topo != NULL) {
        Tarefa* tarefaRecente = pilha->topo;
        printf("Tarefa mais recente:\n");
        printf("ID: %d, Descricao: %s, Data: %s, Prioridade: %d\n",
               tarefaRecente->id, tarefaRecente->descricao, tarefaRecente->data, tarefaRecente->prioridade);
    } else {
        printf("Pilha vazia. Nenhuma tarefa disponivel.\n");
    }
}

int pilhaVazia(PilhaTarefas* pilha) {
    return (pilha->topo == NULL);
}

int tamanhoPilha(PilhaTarefas* pilha) {
    Tarefa* atual = pilha->topo;
    int tamanho = 0;
    while (atual != NULL) {
        tamanho++;
        atual = atual->proxima;
    }
    return tamanho;
}

void liberarPilha(PilhaTarefas* pilha) {
    while (pilha->topo != NULL) {
        Tarefa* proxima = pilha->topo->proxima;
        free(pilha->topo);
        pilha->topo = proxima;
    }
}
