#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "juegos.h"
#include "utn.h"

void juegoMenu(eJuego listaJuegos[], int tamJuego)
{
    int opcionSubMenuJuego;
	int i;

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
                i = buscarLibreJuegos(listaJuegos, tamJuego);
                if (i == -1){
                    printf("\nNo hay lugar para cargar juegos");
                    system("pause");
                    break;
                }else{
                agregarJuego(listaJuegos, tamJuego);
                }
                break;

            case 2:
                if(listaJuegos[0].isEmptyJuegos!=1){
                eliminarJuego(listaJuegos, tamJuego);
                system("pause");
                }else{
				printf("No hay nada que borrar. ");
				system("pause");
                }
                break;

            case 3:
            	if(listaJuegos[0].isEmptyJuegos!=1){
                modificarJuego(listaJuegos, tamJuego);
                system("pause");
                }else{
				printf("No hay nada que modificar. ");
				system("pause");
                }
                break;

            case 4:
                if(listaJuegos[0].isEmptyJuegos!=1){
                ordenarJuegos(listaJuegos, tamJuego);
                mostrarJuegos(listaJuegos, tamJuego);
                system("pause");
                }else{
				printf("No hay nada que listar. ");
				system("pause");
                }
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
		printf("Ingrese id de Juego para verificar: ");
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
		printf("No hay ningun juego con el id %d\n", id);
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

int ordenarJuegos(eJuego *misJuegos, int tamJuego){
    int i, j;
    eJuego auxJuego;
    for (i=0; i<tamJuego-1; i++){
        for (j=0+i; j<tamJuego; j++){
            if (misJuegos[i].isEmptyJuegos == 0 && misJuegos[j].isEmptyJuegos == 0){
                if (misJuegos[i].importe <  misJuegos[j].importe){
                    auxJuego = misJuegos[i];
                    misJuegos[i] = misJuegos[j];
                    misJuegos[j] = auxJuego;
                }
                else if (misJuegos[i].importe ==  misJuegos[j].importe){
                    if (strcmp(misJuegos[i].descripcion,misJuegos[j].descripcion) > 0){
                        auxJuego = misJuegos[i];
                        misJuegos[i] = misJuegos[j];
                        misJuegos[j] = auxJuego;
                    }
                }
            }
        }
    }
    return 0;
}
