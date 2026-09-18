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

                                int n;
                cout << "Cuantas calificaciones deseas registrar? ";
                cin >> n;

                if (n <= 0) {
                    cout << "Debes registrar al menos una calificacion" << endl;
                    break;
                }

                float suma = 0;
                int aprobadas = 0, reprobadas = 0;
                float notaMax, notaMin;
                bool calificacionInvalida = false;

                for (int i = 1; i <= n; i++) {
                    float cal;
                    cout << "Calificacion " << i << ": ";
                    cin >> cal;

                    if (cal < 0 || cal > 10) {
                        cout << "Error: la calificacion debe estar entre 0 y 10" << endl;
                        calificacionInvalida = true;
                        break;
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

                if (calificacionInvalida) break;

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
            default:
                cout << "\nOpcion invalida, intenta de nuevo." << endl;
        }

    } while (opcion != 3);

    return 0;
}