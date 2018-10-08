#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED

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
    int idJuegoAlq;
    int idClienteAlq;
    eFecha fecha;
    int isEmptyAqluiler;
}eAlquiler;


#endif // ALQUILERES_H_INCLUDED
