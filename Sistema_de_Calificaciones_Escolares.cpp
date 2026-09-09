#include <iostream>
#include <string>
using namespace std;

int main() {
    // Nivel 1: estructura base y variables

    string nombre;
    int edad;
    float calificacion1, calificacion2, calificacion3;
    float promedio;

    cout << "=== Sistema de Calificaciones Escolares ===" << endl;

    cout << "Nombre del estudiante: ";
    getline(cin, nombre);

    cout << "Edad: ";
    cin >> edad;

    // Nivel 2: validacion de edad
    if (edad < 0 || edad > 120) {
        cout << "Edad invalida" << endl;
        return 1;
    }

    cout << "Calificacion 1: ";
    cin >> calificacion1;

    cout << "Calificacion 2: ";
    cin >> calificacion2;

    cout << "Calificacion 3: ";
    cin >> calificacion3;

    // Nivel 2: validacion de calificaciones
    if (calificacion1 < 0 || calificacion1 > 10 ||
        calificacion2 < 0 || calificacion2 > 10 ||
        calificacion3 < 0 || calificacion3 > 10) {
        cout << "Error: alguna calificacion no esta entre 0 y 10" << endl;
        return 1;
    }

    // Calcular el promedio
    promedio = (calificacion1 + calificacion2 + calificacion3) / 3;

    // Nivel 2: determinar estado con if-else
    string estado;
    if (promedio >= 9) {
        estado = "EXCELENTE";
    } else if (promedio >= 7) {
        estado = "APROBADO";
    } else if (promedio >= 6) {
        estado = "REGULAR";
    } else {
        estado = "REPROBADO";
    }

    cout << "\n--- Resumen ---" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Promedio: " << promedio << endl;
    cout << "Estado: " << estado << endl;

    return 0;
}