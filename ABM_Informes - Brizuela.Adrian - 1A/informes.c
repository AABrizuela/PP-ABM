#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "alquileres.h"
#include "clientes.h"
#include "juegos.h"
#include "informes.h"

void informesMenu(eAlquiler *listaAlquileres, int tamAlquiler, eJuego *listaJuegos, int tamJuego, eCliente *listaClientes, int tamCliente, int hayClientes, int hayJuegos){

	int opcionSubMenuInformes;
        do{
        system("cls");
        printf("*** Menu Informes ***\n");

        printf("\n1.- Promedio y total de importes de los juegos alquilados.\n");
        printf("\n2.- Cantidad de juegos cuyo importe no superan el promedio del item anterior.\n");
        printf("\n3.- Listar clientes por juego determinado.\n");
        printf("\n4.- Listar juegos por cliente determinado.\n");
        printf("\n5.- Listar juego menos alquilado.\n");
        printf("\n6.- Listar clientes con mas alquileres.\n");
        printf("\n7.- Listar juegos por fecha.\n");
        printf("\n8.- Listar clientes por fecha determinada.\n");
        printf("\n9.- Listar juegos por burbujeo.\n");
        printf("\n10.- Listar clientes por insercion.\n");
        printf("\n11.- Volver\n");

        printf("\nElija una opcion: ");
        scanf("%d", &opcionSubMenuInformes);
        fflush(stdin);

        switch(opcionSubMenuInformes){
            case 1:
                promedioTotal(listaAlquileres, tamAlquiler, listaJuegos, tamJuego, listaClientes, tamCliente);
                break;

            case 2:
                juegosNoSuperenPromedio(listaAlquileres, tamAlquiler, listaJuegos, tamJuego, listaClientes, tamCliente);
                break;

            case 3:
                listarClientesPorJuego(listaAlquileres, tamAlquiler, listaJuegos, tamJuego, listaClientes, tamCliente);
                break;

            case 4:
                listarJuegosPorCliente(listaAlquileres, tamAlquiler, listaJuegos, tamJuego, listaClientes, tamCliente);
                break;

            case 5:
                listarJuegoMenosAlquilado(listaAlquileres, tamAlquiler, listaJuegos, tamJuego);
                break;

            case 6:
                listarClientesConMasAlquileres(listaAlquileres, tamAlquiler, listaClientes, tamCliente);
                break;

            case 7:
                listarJuegosPorFecha(listaAlquileres, tamAlquiler, listaJuegos, tamJuego, listaClientes, tamCliente);
                break;

            case 8:
                listarClientesPorFecha(listaAlquileres, tamAlquiler, listaJuegos, tamJuego, listaClientes, tamCliente);
                break;

            case 9:
                listarJuegoPorBurbujeo(listaJuegos, tamJuego);
                break;

            case 10:
                ordenarClientesPorInsercion(listaClientes, tamCliente);
                break;

            case 11:
                break;

            default:
                printf("\nOpcion incorrecta.");
                system("pause");
        }
    }while (opcionSubMenuInformes != 11);
}

