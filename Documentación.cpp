#include <iostream>   // Para entrada/salida (cin, cout)
#include <string.h>   // Para funciones de manipulación de cadenas (strcpy)

using namespace std;

// Estructura base para representar un nodo genérico
// Puede ser usado para procesos o bloques de memoria
struct Nodo {
    int id;              // Identificador único del proceso o bloque
    char nombre[50];     // Nombre del proceso o descripción del bloque
    Nodo* siguiente;     // Puntero al siguiente nodo en la estructura
};

// Variables globales que apuntan a las diferentes estructuras de datos
Nodo* listaProcesos = NULL;     // Lista de procesos registrados
Nodo* frenteColaCPU = NULL;    // Frente de la cola FIFO (procesos listos para ejecutar)
Nodo* finalColaCPU = NULL;     // Final de la cola FIFO
Nodo* cimaMemoria = NULL;      // Cima de la pila LIFO (bloques de memoria asignados)

// === FUNCIONES PARA LISTA DE PROCESOS ===

/**
 * Registra un nuevo proceso al inicio de la lista enlazada.
 *
 * @param id     Identificador del proceso
 * @param nombre Nombre del proceso
 */
void registrarProceso(int id, const char nombre[]) {
    Nodo* nuevo = new Nodo();                  // Crear nuevo nodo
    nuevo->id = id;                            // Asignar ID
    strcpy(nuevo->nombre, nombre);             // Copiar nombre
    nuevo->siguiente = listaProcesos;          // Apuntar al primer nodo actual
    listaProcesos = nuevo;                     // Actualizar cabeza de lista
    cout << "Proceso registrado." << endl;
}

/**
 * Muestra todos los procesos almacenados en la lista.
 */
void mostrarProcesos() {
    Nodo* temp = listaProcesos;
    if (temp == NULL) {
        cout << "No hay procesos registrados." << endl;
        return;
    }
    while (temp != NULL) {
        cout << "ID: " << temp->id << ", Nombre: " << temp->nombre << endl;
        temp = temp->siguiente;
    }
}

// === FUNCIONES PARA COLA DE PROCESOS (FIFO) ===

/**
 * Agrega un proceso al final de la cola FIFO.
 *
 * @param id     Identificador del proceso
 * @param nombre Nombre del proceso
 */
void agregarACola(int id, const char nombre[]) {
    Nodo* nuevo = new Nodo();
    nuevo->id = id;
    strcpy(nuevo->nombre, nombre);
    nuevo->siguiente = NULL;

    if (finalColaCPU == NULL) {
        // Si la cola está vacía, ambos punteros apuntan al mismo nodo
        frenteColaCPU = finalColaCPU = nuevo;
    } else {
        // Agregar al final y actualizar finalColaCPU
        finalColaCPU->siguiente = nuevo;
        finalColaCPU = nuevo;
    }
    cout << "Proceso agregado a cola ." << endl;
}

/**
 * Ejecuta el siguiente proceso en la cola FIFO y lo elimina.
 */
void ejecutarSiguienteProceso() {
    if (frenteColaCPU == NULL) {
        cout << "No hay procesos en cola para ejecutar." << endl;
        return;
    }

    Nodo* temp = frenteColaCPU;
    cout << "Ejecutando proceso: " << temp->nombre << " (ID: " << temp->id << ")" << endl;

    frenteColaCPU = frenteColaCPU->siguiente;  // Avanzar frente
    delete temp;                               // Liberar memoria del nodo

    if (frenteColaCPU == NULL) {
        // Si cola queda vacía, también reiniciar final
        finalColaCPU = NULL;
    }
}

// === FUNCIONES PARA PILA DE MEMORIA (LIFO) ===

/**
 * Simula la asignación de un bloque de memoria (usa una pila LIFO).
 *
 * @param id Identificador del bloque de memoria
 */
void asignarBloqueMemoria(int id) {
    Nodo* nuevo = new Nodo();
    nuevo->id = id;
    nuevo->siguiente = cimaMemoria;   // Apuntar al bloque anterior
    cimaMemoria = nuevo;              // Actualizar cima de la pila
    cout << "Bloque en pila asignado." << endl;
}

/**
 * Libera el último bloque de memoria asignado (el de la cima de la pila).
 */
void liberarBloqueMemoria() {
    if (cimaMemoria == NULL) {
        cout << "No hay bloques en la pila." << endl;
        return;
    }

    Nodo* temp = cimaMemoria;
    cout << "Liberando bloque de memoria (ID: " << temp->id << ")" << endl;
    cimaMemoria = cimaMemoria->siguiente;  // Bajar cima
    delete temp;                           // Liberar memoria del nodo
}

// === MENÚ PRINCIPAL ===

/**
 * Función principal del programa. Muestra un menú interactivo
 * y permite probar todas las funcionalidades implementadas.
 */
int main() {
    int opcion, id;
    char nombre[50];

    do {
        cout << "\n=== SISTEMA DE GESTION DE PROCESOS ===" << endl;
        cout << "1. Registrar proceso" << endl;
        cout << "2. Mostrar procesos" << endl;
        cout << "3. Agregar proceso a la Cola" << endl;
        cout << "4. Ejecutar siguiente proceso de cola" << endl;
        cout << "5. Asignar proceso a Pila" << endl;
        cout << "6. Liberar Pila" << endl;
        cout << "7. Salir" << endl;
        cout << "Ingrese opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese ID del proceso: ";
                cin >> id;
                cin.ignore();  // Limpiar buffer
                cout << "Ingrese nombre del proceso: ";
                cin.getline(nombre, 50);
                registrarProceso(id, nombre);
                break;

            case 2:
                mostrarProcesos();
                break;

            case 3:
                cout << "Ingrese ID del proceso: ";
                cin >> id;
                cin.ignore();
                cout << "Ingrese nombre del proceso: ";
                cin.getline(nombre, 50);
                agregarACola(id, nombre);
                break;

            case 4:
                ejecutarSiguienteProceso();
                break;

            case 5:
                cout << "Ingrese ID del bloque de memoria: ";
                cin >> id;
                asignarBloqueMemoria(id);
                break;

            case 6:
                liberarBloqueMemoria();
                break;

            case 7:
                cout << "Saliendo..." << endl;
                break;

            default:
                cout << "Opción no válida." << endl;
        }
    } while (opcion != 7);

    return 0;
}
