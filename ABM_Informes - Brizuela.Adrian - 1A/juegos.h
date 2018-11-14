#ifndef JUEGOS_H_INCLUDED
#define JUEGOS_H_INCLUDED

typedef struct
{
    int idJuego;
    char descripcion[51];
    float importe;
    int isEmptyJuegos;
}eJuego;

/** \brief Genera el id de juego autoincremental.
 *
 * \return El id autoincrementado.
 *
 */
int generarNextIdJuego();

/** \brief Inicializa todas las posiciones del array de juegos poniendo el estado de isEmpty en 1
 *
 * \param listaJuegos[] El array completo de juegos
 * \param tamJuegos El tamaño del array de juegos
 * \return void
 *
 */
void inicializarJuegos(eJuego listaJuegos[], int tamJuegos);

/** \brief Sub menu juegos
 *
 * \param listaJuegos[] El array completo de juegos
 * \param tamJuegos El tamaño del array de juegos
 * \return void
 *
 */
void juegoMenu(eJuego listaJuegos[], int tamJuegos);

/** \brief Busca posiciones libres en el array de juegos
 *
 * \param listaEmpleados[] El array completo de juegos
 * \param tamJuegos El tamaño del array de juegos
 * \return -1 si no hay y el indice si Ok
 *
 */
int buscarLibreJuegos(eJuego listaJuegos[], int tamJuegos);

/** \brief Busca un juego y devuelve la posicion en el indice
 *
 * \param listaJuegos[] El array completo de juegos
 * \param tamJuegos El tamaño del array de juegos
 * \return -1 si no encontro y el indice si Ok
 *
 */
int buscarJuego(eJuego listaJuegos[], int tamJuegos, int idJuego);

/** \brief Agrega juegos en posiciones libres
 *
 * \param listaJuegos[] El array completo de juegos
 * \param tamJuegos El tamaño del array de juegos
 * \return void
 *
 */
void agregarJuego(eJuego listaJuegos[], int tamJuegos);

/** \brief Muestra 1 juego por pantalla
 *
 * \param juego El juego que quiero mostrar
 * \return void
 *
 */
void mostrarJuego(eJuego juego);

/** \brief Muestra todos los juegos por pantalla cuyo isEmpty es 0
 *
 * \param listaJuegos El array completo de juegos
 * \param tamJuegos El tamaño del array de juegos
 * \return void
 *
 */
void mostrarJuegos(eJuego listaJuegos[], int tamJuegos);

/** \brief Borra un juego del array elegido por id
 *
 * \param listaJuegos[] El array completo de juegos
 * \param tamJuegos El tamaño del array de juegos
 * \return void
 *
 */
void eliminarJuego(eJuego listaJuegos[], int tamJuegos);

/** \brief Modifica un juego del array elegido por id
 *
 * \param listaJuegos[] El array completo de juegos
 * \param tamClientes El tamaño del array de juegos
 * \return void
 *
 */
void modificarJuego(eJuego listaJuegos[], int tamClientes);

/** \brief Ordena array de estructuras con criterios solicitados
 *
 * \param eJuego *misJuegos
 * \param int largoJuego
 * \return Devuelve 0
 *
 */
int ordenarJuegos(eJuego *misJuegos, int tamJuego);
#endif // JUEGOS_H_INCLUDED
