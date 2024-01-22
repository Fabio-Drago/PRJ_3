// C�digo principal (MAIN)

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
                	//Vari�veis
                    int id, prioridade, dia, mes, ano;
                    char descricao[50];
                    
                    // Verifica��o da entrada para o ID
                    printf("Digite o ID da tarefa (apenas n�meros inteiros): ");
                    int inputResult = scanf("%d", &id);

                    // Verificando se a entrada � um n�mero inteiro
                    if (inputResult != 1) {
                        printf("Entrada inv�lida para o ID. Use apenas n�meros inteiros.\n");
                        continue;  // Retorna ao in�cio do loop
                    }
                    
                    // Verifica��o da entrada para a descri��o
                    printf("Digite a descri��o da tarefa: ");
                    scanf("%s", descricao);

                    // Verifica��o da entrada para o dia, m�s e ano
                    printf("Digite a data da tarefa (dd mm aaaa): ");
                    scanf("%d %d %d", &dia, &mes, &ano);
                    if (dia < 1 || dia > 31 || 
                        mes < 1 || mes > 12 || 
                        ano < 2000 || ano > 2100) {
                        printf("Formato ou valor de data inv�lido. Tarefa n�o adicionada.\n");
                        continue;  // Retorna ao in�cio do loop
                    }

                    // Verifica��o da entrada para a prioridade
                    printf("Digite a prioridade da tarefa (1-5): ");
                    scanf("%d", &prioridade);
                    if (prioridade < 1 || prioridade > 5) {
                        printf("Prioridade inv�lida. Tarefa n�o adicionada.\n");
                        continue;  // Retorna ao in�cio do loop
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
                printf("Op��o inv�lida. Tente novamente.\n");
        }

    } while (opcao != 6);

    liberarPilha(&pilha);
    return 0;
}
