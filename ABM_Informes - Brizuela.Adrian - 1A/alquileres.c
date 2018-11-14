#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "utn.h"

#include "alquileres.h"
#include "clientes.h"
#include "juegos.h"

void alquilerMenu(eAlquiler *pAlquileres, int largoAlquileres, eJuego *pJuegos, int largoJuegos, eCliente *pClientes, int largoClientes, int hayClientes, int hayJuegos){
    int indiceAlquiler;
    char opcion;
        do{
        fflush(stdin);
        system("cls");
        printf("*** Menu Alquileres ***\n");
        printf("\n1- Alta.\n");
        printf("2- Listar.\n");
        printf("3- Volver.\n");
        printf("\nElija una opcion: ");
        scanf("%c",&opcion);
        switch(opcion){
            case '1':
                indiceAlquiler = posicionLibreAlquiler(pAlquileres, CANT_ALQUILERES);
                if (!hayClientes || !hayJuegos){
                    printf("\nNo se pueden generar alquileres sin juegos y/o clientes.\n\n");
                    system("pause");
                    break;
                }
                else{
                    if (indiceAlquiler == -1){
                        printf("\nNo hay lugar para cargar clientes");
                        system("pause");
                        break;
                    }
                    else{
                        nuevoAlquilerJuego(pAlquileres, largoAlquileres, pJuegos, largoJuegos, pClientes, largoClientes, indiceAlquiler);
                    }
                }
                break;
            case '2':

                listarAlquiler(pAlquileres, largoAlquileres, pJuegos, largoJuegos, pClientes, largoClientes);
                break;
            case '3':


                break;
            default:
                printf("\nOpción incorrecta.");
                system("pause");
        }
    }while (opcion != '3');
}

void listarAlquiler(eAlquiler* pAlquileres, int largoAlquileres, eJuego* pJuegos, int largoJuegos, eCliente* pClientes, int largoClientes){
    int i, j, k;
    system("cls");
    printf("*** Lista de alquileres ***\n\n");
    printf("Alquiler Id\tNombre\tApellido\tSexo Juego\t\tImporte\tFecha\n\n");
    for (i=0; i<largoAlquileres; i++){
        if (pAlquileres[i].isEmpty == 0){
            for (j=0; j<largoClientes; j++){
                if (pAlquileres[i].codigoCliente == pClientes[j].idCliente && pClientes[j].isEmptyCliente == 0){
                    for (k=0; k<largoJuegos; k++){
                        if (pAlquileres[i].codigoJuego == pJuegos[k].idJuego && pJuegos[k].isEmptyJuegos == 0){
                            printf("%d\t%d\t%s\t%s\t%c %s\t$ %2.f\t%d/%d/%d\n",
                                pAlquileres[i].codigoAlquiler,
                                pAlquileres[i].codigoCliente,
                                pClientes[j].nombre,
                                pClientes[j].apellido,
                                pClientes[j].sexo,
                                pJuegos[k].descripcion,
                                pJuegos[k].importe,
                                pAlquileres[i].fechaAlquiler.day,
                                pAlquileres[i].fechaAlquiler.month,
                                pAlquileres[i].fechaAlquiler.year
                                );
                        }
                    }
                }
            }
        }
    }
    printf("\n");
    system("pause");
}

int nuevoAlquilerJuego(eAlquiler *pAlquileres, int largoAlquileres, eJuego *pJuegos, int largoJuegos, eCliente *pClientes, int largoClientes, int indiceAlquiler){
    int r, indice[2], retorno = 0, codigoAlquiler, codigoJuego , codigoCliente, day, month, year;
    char opcion;
    eAlquiler myAuxiliarAlquiler;
    do{
        mostrarClientes(pClientes, largoClientes);
        fflush(stdin);
        printf("\nSeleccione el cliente: ");
        scanf("%d",&codigoCliente);
        indice[0] = buscarCliente(pClientes, largoClientes, codigoCliente);
    }while (indice[0] == -1);
    do{
        mostrarJuegos(pJuegos, largoJuegos);
        fflush(stdin);
        printf("\nSeleccione el juego: ");
        scanf("%d",&codigoJuego);
    indice[1] = buscarJuego(pJuegos, largoJuegos, codigoJuego);
    }while (indice[1] == -1);
    system("cls");
    printf("*** Nuevo alquiler ***\n");
    do{
        fflush(stdin);
        printf("\nIngrese la fecha:\n");
        printf( "\nIntroduzca d%ca: ", 161 );
        scanf( "%d", &day );
        printf( "\nIntroduzca mes: " );
        scanf( "%d", &month );
        printf( "\nIntroduzca a%co: ", 164 );
        scanf( "%d", &year );
        r = isFecha(day, month, year);
    }while (r == 0);
    fflush(stdin);
    printf("\nCliente\tNombre\t\tApellido\tJuego\t\t\tImporte\n");
    printf("\n%d\t%s\t\t%s\t\t%s\t\t$ %.2f",pClientes[indice[0]].idCliente,pClientes[indice[0]].nombre,pClientes[indice[0]].apellido,pJuegos[indice[1]].descripcion,pJuegos[indice[1]].importe);
    printf("\n\n%cConfirma el aquiler? S/N: ", 168);
    scanf("%c",&opcion);
    strlwr(&opcion);
    if ((opcion = 's')){
        codigoAlquiler = nuevoCodigoAlquiler();
        myAuxiliarAlquiler.codigoAlquiler = codigoAlquiler;
        myAuxiliarAlquiler.codigoCliente = codigoCliente;
        myAuxiliarAlquiler.codigoJuego = codigoJuego;
        myAuxiliarAlquiler.fechaAlquiler.day = day;
        myAuxiliarAlquiler.fechaAlquiler.month = month;
        myAuxiliarAlquiler.fechaAlquiler.year = year;
        myAuxiliarAlquiler.isEmpty = 0;
        pAlquileres[indiceAlquiler] = myAuxiliarAlquiler;
        printf("\nAlquiler confirmado.\n\n");
    }
    system("pause");
    return retorno;
}

int nuevoCodigoAlquiler(void){
    static int nuevoIdAlquiler = 0;
    nuevoIdAlquiler++;
    return nuevoIdAlquiler;
}

int posicionLibreAlquiler(eAlquiler *pAlquileres, int largoAlquileres){
    int indice, retorno = -1;
    for (indice=0; indice<largoAlquileres; indice++){
        if (pAlquileres[indice].isEmpty){
            retorno = indice;
            break;
        }
    }
    return retorno;
}

int inicializarAlquileres(eAlquiler *pAlquileres, int largoAlquileres){
    int i, retorno = -1;
    if (pAlquileres != NULL && largoAlquileres != 0){
        retorno = 0;
        for (i=0; i<largoAlquileres; i++){
            pAlquileres[i].isEmpty = 1;
        }
    }
    return retorno;
}
