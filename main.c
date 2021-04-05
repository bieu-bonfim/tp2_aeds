#include <stdio.h>

void MenuInicial();
void MenuInterativo();
void MenuAutomatico();
void GerarCombinacoes(int n, int c, int arr[], int E[99][3][2], int i);
void PrintExpressao(int E[99][3][2], int c);
int CheckExpressao(int E[99][3][2], int arr[], int c);

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
//        MenuAutomatico();
    }

}

void MenuInterativo() {
    int c, n, ci, est;
    int E[99][3][2];
    int arr[99];

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

    GerarCombinacoes(n, c, arr, E, 0);
}

void PrintExpressao(int E[99][3][2], int c) {
    printf("E = ");
    for (int i = 0; i < c; i++) {
        printf("(");
        for (int j = 0; j < 3; j++) {
            if (E[i][j][1] == 1) {
                printf("X%d", E[i][j][0]);
            } else {
                printf("!X%d", E[i][j][0]);
            }
            if (j != 2) {
                printf(" | ");
            }
        }
        printf(")");
        if (i != c - 1) {
            printf(" & ");
        }
    }
}

void PrintCombinacoes(int arr[], int n, int E[99][3][2], int c)
{
    printf("{");
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            printf("V");
        } else {
            printf("F");
        }

        if (i != n - 1) {
            printf(", ");
        }
    }
    printf("}");
    int result = CheckExpressao(E, arr, c);
    printf(" = %d", result);
    printf("\n");
}

int CheckExpressao(int E[99][3][2], int arr[], int c) {
    int results[c];
    for (int i = 0; i < c; i++) {
        int c1, c2, c3;
        c1 = arr[E[i][0][0]];
        c2 = arr[E[i][1][0]];
        c3 = arr[E[i][2][0]];
        if (E[i][0][1] == 2) {
            c1 = 1 == c1 ? 0 : 1;
        }
        if (E[i][1][1] == 2) {
            c2 = 1 == c2 ? 0 : 1;
        }
        if (E[i][2][1] == 2) {
            c3 = 1 == c3 ? 0 : 1;
        }
        if (c1 | c2 | c3) {
            results[i] = 1;
        } else {
            results[i] = 0;
        }
    }

    for (int i = 0; i < c; ++i) {
        if (results[i] == 0) {
            return 0;
        }
    }

    return 1;
}

void GerarCombinacoes(int n, int c, int arr[], int E[99][3][2], int i)
{
    if (i == n) {
        PrintCombinacoes(arr, n, E, c);
        return;
    }

    // And then assign "1" at ith position
    // and try for all other permutations
    // for remaining positions
    arr[i] = 1;
    GerarCombinacoes(n, c, arr, E, i + 1);

    // First assign "0" at ith position
    // and try for all other permutations
    // for remaining positions
    arr[i] = 0;
    GerarCombinacoes(n, c, arr, E, i + 1);
}

int main() {

    int n;

//    printf("\nInsira a quantidade de variaveis: ");
//    scanf("%d", &n);



    MenuInicial();


    return 0;
}
