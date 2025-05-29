int main() {
    int opcion, id;
    char nombre[50];

    do {
        cout << "\n";
        cout << "========================================\n";
        cout << "=== SISTEMA DE GESTIÓN DE PROCESOS ===\n";
        cout << "========================================\n";
        cout << "1. Registrar proceso\n";
        cout << "2. Mostrar procesos\n";
        cout << "3. Agregar proceso a la Cola\n";
        cout << "4. Ejecutar siguiente proceso de cola\n";
        cout << "5. Asignar proceso a Pila\n";
        cout << "6. Liberar Pila\n";
        cout << "7. Salir\n";
        cout << "Ingrese opción: ";
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
