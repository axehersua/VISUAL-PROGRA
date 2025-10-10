#include <stdio.h>
#include <string.h>

int main() {
    int id, stock, opcion, cantidad;
    char nombre[50];
    float precio, ganancias = 0.0, descuento, precioFinal;

    printf("Ingrese el ID del producto: ");
    scanf("%d", &id);
    printf("Ingrese el nombre del producto (sin espacios): ");
    scanf("%s", nombre);
    printf("Ingrese la cantidad en stock: ");
    scanf("%d", &stock);
    printf("Ingrese el precio unitario: ");
    scanf("%f", &precio);

    do {
        printf("\n--- MENU ---\n");
        printf("1. Vender producto\n");
        printf("2. Reabastecer stock\n");
        printf("3. Consultar informacion\n");
        printf("4. Mostrar ganancias\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            printf("Ingrese la cantidad a vender: ");
            scanf("%d", &cantidad);
            if (cantidad <= 0) {
                printf("Cantidad invalida.\n");
            } else if (cantidad > stock) {
                printf("Error: stock insuficiente.\n");
            } else {
                printf("Ingrese descuento (0 a 100%%): ");
                scanf("%f", &descuento);
                if (descuento < 0 || descuento > 100) {
                    printf("Descuento invalido, se aplicara 0%%.\n");
                    descuento = 0;
                }
                precioFinal = precio - (precio * descuento / 100);
                stock -= cantidad;
                ganancias += cantidad * precioFinal;
                printf("Venta realizada con exito.\n");
            }
        } 
        else if (opcion == 2) {
            printf("Ingrese la cantidad a reabastecer: ");
            scanf("%d", &cantidad);
            if (cantidad > 0) {
                stock += cantidad;
                printf("Stock actualizado.\n");
            } else {
                printf("Cantidad invalida.\n");
            }
        } 
        else if (opcion == 3) {
            printf("\n--- INFORMACION DEL PRODUCTO ---\n");
            printf("ID: %d\n", id);
            printf("Nombre: %s\n", nombre);
            printf("Stock: %d\n", stock);
            printf("Precio unitario: %.2f\n", precio);
        } 
        else if (opcion == 4) {
            printf("Ganancias acumuladas: %.2f\n", ganancias);
        } 
        else if (opcion == 5) {
            printf("Saliendo del programa...\n");
        } 
        else {
            printf("Opcion invalida.\n");
        }

    } while(opcion != 5);

    return 0;
}