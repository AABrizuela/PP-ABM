#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menuPrincipal.h"
#include "clientes.h"
#include "juegos.h"
#include "alquileres.h"
#include "utn.h"

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


/*-------------Submenu Cliente-------------*/


void clienteMenu(eCliente listaClientes[], int tamCliente)
{
    int opcionSubMenuCliente;

    do
    {
        system("cls");
        printf("*** Menu de Clientes ***\n\n");

        printf("1.- Alta.\n");
        printf("2.- Baja.\n");
        printf("3.- Modificacion.\n");
        printf("4.- Listar.\n");
        printf("5.- Volver.\n\n");

        printf("Elija opcion: ");
        scanf("%d", &opcionSubMenuCliente);
        fflush(stdin);
        printf("\n");

        switch(opcionSubMenuCliente)
        {
            case 1:
                agregarCliente(listaClientes, tamCliente);
                break;

            case 2:
                eliminarCliente(listaClientes, tamCliente);
                break;

            case 3:
                modificarCliente(listaClientes, tamCliente);
                break;

            case 4:
                mostrarClientes(listaClientes, tamCliente);
                system("pause");
                break;

            case 5:
                break;

            default:
                printf("No es una opcion valida. ");
                system("pause");
                break;
        }
    }while(opcionSubMenuCliente!=5);
}

void inicializarClientes(eCliente listaClientes[], int tamCliente)
{
    int i=0;

	for(i=0; i < tamCliente; i++)
	{
		listaClientes[i].isEmptyCliente = 1;
	}
}

