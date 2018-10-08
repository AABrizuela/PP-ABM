#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menuPrincipal.h"
#include "clientes.h"
#include "juegos.h"
#include "alquileres.h"

int main()
{
    int tamCliente = 100;
    int tamJuegos = 20;
    int tamAlquiler = 2000;
    eCliente listaClientes[tamCliente];
    eJuego listaJuegos[tamJuegos];
    eAlquiler listaAlquiler[tamAlquiler];

    inicializarClientes(listaClientes, tamCliente);

    menuPrincipal(listaClientes, tamCliente, listaJuegos, tamJuegos, listaAlquiler, tamAlquiler);

    return 0;
}
