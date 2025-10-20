#include <stdio.h>
//Axel Hernandez y JuanPablo Toapanta.
int main() {
    int agenda[5][8] = {0};  
    const char *dias[5]  = {"Lun","Mar","Mie","Jue","Vie"};
    const char *horas[8] = {
        "09:00-10:00","10:00-11:00","11:00-12:00","13:00-14:00",
        "14:00-15:00","15:00-16:00","16:00-17:00", "17:00-18:00"
    };

    int opcion = -1;
    while (opcion != 4) {
        
        printf("\n------------ AGENDA DE JUANITO ------------\n");
        printf("1) Ver agenda completa\n");
        printf("2) Ver horarios disponibles por dia\n");
        printf("3) Agendar un contrato (reservar)\n");
        printf("4) Salir\n");
        printf("Elige una opcion: ");
        if (scanf("%d", &opcion) != 1) { 
            int c; while((c=getchar())!='\n' && c!=EOF);
            opcion = -1;
            continue;
        }

        if (opcion == 1) {
          
            int i, j;
            printf("\n       ");
            for (j = 0; j < 8; j++) printf(" [%d]%s ", j+1, horas[j]);
            printf("\n");
            for (i = 0; i < 5; i++) {
                printf("[%d]%s ", i+1, dias[i]);
                for (j = 0; j < 8; j++) {
                    printf("%15d", agenda[i][j]); 
                }
                printf("\n");
            }
            printf("\n(0 = libre, 1 = reservado)\n");
        }
        else if (opcion == 2) {
           
            int d, j, hay;
            printf("\nDia (1=Lun, 2=Mar, 3=Mie, 4=Jue o 5=Vie): ");
            if (scanf("%d", &d) != 1) { int c; 
                while((c=getchar())!='\n' && c!=EOF); 
                continue; }
            if (d < 1 || d > 5) { printf("Dia invalido.\n"); 
                continue; }
            d--; hay = 0;
            printf("Disponibles en %s:\n", dias[d]);
            for (j = 0; j < 8; j++) {
                if (agenda[d][j] == 0) {
                    printf("  Hora %d: %s\n", j+1, horas[j]);
                    hay = 1;
                }
            }
            if (!hay) printf("(No hay horarios libres este dia)\n");
        }
        else if (opcion == 3) {
          
            int d, h;
            printf("\nIngresa dia (1=Lun, 2=Mar, 3=Mie, 4=Jue o 5=Vie): ");
            if (scanf("%d", &d) != 1) { int c; 
                while((c=getchar())!='\n' && c!=EOF); 
                continue; }
            printf("Ingresa la hora requerida (1= 09:00-10:00, 2= 10:00-11:00, 3= 11:00-12:00, 4= 13:00-14:00, 5= 14:00-15:00, 6= 15:00-16:00, 7= 16:00-17:00, 8= 17:00-18:00): ");
            if (scanf("%d", &h) != 1) { int c; 
                while((c=getchar())!='\n' && c!=EOF); 
                continue; }

            if (d < 1 || d > 5 || h < 1 || h > 8) { printf("Rango invalido.\n"); 
                continue; }
            d--; h--;

            if (agenda[d][h] == 1) {
                printf("Existe un Conflicto: %s %s ya esta reservado.\n", dias[d], horas[h]);
            } else {
                agenda[d][h] = 1;
                printf("Reservado: %s %s.\n", dias[d], horas[h]);
            }
        }
      
        else if (opcion == 4) {
            printf("Saliendo...\n");
        }
        else {
            printf("Opcion invalida.\n");
        }
    }
    return 0;
}