/**< Acumulador & Contador */
int promedioImportes(eAlquiler *listaAlquileres, int tamAlquiler, eJuego *listaJuegos, int tamJuego, eCliente *listaClientes, int tamCliente, float *pPromedio, float *pAcumulador, int *pContador){
    int i, j, k, retorno = 0;
    *pContador = 0;
    *pPromedio = 0;
    *pAcumulador = 0;
    for (i=0; i<tamAlquiler; i++){
        if (listaAlquileres[i].isEmpty == 0){
            for (j=0; j<tamCliente; j++){
                if (listaAlquileres[i].codigoCliente == listaClientes[j].idCliente ){
                    //No valido xq el alquiler puede existir pero el ciente puede estar dado de baja
                    //&& listaClientes[j].isEmpty == 0
                    for (k=0; k<tamJuego; k++){
                        if (listaAlquileres[i].codigoJuego == listaJuegos[k].idJuego){
                            //&& listaJuegos[k].isEmpty == 0
                            //No valido xq el alquiler puede existir pero el juego puede estar dado de baja
                            *pAcumulador = *pAcumulador + listaJuegos[k].importe;
                            *pContador = *pContador + 1;
                        }
                    }
                }
            }
        }
    }
    if (*pContador != 0){
        *pPromedio = (float) (*pAcumulador / *pContador);
        retorno = 1;
    }
    system("cls");
    return retorno;
}
/**< Punto A */
void promedioTotal(eAlquiler *listaAlquileres, int tamAlquiler, eJuego *listaJuegos, int tamJuego, eCliente *listaClientes, int tamCliente){
    float promedio, acumulador;
    int contador, r;
    r = promedioImportes(listaAlquileres, tamAlquiler, listaJuegos, tamJuego, listaClientes, tamCliente, &promedio, &acumulador, &contador);
    if (r){
        printf("El total de alquileres [%i] es de $%.2f.\n",contador,acumulador);
        printf("\nEl promedio es $%.2f.\n\n",promedio);
    }
    else{
        printf("No se pudo realizar la operacion.\n");
    }
    system("pause");
}
/**< Punto B */
void juegosNoSuperenPromedio(eAlquiler *listaAlquileres, int tamAlquiler, eJuego *listaJuegos, int tamJuego, eCliente *listaClientes, int tamCliente){
    float promedio, acumulador;
    int contador, contadorInferior = 0, r, i;
    r = promedioImportes(listaAlquileres, tamAlquiler, listaJuegos, tamJuego, listaClientes, tamCliente, &promedio, &acumulador, &contador);
    if (r){
        printf("Codigo\tDescripcion\t\tImporte\n\n");
        for (i=0; i<tamJuego; i++){
            if (!listaJuegos[i].isEmptyJuegos && listaJuegos[i].importe < promedio){
                mostrarJuego(listaJuegos[i]);
                contadorInferior++;
            }
        }
        printf("\nCantidad de juegos [%d] inferiores al promedio de [$%.2f].\n\n",contadorInferior,promedio);
    }
    else{
        printf("No se pudo realizar la operacion.\n");
    }
    system("pause");
}
/**< Punto C */
void listarClientesPorJuego(eAlquiler *listaAlquileres, int tamAlquiler, eJuego *listaJuegos, int tamJuego, eCliente *listaClientes, int tamCliente){
    int i, j, codigoJuego, flag = 1;
    fflush(stdin);
    mostrarJuegos(listaJuegos, tamJuego);
    printf("Ingrese el codigo: ");
    scanf("%d",&codigoJuego);
    system("cls");
    int indiceJuego = buscarJuego(listaJuegos, tamJuego, codigoJuego);
    if (indiceJuego == -1){
        printf("Juego inexistente.\n\n");
    }
    else{//Clientes que alquilaron el juego.
        printf("El juego seleccionado es %s y los clientes que lo alquilaron son:\n",listaJuegos[indiceJuego].descripcion);
        printf("\nCodigo\tApellido\tNombre\tSexo\tDomicilio\n\n");
        for (i=0; i<tamAlquiler; i++){
            if (listaAlquileres[i].isEmpty == 0){
                if (codigoJuego == listaAlquileres[i].codigoJuego){
                    for (j=0; j<tamCliente; j++){
                        if (listaAlquileres[i].codigoCliente == listaClientes[j].idCliente){
                                mostrarCliente(listaClientes[j]);
                                flag = 0;
                        }
                    }
                }
            }
        }
    }
    if (flag)
        printf("El juego seleccionado no ha sido alquilado.\n");
    printf("\n");
    system("pause");
}
/**< Punto D */
void listarJuegosPorCliente(eAlquiler *listaAlquileres, int tamAlquiler, eJuego *listaJuegos, int tamJuego, eCliente *listaClientes, int tamCliente){
    int i, j, codigoCliente, flag = 1;
    fflush(stdin);
    mostrarClientes(listaClientes, tamCliente);
    printf("\nIngrese el codigo: ");
    scanf("%d",&codigoCliente);
    system("cls");
    int indiceCliente = buscarCliente(listaClientes, tamCliente, codigoCliente);
    if (indiceCliente == -1){
        printf("Cliente inexistente.\n\n");
    }
    else{//Juego que alquilaron los clientes.
        printf("El cliente es %s %s y los juegos que alquilo son:\n",listaClientes[indiceCliente].nombre,listaClientes[indiceCliente].apellido);
        printf("\nCodigo\tDescripcion\t\tImporte\n\n");
        for (i=0; i<tamAlquiler; i++){
            if (listaAlquileres[i].isEmpty == 0){
                if (codigoCliente == listaAlquileres[i].codigoCliente){
                    for (j=0; j<tamJuego; j++){
                        if (listaAlquileres[i].codigoJuego == listaJuegos[j].idJuego){
                            mostrarJuego(listaJuegos[j]);
                            flag = 0;
                        }
                    }
                }
            }
        }
    }
    if (flag)
        printf("El cliente no ha alquilado.\n");
    printf("\n");
    system("pause");
}
/**< Punto E */
void listarJuegoMenosAlquilado(eAlquiler *listaAlquileres, int tamAlquiler, eJuego *listaJuegos, int tamJuego){
    int i, j, acumulador = 0, bandera = 1, menor;
    //Busco la cantidad del juego menor alquilado
    for (i=0; i<tamJuego; i++){
        if (!listaJuegos[i].isEmptyJuegos){
            acumulador = 0;
            for (j=0; j<tamAlquiler; j++){
                if (listaAlquileres[j].codigoJuego == listaJuegos[i].idJuego && !listaAlquileres[j].isEmpty)
                    acumulador++;
            }
            if (bandera){
                menor = acumulador;
                bandera = 0;
            }
            if (acumulador < menor)
                menor = acumulador;
        }
    }
    //Busco si hay uno o mas juegos menos alquilados.
    system("cls");
    printf("Juegos menos alquilados (veces [%d]).\n",menor);
    printf("\nID\tJuego\t\t\tPrecio\n\n");
    for (i=0; i<tamJuego; i++){
        acumulador = 0;
        if (!listaJuegos[i].isEmptyJuegos){
            for (j=0; j<tamAlquiler; j++){
                if (listaAlquileres[j].codigoJuego == listaJuegos[i].idJuego && !listaAlquileres[j].isEmpty)
                    acumulador++;
            }
            if (acumulador == menor){
                mostrarJuego(listaJuegos[i]);
            }
        }
    }
    printf("\n");
    system("pause");
}

