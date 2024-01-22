//Estrutura da "LerOpcção"
#include <stdio.h>

int lerOpcao() {
    int opcao;

    printf("Escolha a opção desejada: ");
    while (scanf("%d", &opcao) != 1) {
        // Limpa o buffer de entrada
        while (getchar() != '\n');
        printf("Entrada inválida. Por favor, digite um número: ");
    }

    return opcao;
}