int buscarLibreClientes(eCliente listaClientes[], int tamCliente)
{
    int indice = -1, i=0;

    for(i=0; i < tamCliente; i++)
    {

        if( listaClientes[i].isEmptyCliente == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarCliente(eCliente listaClientes[], int tamCliente, int idCliente)
{
    int indice=-1, i=0;

    for(i=0; i < tamCliente; i++)
    {
        if( listaClientes[i].idCliente == idCliente && listaClientes[i].isEmptyCliente == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void agregarCliente(eCliente listaClientes[], int tamCliente)
{
    eCliente nuevoCliente;
    int indice;
	int esta;
	int idCliente;

	indice = buscarLibreClientes(listaClientes, tamCliente);

	if(indice == -1)
	{
		printf("No hay lugar\n\n");
		system("pause");
	}
	else
	{
		printf("Ingrese id de Cliente para verificar: ");
		scanf("%d", &idCliente);

		esta = buscarCliente(listaClientes, tamCliente, idCliente);

		if(esta != -1)
		{
			printf("Existe un cliente con el id %d\n", idCliente);
			mostrarCliente(listaClientes[esta]);
			printf("\n");
			system("pause");
		}
		else{
            printf("Espacio libre en el id %d\n", idCliente);

			nuevoCliente.idCliente = generarNextIdCliente();

			getValidString("Ingrese apellido: ", "Error, ingrese apellido.", nuevoCliente.apellido);

			getValidString("Ingrese nombre: ", "Error, ingrese nombre.", nuevoCliente.nombre);

			printf("Ingrese sexo: ");
			scanf("%c", &nuevoCliente.sexo);
			fflush(stdin);
			while(nuevoCliente.sexo != 'm' && nuevoCliente.sexo != 'f')
			{
				printf("Error, ingrese f o m: ");
				scanf("%c", &nuevoCliente.sexo);
				fflush(stdin);
				system("pause");
			}

            getValidString("Ingrese calle: ", "Error, ingrese calle.", nuevoCliente.calle);

            nuevoCliente.altura = getValidInt("Ingrese altura: ", "Error, ingrese altura: ", 0, 999999);

			nuevoCliente.isEmptyCliente = 0;

			listaClientes[indice] = nuevoCliente;

			printf("Cliente cargado exitosamente. ");
			system("pause");
		   }
	    }
}

int generarNextIdCliente()
{
    static int id = 0;

    id ++;

    return id;
}

void mostrarCliente(eCliente cliente)
{
    printf("%d\t%s\t\%s\t%c\t%s\t%d\n\n", cliente.idCliente, cliente.apellido, cliente.nombre, cliente.sexo, cliente.calle, cliente.altura);
}

void mostrarClientes(eCliente listaClientes[], int tamCliente)
{
    int i;
    for(i=0; i< tamCliente; i++)
    {
        if(listaClientes[i].isEmptyCliente == 0)
        {
            mostrarCliente(listaClientes[i]);
        }
    }
}

void eliminarCliente(eCliente listaClientes[], int tamCliente)
{
    int id;
	int indice;
	char borrar;
	eCliente cliente;

	printf("Ingrese id: ");
	scanf("%d", &id);

	indice = buscarCliente(listaClientes, tamCliente, id);

	if( indice == -1){
		printf("No hay ningun empleado con el id %d\n", id);
	}
	else{
		cliente = listaClientes[indice];
		mostrarCliente(cliente);

		printf("\nConfirma borrado?: ");
		fflush(stdin);
		scanf("%c", &borrar);
		if(borrar != 's'){
		printf("Borrado cancelado\n\n");
	}
	else{
		listaClientes[indice].isEmptyCliente = 1;
		printf("Se ha eliminado el cliente\n\n");
	}
	system("pause");
	}
}

void modificarCliente(eCliente listaClientes[], int tamCliente)
{
    int opcionMenuMod;
	char edit;
	char nuevoNombre[51];
	char nuevoApellido[51];
	char nuevoSexo;
	char nuevaCalle[51];
	int nuevaAltura;
	int indice;
	int id;

	id = getValidInt("Ingrese id de cliente a modificar: ", "Error, fuera de rango.", 1, 100);
	indice = buscarCliente(listaClientes, tamCliente, id);

	do
	{
		system("cls");
		printf("*** Cliente a modificar ***\n\n");

		mostrarCliente(listaClientes[indice]);

		printf("*** Menu de MODIFICACIONES ***\n\n");
		printf("1.- Modificar apellido.\n");
		printf("2.- Modificar nombre.\n");
		printf("3.- Modificar sexo.\n");
		printf("4.- Modificar calle.\n");
		printf("5.- Modificar altura.\n");
		printf("6.- Salir.\n\n");

		printf("Elija opcion: ");
		scanf("%d", &opcionMenuMod);

		switch(opcionMenuMod)
		{
			case 1:
				printf("\nModifica apellido? s/n ");
				fflush(stdin);
				scanf("%c", &edit);
				if(edit!='s')
				{
					printf("Modificacion cancelada.\n\n");
				}
				else
				{
					getValidString("Ingrese NUEVO apellido: ", "Error, reingrese.", nuevoApellido);
					strcpy(listaClientes[indice].apellido, nuevoApellido);
					printf("Se ha modificado el apellido con exito\n\n");
				}

				system("pause");
				break;

			case 2:
				printf("\nModifica nombre? s/n ");
				fflush(stdin);
				scanf("%c", &edit);
				if(edit!='s')
				{
					printf("Modificacion cancelada.\n\n");
				}
				else
				{
					getValidString("Ingrese NUEVO nombre: ", "Error, reingrese.", nuevoNombre);
					strcpy(listaClientes[indice].nombre, nuevoNombre);
					printf("Se ha modificado el nombre con exito\n\n");
				}

				system("pause");
				break;

			case 3:
				printf("\nModifica sexo? s/n ");
				fflush(stdin);
				scanf("%c", &edit);
				if(edit!='s')
				{
					printf("Modificacion cancelada.\n\n");
				}
				else
				{
					printf("Ingrese NUEVO sexo: ");
					scanf("%c", &nuevoSexo);
					fflush(stdin);
					while(nuevoSexo != 'm' && nuevoSexo != 'f')
					{
						printf("Error, ingrese f o m: ");
						scanf("%c", &nuevoSexo);
						fflush(stdin);
					}
					listaClientes[indice].sexo = nuevoSexo;
					printf("Se ha modificado el sexo con exito.\n\n");
				}

				system("pause");
				break;

			case 4:
				printf("\nModifica calle?: ");
				fflush(stdin);
				scanf("%c", &edit);
				if(edit != 's'){
				printf("Modificacion cancelada\n\n");
				}
				else{
					getValidString("Ingrese NUEVA calle: ", "Error, reingrese.", nuevaCalle);
                    strcpy(listaClientes[indice].calle, nuevaCalle);
					printf("Se ha modificado la calle con exito\n\n");
				}

				system("pause");
				break;

			case 5:
				printf("\nModifica altura?: ");
				fflush(stdin);
				scanf("%c", &edit);
				if(edit != 's'){
				printf("Modificacion cancelada\n\n");
				}
				else{
					nuevaAltura = getValidInt("Ingrese NUEVA altura: ", "Error, reingrese.", 0, 999999);

					listaClientes[indice].altura = nuevaAltura;
					printf("Se ha modificado la altura con exito\n\n");
				}

				system("pause");
				break;

			case 6:
				break;

			default:
				printf("Opcion equivocada. ");
				system("pause");
				break;

		}
	}while(opcionMenuMod!=6);
}

/*-------------Submenu Juegos-------------*/

void juegoMenu(eJuego listaJuegos[], int tamJuego)
{
    int opcionSubMenuJuego;

    do
    {
        system("cls");
        printf("*** Menu de Juegos ***\n\n");

        printf("1.- Alta.\n");
        printf("2.- Baja.\n");
        printf("3.- Modificacion.\n");
        printf("4.- Listar.\n");
        printf("5.- Volver.\n\n");

        printf("Elija opcion: ");
        scanf("%d", &opcionSubMenuJuego);
        fflush(stdin);
        printf("\n");

        switch(opcionSubMenuJuego)
        {
            case 1:
                agregarJuego(listaJuegos, tamJuego);
                break;

            case 2:
                eliminarJuego(listaJuegos, tamJuego);
                break;

            case 3:
                modificarJuego(listaJuegos, tamJuego);
                break;

            case 4:
                mostrarJuegos(listaJuegos, tamJuego);
                system("pause");
                break;

            case 5:
                break;

            default:
                printf("No es una opcion valida. ");
                system("pause");
                break;
        }
    }while(opcionSubMenuJuego!=5);
}

void inicializarJuegos(eJuego listaJuegos[], int tamJuego)
{
    int i=0;

	for(i=0; i < tamJuego; i++)
	{
		listaJuegos[i].isEmptyJuegos = 1;
	}
}

int buscarLibreJuegos(eJuego listaJuegos[], int tamJuego)
{
    int indice = -1, i=0;

    for(i=0; i < tamJuego; i++)
    {

        if( listaJuegos[i].isEmptyJuegos == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarJuego(eJuego listaJuegos[], int tamJuego, int idJuego)
{
    int indice=-1, i=0;

    for(i=0; i < tamJuego; i++)
    {
        if(listaJuegos[i].idJuego == idJuego && listaJuegos[i].isEmptyJuegos == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void agregarJuego(eJuego listaJuegos[], int tamJuego)
{
    eJuego nuevoJuego;
    int indice;
	int esta;
	int idJuego;

	indice = buscarLibreJuegos(listaJuegos, tamJuego);

	if(indice == -1)
	{
		printf("No hay lugar\n\n");
		system("pause");
	}
	else
	{
		printf("Ingrese id de Cliente para verificar: ");
		scanf("%d", &idJuego);

		esta = buscarJuego(listaJuegos, tamJuego, idJuego);

		if(esta != -1)
		{
			printf("Existe un cliente con el id %d\n", idJuego);
			mostrarJuego(listaJuegos[esta]);
			printf("\n");
			system("pause");
		}
		else{
            printf("Espacio libre en el id %d\n", idJuego);

			nuevoJuego.idJuego = generarNextIdJuego();

			getValidString("Ingrese nombre de juego: ", "Error, ingrese nombre de juego.", nuevoJuego.descripcion);

            nuevoJuego.importe = getValidFloat("Ingrese precio de juego: ", "Error, ingrese precio.", 1, 999999);

			nuevoJuego.isEmptyJuegos = 0;

			listaJuegos[indice] = nuevoJuego;

			printf("Juego cargado exitosamente. ");
			system("pause");
		   }
	    }
}

int generarNextIdJuego()
{
    static int id = 0;

    id ++;

    return id;
}

void mostrarJuego(eJuego juego)
{
    printf("%d\t%s\t%.2f\n\n", juego.idJuego, juego.descripcion, juego.importe);
}

void mostrarJuegos(eJuego listaJuegos[], int tamJuego)
{
    int i;
    for(i=0; i< tamJuego; i++)
    {
        if(listaJuegos[i].isEmptyJuegos == 0)
        {
            mostrarJuego(listaJuegos[i]);
        }
    }
}

void eliminarJuego(eJuego listaJuegos[], int tamJuego)
{
    int id;
	int indice;
	char borrar;
	eJuego juego;

	printf("Ingrese id: ");
	scanf("%d", &id);

	indice = buscarJuego(listaJuegos, tamJuego, id);

	if( indice == -1){
		printf("No hay ningun empleado con el id %d\n", id);
	}
	else{
		juego = listaJuegos[indice];
		mostrarJuego(juego);

		printf("\nConfirma borrado?: ");
		fflush(stdin);
		scanf("%c", &borrar);
		if(borrar != 's'){
		printf("Borrado cancelado\n\n");
	}
	else{
		listaJuegos[indice].isEmptyJuegos = 1;
		printf("Se ha eliminado el juego\n\n");
	}
	system("pause");
	}
}

void modificarJuego(eJuego listaJuegos[], int tamJuego)
{
    int opcionMenuMod;
	char edit;
	char nuevoNombre[51];
	float nuevoPrecio;
	int indice;
	int id;

	id = getValidInt("Ingrese id de juego a modificar: ", "Error, fuera de rango.", 1, 100);
	indice = buscarJuego(listaJuegos, tamJuego, id);

	do
	{
		system("cls");
		printf("*** Juego a modificar ***\n\n");

		mostrarJuego(listaJuegos[indice]);

		printf("*** Menu de MODIFICACIONES ***\n\n");
		printf("1.- Modificar descripcion.\n");
		printf("2.- Modificar precio.\n");
		printf("3.- Salir.\n\n");

		printf("Elija opcion: ");
		scanf("%d", &opcionMenuMod);

		switch(opcionMenuMod)
		{
			case 1:
				printf("\nModifica descripcion? s/n ");
				fflush(stdin);
				scanf("%c", &edit);
				if(edit!='s')
				{
					printf("Modificacion cancelada.\n\n");
				}
				else
				{
					getValidString("Ingrese NUEVO descripcion: ", "Error, reingrese.", nuevoNombre);
					strcpy(listaJuegos[indice].descripcion, nuevoNombre);
					printf("Se ha modificado el descripcion con exito\n\n");
				}

				system("pause");
				break;

			case 2:
				printf("\nModifica precio?: ");
				fflush(stdin);
				scanf("%c", &edit);
				if(edit != 's'){
				printf("Modificacion cancelada\n\n");
				}
				else{
					nuevoPrecio = getValidFloat("Ingrese NUEVO precio: ", "Error, reingrese.", 0, 999999);

					listaJuegos[indice].importe = nuevoPrecio;
					printf("Se ha modificado el precio con exito\n\n");
				}

				system("pause");
				break;

			case 3:
				break;

			default:
				printf("Opcion equivocada. ");
				system("pause");
				break;

		}
	}while(opcionMenuMod!=3);
}
