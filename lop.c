//Estrutura da "LerOpc��o"
#include <stdio.h>

int lerOpcao() {
    int opcao;

    printf("Escolha a op��o desejada: ");
    while (scanf("%d", &opcao) != 1) {
        // Limpa o buffer de entrada
        while (getchar() != '\n');
        printf("Entrada inv�lida. Por favor, digite um n�mero: ");
    }

    return opcao;
}

