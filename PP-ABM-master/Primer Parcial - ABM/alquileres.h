#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED

#include "juegos.h"
#include "clientes.h"

typedef struct
{
    int dia;
    int mes;
    int anio;
    int isEmpty;
}eFecha;

typedef struct
{
    int idAlquiler;
    eJuego* idJuegoAlq;
    eCliente* idClienteAlq;
    eFecha* fecha;
    int isEmptyAqluiler;
}eAlquiler;


#endif // ALQUILERES_H_INCLUDED
