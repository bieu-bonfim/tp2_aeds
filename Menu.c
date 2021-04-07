#include <stdio.h>
#include <time.h>
#include "Menu.h"
#include "Functions.h"

void MenuInicial() {
    int opcao;

    printf("\n----- Bem Vinde ao -----");
    printf("\n-------- Sistema -------");
    printf("\n------------------------");

    printf("\n\n1 - Menu Interativo");
    printf("\n2 - Menu Automatico");

    printf("\n\nEscolha o modo de uso: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        MenuInterativo();
    } else if (opcao == 2) {
        MenuAutomatico();
    }

}

void MenuAutomatico() {
    int n, c;

    printf("\n------------------------");
    printf("\n--- Menu  Automatico ---");
    printf("\n------------------------");

    printf("\n\nInsira o valor de N: ");
    scanf("%d", &n);

    c = (n/3)*2;

    clock_t t;
    
    // Início da contagem de tempo para gerar os resultados
    t = clock();

    GerarMatriz(n, c);

    // Fim da contagem de tempo para gerar os resultados
    t = clock() - t;
    
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("\n A combinacao levou %f segundos para ser executado. \n", time_taken);

    int opcao;

    printf("\n\n1 - Voltar ao Menu Interativo");
    printf("\n2 - Voltar ao Menu Inicial");
    printf("\n\nOpcao escolhida: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        MenuAutomatico();
    } else {
        MenuInicial();
    }
}

void MenuInterativo() {
    int c, n, ci, est;
    int E[100][3][2];
    int arr[100];

    printf("\n------------------------");
    printf("\n--- Menu  Interativo ---");
    printf("\n------------------------");

    printf("\n\nInsira o numero de clausulas: ");
    scanf("%d", &c);
    printf("\n\nInsira o numero de literais: ");
    scanf("%d", &n);

    for (int i = 0; i < c; i++) {

        printf("\n------------------------");
        printf("\n------ Clausula %d ------", i+1);
        printf("\n------------------------\n");

        for (int j = 0; j < 3; j++) {
            printf("\nIdentificador do literal: ");
            scanf("%d", &ci);
            printf("\nEstado do literal: ");
            scanf("%d", &est);

            E[i][j][0] = ci;
            E[i][j][1] = est;
        }
    }

    PrintExpressao(E, c);

    clock_t t;
    
    // Início da contagem de tempo para gerar os resultados
    t = clock();

    GerarCombinacoes(n, c, arr, E, 0);

    // Fim da contagem de tempo para gerar os resultados
    t = clock() - t;
    
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("\n A combinacaao levou %f segundos para ser executada. \n", time_taken);
    
    int opcao;

    printf("\n\n1 - Voltar ao Menu Interativo");
    printf("\n2 - Voltar ao Menu Inicial");
    printf("\n\nOpcao escolhida: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        MenuInterativo();
    } else {
        MenuInicial();
    }
}

