// Função que gera as combinacoes aleatorias
void GerarCombinacoes(int n, int c, int arr[], int E[99][3][2], int i);

// Função que imprime a expressão
void PrintExpressao(int E[99][3][2], int c);

// Verifica se a combinação de literais é válida para a expressão
int CheckExpressao(int E[99][3][2], int arr[], int c);

// Função que gera uma matriz aleatória, gerando uma nova expressão
void GerarMatriz(int n, int c);