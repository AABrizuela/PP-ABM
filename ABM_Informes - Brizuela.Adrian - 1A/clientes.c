#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "clientes.h"

void clienteMenu(eCliente listaClientes[], int tamCliente)
{
    int opcionSubMenuCliente;
    int i;

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
                i = buscarLibreClientes(listaClientes, tamCliente);
                if (i == -1){
                    printf("\nNo hay lugar para cargar clientes");
                    system("pause");
                    break;
                }else{
                agregarCliente(listaClientes, tamCliente);
                }
                break;

            case 2:
            	if(listaClientes[0].isEmptyCliente!=1){
                eliminarCliente(listaClientes, tamCliente);
                system("pause");
                }else{
				printf("No hay nada que borrar. ");
				system("pause");
                }
                break;

            case 3:
            	if(listaClientes[0].isEmptyCliente!=1){
                modificarCliente(listaClientes, tamCliente);
                system("pause");
                }else{
                	printf("No hay nada que modificar. ");
				system("pause");
                }
                break;

            case 4:
            	if(listaClientes[0].isEmptyCliente!=1){
                ordenarClientes(listaClientes, tamCliente);
                mostrarClientes(listaClientes, tamCliente);
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
            while(strlen(nuevoCliente.apellido)>50){

                printf("El dato ingresado debe tener menos de 50 caracteres. Reingrese.");
                getValidString("Ingrese apellido: ", "Error, ingrese apellido.", nuevoCliente.apellido);

            }
			getValidString("Ingrese nombre: ", "Error, ingrese nombre.", nuevoCliente.nombre);
			while(strlen(nuevoCliente.nombre)>50){

                printf("El dato ingresado debe tener menos de 50 caracteres. Reingrese.");
                getValidString("Ingrese nombre: ", "Error, ingrese nombre.", nuevoCliente.nombre);

            }

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
		printf("No hay ningun empleado con el id %d. \n", id);
		system("pause");
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
				printf("\nModifica apellido? <S/N> ");
				fflush(stdin);
				scanf("%c", &edit);
				if(edit != 's' || edit != 'S')
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
				printf("\nModifica nombre? <S/N>");
				fflush(stdin);
				scanf("%c", &edit);
				if(edit != 's' || edit != 'S')
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
				printf("\nModifica sexo? <S/N> ");
				fflush(stdin);
				scanf("%c", &edit);
				if(edit != 's' || edit != 'S')
				{
					printf("Modificacion cancelada.\n\n");
				}
				else
				{
					printf("Ingrese NUEVO sexo: ");
					fflush(stdin);
					scanf("%c", &nuevoSexo);
					while(nuevoSexo != 'm' && nuevoSexo != 'f')
					{
						printf("Error, ingrese f o m: ");
						fflush(stdin);
						scanf("%c", &nuevoSexo);
                    }
					listaClientes[indice].sexo = nuevoSexo;
					printf("Se ha modificado el sexo con exito.\n\n");
				}

				system("pause");
				break;

			case 4:
				printf("\nModifica calle? <S/N>");
				fflush(stdin);
				scanf("%c", &edit);
				if(edit != 's' || edit != 'S'){
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
				printf("\nModifica altura? <S/N> ");
				fflush(stdin);
				scanf("%c", &edit);
				if(edit != 's' || edit != 'S'){
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

int ordenarClientes(eCliente *misClientes, int tamCliente){
    int i, j;
    eCliente auxCliente;
    for (i=0; i<tamCliente-1; i++){
        for (j=0+i; j<tamCliente; j++){
            if (misClientes[i].isEmptyCliente == 0 && misClientes[j].isEmptyCliente == 0){
                if (strcmp(misClientes[i].apellido,misClientes[j].apellido) > 0){
                    auxCliente = misClientes[i];
                    misClientes[i] = misClientes[j];
                    misClientes[j] = auxCliente;
                }
                else if (strcmp(misClientes[i].apellido,misClientes[j].apellido) == 0){
                    if (strcmp(misClientes[i].nombre,misClientes[j].nombre) > 0){
                        auxCliente = misClientes[i];
                        misClientes[i] = misClientes[j];
                        misClientes[j] = auxCliente;
                    }
                }
            }
        }
    }
    return 0;
}
