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
        cout << "4. Registrar otro estudiante" << endl;
        do {
    cout << "Opcion: ";
    cin >> opcion;
    if (cin.fail()) {
        cout << "Opcion invalida, intenta de nuevo." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        opcion = -1; // fuerza a repetir el ciclo
        continue;
    }
    cin.ignore();
    if (opcion < 1 || opcion > 4) {
        cout << "Opcion invalida, intenta de nuevo." << endl;
    }
} while (opcion < 1 || opcion > 4);

        switch (opcion) {
            case 1: case 4:{
                string nombre;
                int edad;

                cout << "\nNombre del estudiante: ";
                getline(cin, nombre);

                cout << "Edad: ";
                cin >> edad;

                 while (cin.fail() || edad < 0 || edad > 120) {
                 cout << "Edad invalida, ingresa de nuevo: ";
                 cin.clear();
                 cin.ignore(10000, '\n');
                 cin >> edad;
                }

                                int n;
                cout << "Cuantas calificaciones deseas registrar? ";
                cin >> n;

                 while (cin.fail() || n <= 0) {
                 cout << "Debes registrar al menos una calificacion. Intenta de nuevo: ";
                 cin.clear();
                 cin.ignore(10000, '\n');
                 cin >> n;
                }

                float suma = 0;
                int aprobadas = 0, reprobadas = 0;
                float notaMax, notaMin;

                for (int i = 1; i <= n; i++) {
                    float cal;
                    cout << "Calificacion " << i << ": ";
                    cin >> cal;

                 while (cin.fail() || cal < 0 || cal > 10) {
                 cout << "Calificacion invalida, ingresa de nuevo (0-10): ";
                 cin.clear();
                 cin.ignore(10000, '\n');
                 cin >> cal;
                }

                    suma += cal;

                    if (cal >= 6) aprobadas++;
                    else reprobadas++;

                    if (i == 1) {
                        notaMax = cal;
                        notaMin = cal;
                    } else {
                        if (cal > notaMax) notaMax = cal;
                        if (cal < notaMin) notaMin = cal;
                    }
                }


                float promedio = suma / n;

                string estado;
                if (promedio >= 9) estado = "EXCELENTE";
                else if (promedio >= 7) estado = "APROBADO";
                else if (promedio >= 6) estado = "REGULAR";
                else estado = "REPROBADO";

                cout << "\n--- Resumen ---" << endl;
                cout << "Nombre: " << nombre << endl;
                cout << "Edad: " << edad << endl;
                cout << "Calificaciones registradas: " << n << endl;
                cout << "Promedio: " << promedio << endl;
                cout << "Calificacion mas alta: " << notaMax << endl;
                cout << "Calificacion mas baja: " << notaMin << endl;
                cout << "Aprobadas: " << aprobadas << endl;
                cout << "Reprobadas: " << reprobadas << endl;
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
        }

    } while (opcion != 3);

    return 0;
}