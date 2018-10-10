#ifndef NEGOCIO_H_INCLUDED
#define NEGOCIO_H_INCLUDED

typedef struct
{
    int idCliente;
    char apellido[51];
    char nombre[51];
    char sexo;
    char calle[51];
    int altura;
    int isEmptyCliente;
}eCliente;

typedef struct
{
    int idJuego;
    char descripcion[51];
    float importe;
    int isEmptyJuegos;
}eJuego;

typedef struct
{
    int dia;
    int mes;
    int anio;
    int isEmpty;
}eFecha;

typedef struct
{
    int idAlquiler;
    int idJuegoAlq;
    int idClienteAlq;
    eFecha fecha;
    int isEmptyAqluiler;
}eAlquiler;

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

/** \brief Genera el id de cliente autoincremental.
 *
 * \return El id autoincrementado.
 *
 */
int generarNextIdCliente();

/** \brief Inicializa todas las posiciones del array de clientes poniendo el estado de isEmpty en 1
 *
 * \param listaClientes[] El array completo de clientes
 * \param tamCliente El tamaño del array de clientes
 * \return void
 *
 */
void inicializarClientes(eCliente listaClientes[], int tamCliente);

/** \brief Sub menu clientes
 *
 * \param listaClientes[] El array completo de clientes
 * \param tamCliente El tamaño del array de clientes
 * \return void
 *
 */
void clienteMenu(eCliente listaClientes[], int tamCliente);

/** \brief Busca posiciones libres en el array de clientes
 *
 * \param listaEmpleados[] El array completo de clientes
 * \param tamCliente El tamaño del array de clientes
 * \return -1 si no hay y el indice si Ok
 *
 */
int buscarLibreClientes(eCliente listaClientes[], int tamCliente);

/** \brief Busca un cliente y devuelve la posicion en el indice
 *
 * \param listaClientes[] El array completo de clientes
 * \param tamCliente El tamaño del array de clientes
 * \return -1 si no encontro y el indice si Ok
 *
 */
int buscarCliente(eCliente listaClientes[], int tamCliente, int idCliente);

/** \brief Agrega clientes en posiciones libres
 *
 * \param listaClientes[] El array completo de clientes
 * \param tamCliente El tamaño del array de clientes
 * \return void
 *
 */
void agregarCliente(eCliente listaClientes[], int tamCliente);

/** \brief Muestra 1 cliente por pantalla
 *
 * \param cliente El cliente que quiero mostrar
 * \return void
 *
 */
void mostrarCliente(eCliente cliente);

/** \brief Muestra todos los clientes por pantalla cuyo isEmpty es 0
 *
 * \param listaClientes El array completo de clientes
 * \param tamCliente El tamaño del array de clientes
 * \return void
 *
 */
void mostrarClientes(eCliente listaClientes[], int tamCliente);

/** \brief Borra un cliente del array elegido por id
 *
 * \param listaClientes[] El array completo de clientes
 * \param tamCliente El tamaño del array de clientes
 * \return void
 *
 */
void eliminarCliente(eCliente listaClientes[], int tamCliente);

/** \brief Modifica un cliente del array elegido por id
 *
 * \param listaClientes[] El array completo de clientes
 * \param tamClientes El tamaño del array de clientes
 * \return void
 *
 */
void modificarCliente(eCliente listaClientes[], int tamClientes);

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

#endif // NEGOCIO_H_INCLUDED
