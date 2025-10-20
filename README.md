/* Agenda semanal de Juanito (sin funciones ni structs) */
/* Compila:  gcc agenda.c -o agenda  &&  ./agenda */

#include <stdio.h>

int main() {
    int agenda[5][8] = {0};  /* 0 = libre, 1 = reservado */
    const char *dias[5]  = {"Lun","Mar","Mie","Jue","Vie"};
    const char *horas[8] = {
        "09:00-10:00","10:00-11:00","11:00-12:00","12:00-13:00",
        "13:00-14:00","14:00-15:00","15:00-16:00","16:00-17:00"
    };

    int opcion = -1;
    while (opcion != 5) {
        /* Menú principal */
        printf("\n========== AGENDA DE JUANITO (Paseo de Perros) ==========\n");
        printf("1) Ver agenda completa\n");
        printf("2) Ver horarios disponibles por dia\n");
        printf("3) Agendar un contrato (reservar)\n");
        printf("4) Liberar un horario (cancelar)\n");
        printf("5) Salir\n");
        printf("Elige una opcion: ");
        if (scanf("%d", &opcion) != 1) { /* limpieza de entrada invalida */
            int c; while((c=getchar())!='\n' && c!=EOF);
            opcion = -1;
            continue;
        }

        if (opcion == 1) {
            /* Mostrar la matriz de la agenda */
            int i, j;
            printf("\n       ");
            for (j = 0; j < 8; j++) printf(" [%d]%s ", j+1, horas[j]);
            printf("\n");
            for (i = 0; i < 5; i++) {
                printf("[%d]%s ", i+1, dias[i]);
                for (j = 0; j < 8; j++) {
                    printf("     %d      ", agenda[i][j]); /* 0 libre, 1 ocupado */
                }
                printf("\n");
            }
            printf("\n(0 = libre, 1 = reservado)\n");
        }
        else if (opcion == 2) {
            /* Consultar disponibles por día */
            int d, j, hay;
            printf("\nDia (1=Lun ... 5=Vie): ");
            if (scanf("%d", &d) != 1) { int c; while((c=getchar())!='\n' && c!=EOF); continue; }
            if (d < 1 || d > 5) { printf("Dia invalido.\n"); continue; }
            d--; hay = 0;
            printf("Disponibles en %s:\n", dias[d]);
            for (j = 0; j < 8; j++) {
                if (agenda[d][j] == 0) {
                    printf("  Hora %d: %s\n", j+1, horas[j]);
                    hay = 1;
                }
            }
            if (!hay) printf("  (No hay horarios libres este dia)\n");
        }
        else if (opcion == 3) {
            /* Agendar (reservar) */
            int d, h;
            printf("\nIngresa dia (1=Lun ... 5=Vie): ");
            if (scanf("%d", &d) != 1) { int c; while((c=getchar())!='\n' && c!=EOF); continue; }
            printf("Ingresa franja horaria (1..8): ");
            if (scanf("%d", &h) != 1) { int c; while((c=getchar())!='\n' && c!=EOF); continue; }

            if (d < 1 || d > 5 || h < 1 || h > 8) { printf("Rango invalido.\n"); continue; }
            d--; h--;

            if (agenda[d][h] == 1) {
                printf("Conflicto: %s %s ya esta reservado.\n", dias[d], horas[h]);
            } else {
                agenda[d][h] = 1;
                printf("Reservado: %s %s.\n", dias[d], horas[h]);
            }
        }
        else if (opcion == 4) {
            /* Liberar (cancelar) */
            int d, h;
            printf("\nIngresa dia (1=Lun ... 5=Vie): ");
            if (scanf("%d", &d) != 1) { int c; while((c=getchar())!='\n' && c!=EOF); continue; }
            printf("Ingresa franja horaria (1..8): ");
            if (scanf("%d", &h) != 1) { int c; while((c=getchar())!='\n' && c!=EOF); continue; }

            if (d < 1 || d > 5 || h < 1 || h > 8) { printf("Rango invalido.\n"); continue; }
            d--; h--;

            if (agenda[d][h] == 0) {
                printf("Ese horario ya estaba libre.\n");
            } else {
                agenda[d][h] = 0;
                printf("Se libero: %s %s.\n", dias[d], horas[h]);
            }
        }
        else if (opcion == 5) {
            printf("Saliendo...\n");
        }
        else {
            printf("Opcion invalida.\n");
        }
    }
    return 0;
}
