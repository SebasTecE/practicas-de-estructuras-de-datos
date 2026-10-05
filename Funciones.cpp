#include <iostream>
#include <string>
using namespace std;

void mostrarMenu();
int leerEntero(string mensaje, int minVal, int maxVal);
float leerCalificacion(int numero);
float calcularPromedio(float suma, int n);
string obtenerEstado(float promedio);
void registrarEstudiante();

int main() {
    int opcion;

    do {
        mostrarMenu();
        opcion = leerEntero("Opcion: ", 1, 4);

        switch (opcion) {
            case 1:
            case 4:
                registrarEstudiante();
                break;
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

void mostrarMenu() {
    cout << "\n=== SISTEMA DE CALIFICACIONES ===" << endl;
    cout << "1. Registrar estudiante" << endl;
    cout << "2. Ver informacion del programa" << endl;
    cout << "3. Salir" << endl;
    cout << "4. Registrar otro estudiante" << endl;
}

int leerEntero(string mensaje, int minVal, int maxVal) {
    int valor;
    cout << mensaje;
    cin >> valor;

    while (cin.fail() || valor < minVal || valor > maxVal) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Valor invalido, ingresa de nuevo (" << minVal << "-" << maxVal << "): ";
        cin >> valor;
    }

    cin.ignore(10000, '\n');
    return valor;
}

float leerCalificacion(int numero) {
    float cal;
    cout << "Calificacion " << numero << ": ";
    cin >> cal;

    while (cin.fail() || cal < 0 || cal > 10) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Calificacion invalida, ingresa de nuevo (0-10): ";
        cin >> cal;
    }

    return cal;
}

float calcularPromedio(float suma, int n) {
    return suma / n;
}

string obtenerEstado(float promedio) {
    if (promedio >= 9) return "EXCELENTE";
    else if (promedio >= 7) return "APROBADO";
    else if (promedio >= 6) return "REGULAR";
    else return "REPROBADO";
}

void registrarEstudiante() {
    string nombre;
    cout << "\nNombre del estudiante: ";
    getline(cin, nombre);

    int edad = leerEntero("Edad: ", 0, 120);
    int n = leerEntero("Cuantas calificaciones deseas registrar? ", 1, 100);

    float suma = 0;
    int aprobadas = 0, reprobadas = 0;
    float notaMax, notaMin;

    for (int i = 1; i <= n; i++) {
        float cal = leerCalificacion(i);

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

    float promedio = calcularPromedio(suma, n);
    string estado = obtenerEstado(promedio);

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
}