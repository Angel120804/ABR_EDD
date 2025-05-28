#include <iostream>             // Biblioteca para entrada y salida estándar (cout, cin)
#include <string.h>             // Biblioteca para funciones con cadenas tipo C (strcpy)

using namespace std;            // Permite usar cout, cin, etc., sin anteponer std::

// Definición de la estructura Nodo
struct Nodo {
    int id;                     // ID del proceso o bloque de memoria
    char nombre[50];           // Nombre del proceso (máx 49 caracteres + '\0')
    Nodo* siguiente;           // Puntero al siguiente nodo (lista, cola o pila)
};

// Declaración de punteros globales para las estructuras de datos
Nodo* listaProcesos = NULL;     // Lista enlazada de procesos registrados
Nodo* frenteColaCPU = NULL;     // Frente de la cola de procesos (para ejecución)
Nodo* finalColaCPU = NULL;      // Final de la cola
Nodo* cimaMemoria = NULL;       // Cima de la pila de bloques de memoria

// === FUNCIONES PARA MANEJAR LA LISTA DE PROCESOS ===
void registrarProceso(int id, const char nombre[]) {
    Nodo* nuevo = new Nodo();                   // Crea nuevo nodo dinámicamente
    nuevo->id = id;                             // Asigna el ID al nuevo nodo
    strcpy(nuevo->nombre, nombre);              // Copia el nombre al nuevo nodo
    nuevo->siguiente = listaProcesos;           // Apunta al nodo actual de la lista
    listaProcesos = nuevo;                      // Actualiza el inicio de la lista
    cout << "Proceso registrado." << endl;      // Mensaje de confirmación
}
