#include <stdio.h>
#include <stdlib.h>

int chamadasIngenua = 0;
int chamadasMemo = 0;

// =========================
// Fibonacci Ingênua
// =========================

// Caso base:
// Se n for 0 ou 1, retorna o próprio valor.
// Redução:
// Divide em fibonacciIngenua(n-1) e fibonacciIngenua(n-2).
int fibonacciIngenua(int n) {
    chamadasIngenua++;

    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    return fibonacciIngenua(n - 1) + fibonacciIngenua(n - 2);
}

// =========================
// Fibonacci Memoizada
// =========================

// Caso base:
// Se n for 0 ou 1, retorna o próprio valor.
// Redução:
// Resolve fibonacciMemo(n-1) e fibonacciMemo(n-2),
// armazenando resultados já calculados.
int fibonacciMemo(int n, int *cache) {
    chamadasMemo++;

    if (cache[n] != -1)
        return cache[n];

    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    cache[n] = fibonacciMemo(n - 1, cache) +
               fibonacciMemo(n - 2, cache);

    return cache[n];
}

int main() {
    int n;

    printf("Digite um valor para n: ");
    scanf("%d", &n);

    // Fibonacci ingênua
    int resultadoIngenua = fibonacciIngenua(n);

    // Alocação dinâmica do cache
    int *cache = (int *) malloc((n + 1) * sizeof(int));

    for (int i = 0; i <= n; i++) {
        cache[i] = -1;
    }

    // Fibonacci memoizada
    int resultadoMemo = fibonacciMemo(n, cache);

    printf("\n=== RESULTADOS ===\n");

    printf("Fibonacci Ingenua(%d) = %d\n", n, resultadoIngenua);
    printf("Chamadas da versao ingenua: %d\n\n", chamadasIngenua);

    printf("Fibonacci Memoizada(%d) = %d\n", n, resultadoMemo);
    printf("Chamadas da versao memoizada: %d\n", chamadasMemo);

    free(cache);

    return 0;
}
