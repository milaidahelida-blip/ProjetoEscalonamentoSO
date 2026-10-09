#include <stdio.h>

int main() {
    int n, quantum;
    int tempo[10], restante[10];
    int i, concluidos = 0;

    printf("Quantidade de processos (maximo 10): ");
    scanf("%d", &n);

    if (n < 1 || n > 10) {
        printf("Quantidade invalida!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Tempo de execucao do P%d: ", i + 1);
        scanf("%d", &tempo[i]);

        if (tempo[i] <= 0) {
            printf("Tempo invalido!\n");
            return 1;
        }

        restante[i] = tempo[i];
    }

    printf("Informe o quantum: ");
    scanf("%d", &quantum);

    if (quantum <= 0) {
        printf("Quantum invalido!\n");
        return 1;
    }

    printf("\n--- Escalonamento Round Robin ---\n");

    while (concluidos < n) {
        for (i = 0; i < n; i++) {
            if (restante[i] > 0) {

                if (restante[i] > quantum) {
                    restante[i] -= quantum;
                    printf("P%d executou por %d unidades.\n",
                           i + 1, quantum);
                } else {
                    printf("P%d executou por %d unidades e terminou.\n",
                           i + 1, restante[i]);

                    restante[i] = 0;
                    concluidos++;
                }
            }
        }
    }

    printf("\nTodos os processos foram concluidos!\n");

    return 0;
}
