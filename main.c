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
                	//Variáveis
                    int id, prioridade, dia, mes, ano;
                    char descricao[50];
                    
                    // Verificação da entrada para o ID
                    printf("Digite o ID da tarefa (apenas números inteiros): ");
                    int inputResult = scanf("%d", &id);

                    // Verificando se a entrada é um número inteiro
                    if (inputResult != 1) {
                        printf("Entrada inválida para o ID. Use apenas números inteiros.\n");
                        continue;  // Retorna ao início do loop
                    }
                    
                    // Verificação da entrada para a descrição
                    printf("Digite a descrição da tarefa: ");
                    scanf("%s", descricao);

                    // Verificação da entrada para o dia, mês e ano
                    printf("Digite a data da tarefa (dd mm aaaa): ");
                    scanf("%d %d %d", &dia, &mes, &ano);
                    if (dia < 1 || dia > 31 || 
                        mes < 1 || mes > 12 || 
                        ano < 2000 || ano > 2100) {
                        printf("Formato ou valor de data inválido. Tarefa não adicionada.\n");
                        continue;  // Retorna ao início do loop
                    }

                    // Verificação da entrada para a prioridade
                    printf("Digite a prioridade da tarefa (1-5): ");
                    scanf("%d", &prioridade);
                    if (prioridade < 1 || prioridade > 5) {
                        printf("Prioridade inválida. Tarefa não adicionada.\n");
                        continue;  // Retorna ao início do loop
                    }

                    adicionarTarefa(&pilha, id, descricao, dia, mes, ano, prioridade);
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
