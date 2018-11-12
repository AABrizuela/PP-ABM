#ifndef MENUPRINCIPAL_H_INCLUDED
#define MENUPRINCIPAL_H_INCLUDED

#include "clientes.h"
#include "juegos.h"
#include "alquileres.h"

/** \brief Funcion que llama al menu principal
 *
 * \param listaClientes[] El array completo de clientes
 * \param tamCliente El tamaño del array de clientes
 * \param listaJuegos[] El array completo de juegos
 * \param tamJuegos El tamaño del array de juegos
 * \param listaAlquiler[] El array completo de alquileres
 * \param tamAlquiler El tamaño del array de alquileres
 * \return void
 *
 */
void menuPrincipal(eCliente listaClientes[], int tamCliente, eJuego listaJuegos[], int tamJuegos, eAlquiler listaAlquiler[], int tamAlquiler);

#endif // MENUPRINCIPAL_H_INCLUDED
