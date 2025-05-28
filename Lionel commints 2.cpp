            case 4:
                if(frenteColaCPU == NULL) {
                    cout << "\n[ADVERTENCIA] La cola de procesos está vacía" << endl;
                } else {
                    cout << "\n=== INICIANDO EJECUCIÓN ===" << endl;
                    ejecutarSiguienteProceso();
                    cout << "Operación completada exitosamente" << endl;
                }
                break;

            case 5:
                cout << "\n=== ASIGNAR MEMORIA ===" << endl;
                cout << "Ingrese ID del bloque (número positivo): ";
                cin >> id;
                if(id > 0) {
                    asignarBloqueMemoria(id);
                    cout << "Operación de asignación finalizada" << endl;
                } else {
                    cout << "[ERROR] ID debe ser un número positivo" << endl;
                }
                break;

            case 6:
                cout << "\n=== LIBERAR MEMORIA ===" << endl;
                if(cimaMemoria == NULL) {
                    cout << "No hay bloques para liberar" << endl;
                } else {
                    liberarBloqueMemoria();
                    cout << "Memoria liberada correctamente" << endl;
                }
                break;

            case 7:
                cout << "\n=== SISTEMA ===" << endl;
                cout << "Cerrando todas las operaciones..." << endl;
                cout << "Sesión finalizada" << endl;
                break;

            default:
                cout << "\n[ERROR] Opción no reconocida" << endl;
                cout << "Por favor ingrese un número entre 1 y 7" << endl;
        }
    } while (opcion != 7);  // Mantener en ciclo hasta recibir comando de salida
