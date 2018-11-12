#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

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
#endif // CLIENTES_H_INCLUDED
