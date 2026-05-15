#include <stdio.h>

void hanoi(int discos, char origem, char auxiliar, char destino, int *movimentos) {


    if (discos == 1) {
        printf("Mover disco 1 de %c para %c\n", origem, destino);
        (*movimentos)++;
        return;
    }

    hanoi(discos - 1, origem, destino, auxiliar, movimentos);

    printf("Mover disco %d de %c para %c\n", discos, origem, destino);
    (*movimentos)++;

    hanoi(discos - 1, auxiliar, origem, destino, movimentos);
}

int main() {
    int discos;
    int movimentos = 0;

    printf("Digite a quantidade de discos: ");
    scanf("%d", &discos);

    printf("\nMovimentos:\n");

    hanoi(discos, 'A', 'B', 'C', &movimentos);

    printf("\nTotal de movimentos: %d\n", movimentos);

    return 0;
}
