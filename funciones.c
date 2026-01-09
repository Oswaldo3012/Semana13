#include <stdio.h>
#include <string.h>
#include "funciones.h"

void agregarVehiculo() {
    FILE *f = fopen(ARCH_VEH, "ab");
    Vehiculo v;

    if (!f) {
        printf("Error al abrir archivo.\n");
        return;
    }

    printf("ID: ");
    scanf("%d", &v.id);
    printf("Marca: ");
    scanf("%s", v.marca);
    printf("Tipo: ");
    scanf("%s", v.tipo);
    printf("Estado (Nuevo/Usado): ");
    scanf("%s", v.estado);
    printf("Precio: ");
    scanf("%f", &v.precio);

    v.disponible = 1;

    fwrite(&v, sizeof(Vehiculo), 1, f);
    fclose(f);

    printf("Vehículo agregado.\n");
}

void mostrarVehiculos() {
    FILE *f = fopen(ARCH_VEH, "rb");
    Vehiculo v;

    if (!f) {
        printf("No hay vehículos registrados.\n");
        return;
    }

    printf("\n--- INVENTARIO ---\n");
    while (fread(&v, sizeof(Vehiculo), 1, f)) {
        if (v.disponible) {
            printf("ID:%d | %s | %s | %s | $%.2f\n",
                   v.id, v.marca, v.tipo, v.estado, v.precio);
        }
    }

    fclose(f);
}

void buscarVehiculos(char marca[], char tipo[], char estado[], float presupuesto) {
    FILE *f = fopen(ARCH_VEH, "rb");
    Vehiculo v;
    int encontrado = 0;

    printf("\n--- RESULTADOS ---\n");
    while (fread(&v, sizeof(Vehiculo), 1, f)) {
        if (v.disponible &&
            strcmp(v.marca, marca) == 0 &&
            strcmp(v.tipo, tipo) == 0 &&
            strcmp(v.estado, estado) == 0 &&
            v.precio <= presupuesto) {

            printf("ID:%d | %s | $%.2f\n", v.id, v.marca, v.precio);
            encontrado = 1;
        }
    }

    if (!encontrado)
        printf("No se encontraron vehículos.\n");

    fclose(f);
}

void registrarVenta() {
    FILE *f = fopen(ARCH_VEH, "r+b");
    FILE *fv = fopen(ARCH_VENT, "ab");
    Vehiculo v;
    Venta venta;
    int id;

    if (!f || !fv) {
        printf("Error en archivos.\n");
        return;
    }

    printf("Nombre del cliente: ");
    scanf("%s", venta.cliente);
    printf("ID del vehículo: ");
    scanf("%d", &id);

    while (fread(&v, sizeof(Vehiculo), 1, f)) {
        if (v.id == id && v.disponible) {
            v.disponible = 0;
            fseek(f, -sizeof(Vehiculo), SEEK_CUR);
            fwrite(&v, sizeof(Vehiculo), 1, f);

            venta.idVehiculo = v.id;
            venta.precioVenta = v.precio;
            fwrite(&venta, sizeof(Venta), 1, fv);

            printf("Venta registrada correctamente.\n");
            fclose(f);
            fclose(fv);
            return;
        }
    }

    printf("Vehículo no disponible.\n");
    fclose(f);
    fclose(fv);
}
