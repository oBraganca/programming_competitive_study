#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char an[10];
    int bm;          // Base matriz
    int tb;          // Tamanho em bytes
    int c[11];       // Constantes para cálculo do deslocamento
    int t[10];       // Tamanho máximo de cada dimensão
    int n;           // Número de dimensões
    int d[10];       // Limite inferior de cada dimensão
} arr;

int main() {
    int n = 0, nr = 0;

    scanf("%d %d", &n, &nr);
    arr* ar = malloc(n * sizeof(arr));

    for (int i = 0; i < n; i++) {
        scanf("%s %d %d %d", ar[i].an, &ar[i].bm, &ar[i].tb, &ar[i].n);

        for (int j = 0; j < ar[i].n; j++) {
            scanf("%d %d", &ar[i].d[j], &ar[i].t[j]);
        }

        ar[i].c[ar[i].n] = ar[i].tb;
        for (int j = ar[i].n - 1; j >= 0; j--) {
            ar[i].c[j] = ar[i].c[j + 1] * (ar[i].t[j] - ar[i].d[j] + 1);
        }
    }

    char nm[10];
    unsigned long tt;

    for (int i = 0; i < nr; i++) {
        scanf("%s", nm);
        int a = -1;

        for (int j = 0; j < n; j++) {
            if (!strcmp(ar[j].an, nm)) {
                a = j;
                break;
            }
        }

        if (a == -1) {
            printf("Array %s não encontrado.\n", nm);
            continue;
        }

        tt = ar[a].bm;
        printf("%s[", ar[a].an);

        for (int j = 0; j < ar[a].n; j++) {
            int an;
            scanf("%d", &an);

            if (an < ar[a].d[j] || an > ar[a].t[j]) {
                printf("Índice %d fora do intervalo [%d, %d]\n", an, ar[a].d[j], ar[a].t[j]);
                return 1;
            }

            tt += ar[a].c[j + 1] * (an - ar[a].d[j]);
            printf("%d%s", an, (j == ar[a].n - 1) ? "" : ", ");
        }

        printf("] = %lu\n", tt);
    }

    free(ar);
    return 0;
}
