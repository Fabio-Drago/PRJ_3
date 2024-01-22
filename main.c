// Código principal (MAIN)

#include "tarefas.h"
#include "lop.h"
#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

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

        opcao = lerOpcao();

        switch (opcao) {
            case 1:
                {
                    int id, prioridade;
                    char descricao[50], data[15];
                    printf("Digite o ID da tarefa: ");
                    scanf("%d", &id);
                    printf("Digite a descrição da tarefa: ");
                    scanf("%s", descricao);
                    printf("Digite a data da tarefa (xx/xx/xxxx): ");
                    scanf("%s", data);
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
