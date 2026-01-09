#include <stdio.h>
#include "funciones.h"

int main() {
    int op;
    char marca[20], tipo[20], estado[10];
    float presupuesto;

    do {
        printf("\n--- SGIC RUEDAS DE ORO ---\n");
        printf("1. Agregar vehículo\n");
        printf("2. Mostrar vehículos\n");
        printf("3. Buscar vehículo\n");
        printf("4. Registrar venta\n");
        printf("0. Salir\n");
        printf("Opción: ");
        scanf("%d", &op);

        switch (op) {
        case 1:
            agregarVehiculo();
            break;
        case 2:
            mostrarVehiculos();
            break;
        case 3:
            printf("Marca: ");
            scanf("%s", marca);
            printf("Tipo: ");
            scanf("%s", tipo);
            printf("Estado: ");
            scanf("%s", estado);
            printf("Presupuesto máximo: ");
            scanf("%f", &presupuesto);
            buscarVehiculos(marca, tipo, estado, presupuesto);
            break;
        case 4:
            registrarVenta();
            break;
        }
    } while (op != 0);

    return 0;
}
