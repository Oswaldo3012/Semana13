#ifndef FUNCIONES_H
#define FUNCIONES_H

#define ARCH_VEH "vehiculos.dat"
#define ARCH_VENT "ventas.dat"

typedef struct {
    int id;
    char marca[20];
    char tipo[20];
    char estado[10];
    float precio;
    int disponible;
} Vehiculo;

typedef struct {
    char cliente[30];
    int idVehiculo;
    float precioVenta;
} Venta;

/* Prototipos */
void agregarVehiculo();
void mostrarVehiculos();
void buscarVehiculos(char marca[], char tipo[], char estado[], float presupuesto);
void registrarVenta();

#endif
