#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED

#define CANT_ALQUILERES 2000

#include "clientes.h"
#include "juegos.h"

typedef struct{
    int day;
    int month;
    int year;
}eFecha;

typedef struct{
    int codigoAlquiler;
    int codigoJuego;
    int codigoCliente;
    eFecha fechaAlquiler;
    int isEmpty;
}eAlquiler;

void alquilerMenu(eAlquiler *pAlquileres, int largoAlquileres, eJuego *pJuegos, int largoJuegos, eCliente *pClientes, int largoClientes, int hayClientes, int hayJuegos);
int inicializarAlquileres(eAlquiler *pAlquileres, int largoAlquileres);
void listarAlquiler(eAlquiler *pAlquileres, int largoAlquileres, eJuego *pJuegos, int largoJuegos, eCliente *pClientes, int largoClientes);
int nuevoAlquilerJuego(eAlquiler *pAlquileres, int largoAlquileres, eJuego *pJuegos, int largoJuegos, eCliente *pClientes, int largoClientes, int indiceAlquiler);
int nuevoCodigoAlquiler(void);
int posicionLibreAlquiler(eAlquiler *pAlquileres, int largoAlquileres);

#endif // ALQUILERES_H_INCLUDED
