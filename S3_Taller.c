#include <stdio.h>
//Axel Hernandez y Juan Pablo Toapanta
#define ESTUDIANTES 5
#define ASIGNATURAS 3

int main() {
    float notas[ESTUDIANTES][ASIGNATURAS];
    float promedioEstudiante[ESTUDIANTES];
    float promedioAsignatura[ASIGNATURAS];
    float mayorEstudiante[ESTUDIANTES], menorEstudiante[ESTUDIANTES];
    float mayorAsignatura[ASIGNATURAS], menorAsignatura[ASIGNATURAS];
    int aprobados[ASIGNATURAS] = {0}, reprobados[ASIGNATURAS] = {0};

    printf("=== GESTION DE CALIFICACIONES ===\n\n");

    // 1. Ingreso de notas con validación
    for (int i = 0; i < ESTUDIANTES; i++) {
        printf("\n--- Estudiante %d ---\n", i + 1);
        for (int j = 0; j < ASIGNATURAS; j++) {
            do {
                printf("Por favor, ingrese la nota de la asignatura %d (0 - 10): ", j + 1);
                scanf("%f", &notas[i][j]);
                if (notas[i][j] < 0 || notas[i][j] > 10)
                    printf("La nota es invalida, por favor ingrese nuevamente.\n");
            } while (notas[i][j] < 0 || notas[i][j] > 10);
        }
    }

    // 2. Promedio, mayor y menor por estudiante
    for (int i = 0; i < ESTUDIANTES; i++) {
        float suma = 0;
        mayorEstudiante[i] = notas[i][0];
        menorEstudiante[i] = notas[i][0];
        for (int j = 0; j < ASIGNATURAS; j++) {
            suma += notas[i][j];
            if (notas[i][j] > mayorEstudiante[i]) mayorEstudiante[i] = notas[i][j];
            if (notas[i][j] < menorEstudiante[i]) menorEstudiante[i] = notas[i][j];
        }
        promedioEstudiante[i] = suma / ASIGNATURAS;
    }

    // 3. Promedio, mayor, menor y aprobados por asignatura
    for (int j = 0; j < ASIGNATURAS; j++) {
        float suma = 0;
        mayorAsignatura[j] = notas[0][j];
        menorAsignatura[j] = notas[0][j];
        for (int i = 0; i < ESTUDIANTES; i++) {
            suma += notas[i][j];
            if (notas[i][j] > mayorAsignatura[j]) mayorAsignatura[j] = notas[i][j];
            if (notas[i][j] < menorAsignatura[j]) menorAsignatura[j] = notas[i][j];
            if (notas[i][j] >= 6)
                aprobados[j]++;
            else
                reprobados[j]++;
        }
        promedioAsignatura[j] = suma / ESTUDIANTES;
    }

    // 4. Mostrar resultados
    printf("\n=== RESULTADOS ===\n");

    printf("\nPromedios, notas altas y bajas por estudiante:\n");
    for (int i = 0; i < ESTUDIANTES; i++) {
        printf("Estudiante %d -> Promedio: %.2f | Mas alta: %.2f | Mas baja: %.2f\n",
               i + 1, promedioEstudiante[i], mayorEstudiante[i], menorEstudiante[i]);
    }

    printf("\nPromedios, notas altas y bajas por asignatura:\n");
    for (int j = 0; j < ASIGNATURAS; j++) {
        printf("Asignatura %d -> Promedio: %.2f | Mas alta: %.2f | Mas baja: %.2f | Aprobados: %d | Reprobados: %d\n",
               j + 1, promedioAsignatura[j], mayorAsignatura[j], menorAsignatura[j], aprobados[j], reprobados[j]);
    }

    printf("\n=== FIN DEL PROGRAMA ===\n");
    return 0;
}
