// Código de todas funções do gestor

#include "tarefas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializarPilha(PilhaTarefas* pilha) {
    pilha->topo = NULL;
}

void adicionarTarefa(PilhaTarefas* pilha, int id, const char* descricao, int dia, int mes, int ano, int prioridade) {
    Tarefa* novaTarefa = (Tarefa*)malloc(sizeof(Tarefa));

    if (novaTarefa == NULL) {
        printf("Erro ao alocar memória para a nova tarefa.\n");
        return;
    }

    novaTarefa->id = id;
    strncpy(novaTarefa->descricao, descricao, sizeof(novaTarefa->descricao));
    novaTarefa->dia = dia;
    novaTarefa->mes = mes;
    novaTarefa->ano = ano;
    novaTarefa->prioridade = prioridade;

    novaTarefa->proxima = pilha->topo;
    pilha->topo = novaTarefa;

    printf("Tarefa adicionada com sucesso.\n");
}

void concluirTarefa(PilhaTarefas* pilha) {
    if (pilhaVazia(pilha)) {
        printf("A pilha de tarefas está vazia. Nenhuma tarefa para concluir.\n");
        return;
    }

    Tarefa* tarefaConcluida = pilha->topo;
    pilha->topo = tarefaConcluida->proxima;

    free(tarefaConcluida);

    printf("Tarefa concluída com sucesso!\n");
}

void removerTarefa(PilhaTarefas* pilha) {
    if (pilhaVazia(pilha)) {
        printf("A pilha de tarefas está vazia. Nenhuma tarefa para remover.\n");
        return;
    }

    Tarefa* tarefaRemovida = pilha->topo;
    pilha->topo = tarefaRemovida->proxima;

    free(tarefaRemovida);

    printf("Tarefa removida com sucesso!\n");
}

void listarTarefas(PilhaTarefas* pilha) {
    if (pilhaVazia(pilha)) {
        printf("A pilha de tarefas está vazia. Nenhuma tarefa para listar.\n");
        return;
    }

    printf("Lista de Tarefas:\n");
    Tarefa* atual = pilha->topo;

    while (atual != NULL) {
        printf("ID: %d, Descrição: %s, Data: %02d/%02d/%04d, Prioridade: %d\n", atual->id, atual->descricao, atual->dia, atual->mes, atual->ano, atual->prioridade);
        atual = atual->proxima;
    }
}

void mostrarMaisRecente(PilhaTarefas* pilha) {
    if (pilhaVazia(pilha)) {
        printf("A pilha de tarefas está vazia. Nenhuma tarefa para mostrar.\n");
        return;
    }

    Tarefa* maisRecente = pilha->topo;
    printf("Tarefa mais recente:\n");
    printf("ID: %d, Descrição: %s, Data: %02d/%02d/%04d, Prioridade: %d\n", maisRecente->id, maisRecente->descricao, maisRecente->dia, maisRecente->mes, maisRecente->ano, maisRecente->prioridade);
}

int pilhaVazia(PilhaTarefas* pilha) {
    return (pilha->topo == NULL);
}

int tamanhoPilha(PilhaTarefas* pilha) {
    int tamanho = 0;
    Tarefa* atual = pilha->topo;

    while (atual != NULL) {
        tamanho++;
        atual = atual->proxima;
    }

    return tamanho;
}

void liberarPilha(PilhaTarefas* pilha) {
    Tarefa* atual = pilha->topo;
    Tarefa* proximo;

    while (atual != NULL) {
        proximo = atual->proxima;
        free(atual);
        atual = proximo;
    }

    pilha->topo = NULL;
}
