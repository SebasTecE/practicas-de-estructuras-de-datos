#include <iostream>
#include <string>
using namespace std;

int main() {
    // ---- Nivel 1: estructura base y variables ----

    // Datos del alumno
    string nombre;
    int edad;

    // Calificaciones
    float calificacion1, calificacion2, calificacion3;
    float promedio;

    cout << "=== Sistema de Calificaciones Escolares ===" << endl;

    // Pedir los datos al usuario
    cout << "Nombre del estudiante: ";
    getline(cin, nombre);

    cout << "Edad: ";
    cin >> edad;

    cout << "Calificacion 1: ";
    cin >> calificacion1;

    cout << "Calificacion 2: ";
    cin >> calificacion2;

    cout << "Calificacion 3: ";
    cin >> calificacion3;

    // Calcular el promedio
    promedio = (calificacion1 + calificacion2 + calificacion3) / 3;

    // Imprimir resumen
    cout << "\n--- Resumen ---" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Promedio: " << promedio << endl;

    return 0;
}