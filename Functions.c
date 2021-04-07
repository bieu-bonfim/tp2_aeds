#include "Functions.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

/*
 *  Geração da matriz como especificada no texto do trabalho prático.
 *  Conversão dessa matriz para o modelo que utilizamos em todas as funções.
 */

void GerarMatriz(int n, int c) {
    int M[c][n], val[3], E[100][3][2];
    int arr[100];

    for (int i = 0; i < c; i++) {
        for (int j = 0; j < n; j++) {
            M[i][j] = 0;
        }
    }

    srand(time(0));

    for (int i = 0; i < c; ++i) {

        int in, im;

        im = 0;

        for (in = 0; in < n && im < 3; ++in) {
            int rn = n - in;
            int rm = 3 - im;
            if (rand() % rn < rm) {
                val[im++] = in;
            }
        }

        // Criação da Matriz Especificada
        M[i][val[0]] = (rand() % 2) + 1;
        M[i][val[1]] = (rand() % 2) + 1;
        M[i][val[2]] = (rand() % 2) + 1;

        // Dados que serão enviados para as demais funções que ja aceitam esse tipo de armazenamento dos valores
        E[i][0][0] = val[0] + 1;
        E[i][0][1] = M[i][val[0]];
        E[i][1][0] = val[1] + 1;
        E[i][1][1] = M[i][val[1]];
        E[i][2][0] = val[2] + 1;
        E[i][2][1] = M[i][val[2]];
    }

    PrintExpressao(E, c);
    GerarCombinacoes(n, c, arr, E, 0);
}

void PrintExpressao(int E[][3][2], int c) {
    printf("E = ");
    for (int i = 0; i < c; i++) {
        printf("(");
        for (int j = 0; j < 3; j++) {
            if (E[i][j][1] == 2) {
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
    printf("\n");
}

void PrintCombinacoes(int arr[], int n, int E[][3][2], int c)
{
    int result = CheckExpressao(E, arr, c);
    if (result == 0) {
        return;
    }
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
    printf("  ");
}


/*
 *  Verificamos cada valor passado dos literais e comparamos dentro da expressão,
 *  caso o valor 1 seja encontrado pelo menos uma vez em cada cláusula, é verdadeiro.
 */

int CheckExpressao(int E[][3][2], int arr[], int c) {
    int results[c];
    for (int i = 0; i < c; i++) {

        int c1, c2, c3;
        c1 = arr[E[i][0][0]-1];
        c2 = arr[E[i][1][0]-1];
        c3 = arr[E[i][2][0]-1];

        if (E[i][0][1] == 1) {
            if (c1 == 1) {
                c1 = 0;
            } else {
                c1 = 1;
            }
        }
        if (E[i][1][1] == 1) {
            if (c2 == 1) {
                c2 = 0;
            } else {
                c2 = 1;
            }
        }
        if (E[i][2][1] == 1) {
            if (c3 == 1) {
                c3 = 0;
            } else {
                c3 = 1;
            }
        }
        if (c1 == 1| c2 == 1| c3 == 1) {
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

/*
 * Buscamos na internet e encontramos um algoritmo que gera todas as strings binarias possíveis
 * com o numero de bits especificado.
 * A cada geração, verificamos se satisfaz a equação e então printamos caso essa condição seja verdadeira.
*/

// https://www.geeksforgeeks.org/generate-all-the-binary-strings-of-n-bits/

void GerarCombinacoes(int n, int c, int arr[], int E[][3][2], int i)
{
    if (i == n) {
        PrintCombinacoes(arr, n, E, c);
        return;
    }

    arr[i] = 1;
    GerarCombinacoes(n, c, arr, E, i + 1);

    arr[i] = 0;
    GerarCombinacoes(n, c, arr, E, i + 1);
}