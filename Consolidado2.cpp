#include <iostream>
#include <string.h>

using namespace std;

// Estructura base del nodo
struct Nodo {
    int id;
    char nombre[50];
    Nodo* siguiente;
};

Nodo* listaProcesos = NULL;     // Lista de procesos
Nodo* frenteColaCPU = NULL;    // Prioridad de Cola 
Nodo* finalColaCPU = NULL;
Nodo* cimaMemoria = NULL;      // Pila de memoria

// === FUNCIONES PARA LISTA DE PROCESOS ===
void registrarProceso(int id, const char nombre[]) {
    Nodo* nuevo = new Nodo();
    nuevo->id = id;
    strcpy(nuevo->nombre, nombre);
    nuevo->siguiente = listaProcesos;
    listaProcesos = nuevo;
    cout << "Proceso registrado." << endl;
}

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

// === FUNCIONES PARA COLA ===
void agregarACola(int id, const char nombre[]) {
    Nodo* nuevo = new Nodo();
    nuevo->id = id;
    strcpy(nuevo->nombre, nombre);
    nuevo->siguiente = NULL;

    if (finalColaCPU == NULL) {
        frenteColaCPU = finalColaCPU = nuevo;
    } else {
        finalColaCPU->siguiente = nuevo;
        finalColaCPU = nuevo;
    }
    cout << "Proceso agregado a cola ." << endl;
}

void ejecutarSiguienteProceso() {
    if (frenteColaCPU == NULL) {
        cout << "No hay procesos en cola para ejecutar." << endl;
        return;
    }

    Nodo* temp = frenteColaCPU;
    cout << "Ejecutando proceso: " << temp->nombre << " (ID: " << temp->id << ")" << endl;

    frenteColaCPU = frenteColaCPU->siguiente;
    delete temp;

    if (frenteColaCPU == NULL)
        finalColaCPU = NULL;
}

// === FUNCIONES PARA PILA  ===
void asignarBloqueMemoria(int id) {
    Nodo* nuevo = new Nodo();
    nuevo->id = id;
    nuevo->siguiente = cimaMemoria;
    cimaMemoria = nuevo;
    cout << "Bloque en pila asignado." << endl;
}

void liberarBloqueMemoria() {
    if (cimaMemoria == NULL) {
        cout << "No hay bloques en la pila." << endl;
        return;
    }

    Nodo* temp = cimaMemoria;
    cout << "Liberando bloque de memoria (ID: " << temp->id << ")" << endl;
    cimaMemoria = cimaMemoria->siguiente;
    delete temp;
}

// === MEN� PRINCIPAL ===
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
        cout << "Ingrese opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese ID del proceso: ";
                cin >> id;
                cout << "Ingrese nombre del proceso: ";
                cin >> nombre;
                registrarProceso(id, nombre);
                break;

            case 2:
                mostrarProcesos();
                break;

            case 3:
                cout << "Ingrese ID del proceso: ";
                cin >> id;
                cout << "Ingrese nombre del proceso: ";
                cin >> nombre;
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
                cout << "Opcion no valida." << endl;
        }
    } while (opcion != 7);

    return 0;
}
