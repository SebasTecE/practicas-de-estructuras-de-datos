#include <iostream>
#include <string>
using namespace std;

int main() {
    int opcion;

    do {
        cout << "\n=== SISTEMA DE CALIFICACIONES ===" << endl;
        cout << "1. Registrar estudiante" << endl;
        cout << "2. Ver informacion del programa" << endl;
        cout << "3. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1: {
                string nombre;
                int edad;

                cout << "\nNombre del estudiante: ";
                getline(cin, nombre);

                cout << "Edad: ";
                cin >> edad;

                if (edad < 0 || edad > 120) {
                    cout << "Edad invalida" << endl;
                    break;
                }

                float calificacion1, calificacion2, calificacion3;
                cout << "Calificacion 1: ";
                cin >> calificacion1;
                cout << "Calificacion 2: ";
                cin >> calificacion2;
                cout << "Calificacion 3: ";
                cin >> calificacion3;

                if (calificacion1 < 0 || calificacion1 > 10 ||
                    calificacion2 < 0 || calificacion2 > 10 ||
                    calificacion3 < 0 || calificacion3 > 10) {
                    cout << "Error: alguna calificacion no esta entre 0 y 10" << endl;
                    break;
                }

                float promedio = (calificacion1 + calificacion2 + calificacion3) / 3;

                string estado;
                if (promedio >= 9) estado = "EXCELENTE";
                else if (promedio >= 7) estado = "APROBADO";
                else if (promedio >= 6) estado = "REGULAR";
                else estado = "REPROBADO";

                cout << "\n--- Resumen ---" << endl;
                cout << "Nombre: " << nombre << endl;
                cout << "Edad: " << edad << endl;
                cout << "Promedio: " << promedio << endl;
                cout << "Estado: " << estado << endl;

                break;
            }
            case 2:
                cout << "\n--- Informacion del programa ---" << endl;
                cout << "Sistema de Calificaciones Escolares" << endl;
                cout << "Practica de Estructuras de Datos - ITE" << endl;
                cout << "Autor: Sebastian Grijalva Ochoa" << endl;
                break;
            case 3:
                cout << "\nSaliendo del programa..." << endl;
                break;
            default:
                cout << "\nOpcion invalida, intenta de nuevo." << endl;
        }

    } while (opcion != 3);

    return 0;
}