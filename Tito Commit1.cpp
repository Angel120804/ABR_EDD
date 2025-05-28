do {
        // Muestra el menú de opciones
        cout << "\n=== SISTEMA DE GESTIÓN DE PROCESOS ===" << endl;
        cout << "1. Registrar proceso" << endl;
        cout << "2. Mostrar procesos" << endl;
        cout << "3. Agregar proceso a la Cola" << endl;
        cout << "4. Ejecutar siguiente proceso de cola" << endl;
        cout << "5. Asignar proceso a Pila" << endl;
        cout << "6. Liberar Pila" << endl;
        cout << "7. Salir" << endl;
        cout << "Ingrese opción: ";
        cin >> opcion;                          // Lee la opción del usuario

        switch (opcion) {
            case 1:
                cout << "Ingrese ID del proceso: ";
                cin >> id;                      // Solicita el ID
                cout << "Ingrese nombre del proceso: ";
                cin >> nombre;                  // Solicita el nombre
                registrarProceso(id, nombre);   // Llama a la función para registrar
                break;

            case 2:
                mostrarProcesos();              // Llama a la función para mostrar procesos
                break;

            case 3:
                cout << "Ingrese ID del proceso: ";
                cin >> id;
                cout << "Ingrese nombre del proceso: ";
                cin >> nombre;
                agregarACola(id, nombre);       // Llama a la función para agregar a la cola
                break;
