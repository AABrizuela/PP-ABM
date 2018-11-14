#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "clientes.h"
#include "juegos.h"
#include "menuprincipal.h"
#include "alquileres.h"
#include "informes.h"


void menuPrincipal(eCliente listaClientes[], int tamCliente, eJuego listaJuegos[], int tamJuegos, eAlquiler listaAlquiler[], int tamAlquiler)
{
    int opcionMenuPrincipal = 0;
    int hayClientes, hayJuegos;

    do
	{
		system("cls");
		printf("*** Bienvenido al ABM ***\n\n");
		printf("Menu principal.\n\n");

		printf("1.- Clientes.\n");
		printf("2.- Juegos.\n");
		printf("3.- Alquileres.\n");
		printf("4.- Informes.\n");
		printf("5.- Salir.\n\n");

		printf("Elija opcion: ");
		scanf("%d", &opcionMenuPrincipal);
		fflush(stdin);
		printf("\n");

		switch(opcionMenuPrincipal)
		{
			case 1:
				clienteMenu(listaClientes, tamCliente);
				hayClientes = 1;
				break;

			case 2:
			    juegoMenu(listaJuegos, tamJuegos);
			    hayJuegos = 1;
				break;

			case 3:
				alquilerMenu(listaAlquiler, tamAlquiler, listaJuegos, tamJuegos, listaClientes, tamCliente, hayClientes, hayJuegos);
				break;

			case 4:
				informesMenu(listaAlquiler, tamAlquiler, listaJuegos, tamJuegos, listaClientes, tamCliente, hayClientes, hayJuegos);
				break;

			case 5:
				printf("Gracias por usar el ABM.\n");
				break;

			default:
				printf("No es una opcion valida. ");
				system("pause");
				break;
		}
	}while(opcionMenuPrincipal!=4);
}

