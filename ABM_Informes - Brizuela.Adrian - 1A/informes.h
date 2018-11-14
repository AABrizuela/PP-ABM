#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

/** \brief Submenu de informes.
 *
 * \param listaAlquileres El array de alquileres.
 * \param tamAlquiler El tamaño del array de alquileres.
 * \param listaJuegos El array de juegos.
 * \param tamJuego El tamaño del array de juegos.
 * \param listaClientes El array de clientes
 * \param tamCliente El tamaño del array de clientes
 * \param hayClientes Variable que verifica si hay clientes.
 * \param hayJuegos Variable que verifica si hay juegos.
 * \return void
 *
 */
void informesMenu(eAlquiler *listaAlquileres, int tamAlquiler, eJuego *listaJuegos, int tamJuego, eCliente *listaClientes, int tamCliente, int hayClientes, int hayJuegos);


/** \brief Acumulador y contador para realizar promedio de los importes.
 *
 * \param listaAlquileres El array de alquileres.
 * \param tamAlquiler El tamaño del array de alquileres
 * \param listaJuegos El array de juegos.
 * \param tamJuego El tamaño del array de juegos.
 * \param listaClientes El array de clientes.
 * \param tamCliente El tamaño del array de Clientes.
 * \param pPromedio Puntero a promedio.
 * \param pAcumulador Puntero a acumulador.
 * \param pContador Puntero a contador.
 * \return int
 *
 */
int promedioImportes(eAlquiler *listaAlquileres, int tamAlquiler, eJuego *listaJuegos, int tamJuego, eCliente *listaClientes, int tamCliente, float *pPromedio, float *pAcumulador, int *pContador);


/** \brief Punto A: Promedio y total de alquileres, llama a la funcion promedioImportes para calcular.
 *
 * \param listaAlquileres El array de alquileres.
 * \param tamAlquiler El tamaño del array de alquileres
 * \param listaJuegos El array de juegos.
 * \param tamJuego El tamaño del array de juegos.
 * \param listaClientes El array de clientes.
 * \param tamCliente El tamaño del array de Clientes.
 * \return void
 *
 */
void promedioTotal(eAlquiler *listaAlquileres, int tamAlquiler, eJuego *listaJuegos, int tamJuego, eCliente *listaClientes, int tamCliente);

/** \brief Punto B: Cantidad de juegos inferiores al promedio, llama a la funcion promedioImportes para calcular.
 *
 * \param listaAlquileres El array de alquileres.
 * \param tamAlquiler El tamaño del array de alquileres
 * \param listaJuegos El array de juegos.
 * \param tamJuego El tamaño del array de juegos.
 * \param listaClientes El array de clientes.
 * \param tamCliente El tamaño del array de Clientes.
 * \return void
 *
 */
void juegosNoSuperenPromedio(eAlquiler *listaAlquileres, int tamAlquiler, eJuego *listaJuegos, int tamJuego, eCliente *listaClientes, int tamCliente);

/** \brief Punto C: Muestra todos los clientes que alquilaron un juego en particular.
 *
 * \param listaAlquileres El array de alquileres.
 * \param tamAlquiler El tamaño del array de alquileres
 * \param listaJuegos El array de juegos.
 * \param tamJuego El tamaño del array de juegos.
 * \param listaClientes El array de clientes.
 * \param tamCliente El tamaño del array de Clientes.
 * \return void
 *
 */
void listarClientesPorJuego(eAlquiler *listaAlquileres, int tamAlquiler, eJuego *listaJuegos, int tamJuego, eCliente *listaClientes, int tamCliente);


/** \brief Punto D: Lista los juegos que alquilo un cliente en particular.
 *
 * \param listaAlquileres El array de alquileres.
 * \param tamAlquiler El tamaño del array de alquileres
 * \param listaJuegos El array de juegos.
 * \param tamJuego El tamaño del array de juegos.
 * \param listaClientes El array de clientes.
 * \param tamCliente El tamaño del array de Clientes.
 * \return void
 *
 */
void listarJuegosPorCliente(eAlquiler *listaAlquileres, int tamAlquiler, eJuego *listaJuegos, int tamJuego, eCliente *listaClientes, int tamCliente);

/** \brief Punto E: Muestra el/los juego/s menos alquilado/s.
 *
 * \param listaAlquileres El array de alquileres.
 * \param tamAlquiler El tamaño del array de alquileres
 * \param listaJuegos El array de juegos.
 * \param tamJuego El tamaño del array de juegos.
 * \return void
 *
 */
void listarJuegoMenosAlquilado(eAlquiler *listaAlquileres, int tamAlquiler, eJuego *listaJuegos, int tamJuego);


/** \brief Punto F: Muestra los clientes con mas alquileres.
 *
 * \param listaAlquileres El array de alquileres.
 * \param tamAlquiler El tamaño del array de alquileres
 * \param listaClientes El array de clientes.
 * \param tamCliente El tamaño del array de Clientes.
 * \return void
 *
 */
void listarClientesConMasAlquileres(eAlquiler *listaAlquileres, int tamAlquiler, eCliente *listaClientes, int tamCliente);


/** \brief Punto G: Muestra los juegos alquilados en una fecha en particular y el importe.
 *
 * \param listaAlquileres El array de alquileres.
 * \param tamAlquiler El tamaño del array de alquileres
 * \param listaJuegos El array de juegos.
 * \param tamJuego El tamaño del array de juegos.
 * \param listaClientes El array de clientes.
 * \param tamCliente El tamaño del array de Clientes.
 * \return void
 *
 */
void listarJuegosPorFecha(eAlquiler *listaAlquileres, int tamAlquiler, eJuego *listaJuegos, int tamJuego, eCliente *listaClientes, int tamCliente);


/** \brief Punto H: Muestra los clientes que alquilaron juegos en una fecha en particular.
 *
 * \param listaAlquileres El array de alquileres.
 * \param tamAlquiler El tamaño del array de alquileres
 * \param listaJuegos El array de juegos.
 * \param tamJuego El tamaño del array de juegos.
 * \param listaClientes El array de clientes.
 * \param tamCliente El tamaño del array de Clientes.
 * \return void
 *
 */
void listarClientesPorFecha(eAlquiler *listaAlquileres, int tamAlquiler, eJuego *listaJuegos, int tamJuego, eCliente *listaClientes, int tamCliente);


/** \brief Punto I: Muestra todos los juegos ordenados por importe (descendente), utilizando burbujeo.
 *
 * \param pJuego El array de juegos.
 * \param tamJuego El tamaño del array de juegos.
 * \return void
 *
 */
void listarJuegoPorBurbujeo(eJuego *pJuego, int tamJuego);


/** \brief Punto J: Listar todos los clientes ordenados por apellido (ascendente), utilizando insercion.
 *
 * \param listaClientes El array de clientes.
 * \param tamCliente El tamaño del array de Clientes.
 * \return void
 *
 */
void ordenarClientesPorInsercion(eCliente *listaClientes, int tamCliente);
#endif // INFORMES_H_INCLUDED