/**< Punto F */
void listarClientesConMasAlquileres(eAlquiler *listaAlquileres, int tamAlquiler, eCliente *listaClientes, int tamCliente){
    int i, j, acumulador = 0, mayor, bandera = 1;
    for (i=0; i<tamCliente; i++){
        if (!listaClientes[i].isEmptyCliente){
            acumulador = 0;
            for (j=0; j<tamAlquiler; j++){
                if (listaAlquileres[j].codigoCliente == listaClientes[i].idCliente && !listaAlquileres[j].isEmpty)
                    acumulador++;
            }
        }
        if (bandera){
            mayor = acumulador;
            bandera = 0;
        }
        if (acumulador > mayor)
            mayor = acumulador;
    }
    system("cls");
    if (mayor != 0){
        printf("Los clientes con mas alquileres (veces [%d]).\n",mayor);
        printf("\nID\tApellido\tNombre\tSexo\tDireccion\n\n");
        for (i=0; i<tamCliente; i++){
            if (!listaClientes[i].isEmptyCliente){
                acumulador = 0;
                for (j=0; j<tamAlquiler; j++){
                    if (listaAlquileres[j].codigoCliente == listaClientes[i].idCliente && !listaAlquileres[j].isEmpty)
                        acumulador++;
                }
            }
            if (acumulador == mayor)
                mostrarCliente(listaClientes[i]);
        }
    }
    else
        printf("No hay alquileres realizados.\n");
    printf("\n");
    system("pause");
}
/**< Punto G */
void listarJuegosPorFecha(eAlquiler *listaAlquileres, int tamAlquiler, eJuego *listaJuegos, int tamJuego, eCliente *listaClientes, int tamCliente){
    int i, j, r, day, month, year, bandera = 1;;
    system("cls");
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
    printf("\nID\tJuego\t\t\tPrecio\n\n");
    for (i=0; i<tamAlquiler; i++){
        if (listaAlquileres[i].isEmpty == 0 && listaAlquileres[i].fechaAlquiler.day == day && listaAlquileres[i].fechaAlquiler.month == month && listaAlquileres[i].fechaAlquiler.year == year){
            for (j=0; j<tamJuego; j++){
                if (listaAlquileres[i].codigoJuego == listaJuegos[j].idJuego){
                    mostrarJuego(listaJuegos[j]);
                    bandera = 0;
                }
            }
        }
    }
    if (bandera)
        printf("No se encontraron juegos alquilados en esa fecha.\n");
    printf("\n");
    system("pause");
}
/**< Punto H */
void listarClientesPorFecha(eAlquiler *listaAlquileres, int tamAlquiler, eJuego *listaJuegos, int tamJuego, eCliente *listaClientes, int tamCliente){
    int i, j, k, r, day, month, year, bandera = 1;
    system("cls");
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
    printf("\nAlquiler Nombre\tApellido\tJuego\tFecha\n\n");
    for (i=0; i<tamAlquiler; i++){
        if (listaAlquileres[i].isEmpty == 0 && listaAlquileres[i].fechaAlquiler.day == day && listaAlquileres[i].fechaAlquiler.month == month && listaAlquileres[i].fechaAlquiler.year == year){
            for (j=0; j<tamCliente; j++){
                if (listaAlquileres[i].codigoCliente == listaClientes[j].idCliente && listaClientes[j].isEmptyCliente == 0){
                    for (k=0; k<tamJuego; k++){
                        if (listaAlquileres[i].codigoJuego == listaJuegos[k].idJuego){
                            printf("%d\t%s\t%s\t%s\t%d.%d.%d\n",
                                listaAlquileres[i].codigoAlquiler,
                                listaClientes[j].nombre,
                                listaClientes[j].apellido,
                                listaJuegos[k].descripcion,
                                listaAlquileres[i].fechaAlquiler.day,
                                listaAlquileres[i].fechaAlquiler.month,
                                listaAlquileres[i].fechaAlquiler.year
                                );
                            bandera = 0;
                        }
                    }
                }
            }
        }
    }
    if (bandera)
        printf("No se encontraron alquileres en esa fecha.\n");
    printf("\n");
    system("pause");
}
/**< Punto I */
void listarJuegoPorBurbujeo(eJuego *listaJuegos, int tamJuego){
    eJuego miAuxiliar;
    int j, banderaOrdenado = 1;
    while(banderaOrdenado){
        banderaOrdenado = 0;
        for (j=1; j<tamJuego;j++){
            if (listaJuegos[j].importe > listaJuegos[j-1].importe){
                miAuxiliar = listaJuegos[j];
                listaJuegos[j] = listaJuegos[j-1];
                listaJuegos[j-1] = miAuxiliar;
                banderaOrdenado = 1;
            }
        }
    }
    mostrarJuegos(listaJuegos, tamJuego);
    system("pause");
}
/**< Punto J */
void ordenarClientesPorInsercion(eCliente *listaClientes, int tamCliente){
    eCliente miAuxiliar;
    int i, j;
    for (i=1; i < tamCliente; i++) {
        miAuxiliar = listaClientes[i];
        j = i-1;
        while (strcmp(listaClientes[j].apellido, miAuxiliar.apellido) > 0 && j>=0) {
            listaClientes[j+1] = listaClientes[j];
            j--;
        }
        listaClientes[j+1] = miAuxiliar;
    }
    mostrarClientes(listaClientes, tamCliente);
    system("pause");
}

