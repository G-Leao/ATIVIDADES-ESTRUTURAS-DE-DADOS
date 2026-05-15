#include <stdio.h>

int chamadas = 0;


int fibonacci(int n) {
    chamadas++;

    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;

    printf("Digite um valor para n: ");
    scanf("%d", &n);

    int resultado = fibonacci(n);

    printf("Fibonacci(%d) = %d\n", n, resultado);
    printf("Quantidade de chamadas recursivas: %d\n", chamadas);

    return 0;
}
