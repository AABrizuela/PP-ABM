#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "clientes.h"
#include "juegos.h"
#include "menuprincipal.h"
#include "alquileres.h"


void menuPrincipal(eCliente listaClientes[], int tamCliente, eJuego listaJuegos[], int tamJuegos, eAlquiler listaAlquiler[], int tamAlquiler)
{
    int opcionMenuPrincipal = 0;

    do
	{
		system("cls");
		printf("*** Bienvenido al ABM ***\n\n");
		printf("Menu principal.\n\n");

		printf("1.- Clientes.\n");
		printf("2.- Juegos.\n");
		printf("3.- Alquileres.\n");
		printf("4.- Salir.\n\n");

		printf("Elija opcion: ");
		scanf("%d", &opcionMenuPrincipal);
		fflush(stdin);
		printf("\n");

		switch(opcionMenuPrincipal)
		{
			case 1:
				clienteMenu(listaClientes, tamCliente);
				break;

			case 2:
			    juegoMenu(listaJuegos, tamJuegos);
				break;

			case 3:
				break;

			case 4:
				printf("Gracias por usar el ABM.\n");
				break;

			default:
				printf("No es una opcion valida. ");
				system("pause");
				break;
		}
	}while(opcionMenuPrincipal!=4);
}

