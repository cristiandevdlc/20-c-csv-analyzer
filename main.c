#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc != 2) { printf("Uso: analyzer ventas.csv\n"); return 1; }
    FILE *file = fopen(argv[1], "r"); if (!file) { perror("No se pudo abrir"); return 1; }
    char line[512]; double total = 0, value, min = 0, max = 0; int count = 0;
    fgets(line, sizeof line, file);
    while (fgets(line, sizeof line, file)) {
        char *last = line; for (char *cursor = line; *cursor; cursor++) if (*cursor == ',') last = cursor + 1;
        value = atof(last); if (!count || value < min) min=value; if (!count || value > max) max=value; total += value; count++;
    }
    fclose(file); if (!count) { puts("Sin registros"); return 0; }
    printf("Registros: %d\nTotal: %.2f\nPromedio: %.2f\nMínimo: %.2f\nMáximo: %.2f\n", count, total, total/count, min, max); return 0;
}
