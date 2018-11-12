/*******************************************************************
*Programa: ABM
*
*Objetivo:
    Ingresar datos de clientes y juegos, y en base a esos datos
    hacer alquileres. Listar diferentes informes.

*
*Version del 10 de octubre de 2018
*Autor: Adrian Brizuela
*
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "juegos.h"
#include "clientes.h"
#include "menuPrincipal.h"
#include "alquileres.h"
#include "utn.h"


int main()
{
    int tamCliente = 100;
    int tamJuegos = 20;
    int tamAlquiler = 2000;
    eCliente listaClientes[tamCliente];
    eJuego listaJuegos[tamJuegos];
    eAlquiler listaAlquiler[tamAlquiler];

    inicializarClientes(listaClientes, tamCliente);
    inicializarJuegos(listaJuegos, tamJuegos);

    menuPrincipal(listaClientes, tamCliente, listaJuegos, tamJuegos, listaAlquiler, tamAlquiler);

    return 0;
}
