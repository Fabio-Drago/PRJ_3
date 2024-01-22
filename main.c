#include "tarefas.h"
#include <stdio.h>

int main() {
    PilhaTarefas pilha;
    inicializarPilha(&pilha);

    int opcao;
    do {
        printf("\n>>>> Menu: <<<<\n");
        printf("1. Adicionar Tarefa\n");
        printf("2. Concluir Tarefa\n");
        printf("3. Remover Tarefa\n");
        printf("4. Listar Tarefas\n");
        printf("5. Mostrar Tarefa mais Recente\n");
        printf("6. Fechar o Programa\n");

        printf("Escolha a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                {
                    int id, prioridade;
                    char descricao[50], data[15];
                    printf("Digite o ID da tarefa: ");
                    scanf("%d", &id);
                    printf("Digite a descricao da tarefa: ");
                    scanf(" %49[^\n]", descricao);
                    printf("Digite a data da tarefa (xx/xx/xxxx): ");
                    scanf(" %14[^\n]", data);
                    printf("Digite a prioridade da tarefa (1-5): ");
                    scanf("%d", &prioridade);
                    adicionarTarefa(&pilha, id, descricao, data, prioridade);
                    break;
                }
            case 2:
                concluirTarefa(&pilha);
                break;
            case 3:
                removerTarefa(&pilha);
                break;
            case 4:
                listarTarefas(&pilha);
                break;
            case 5:
                mostrarMaisRecente(&pilha);
                break;
            case 6:
                printf("Fechando o programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 6);

    liberarPilha(&pilha);
    return 0;
}
