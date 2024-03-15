#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct RegistroTemperatura {
    string fecha;
    float manana;
    float tarde;
    float noche;
};

// Función para ingresar los registros de temperatura
void ingresarRegistros(RegistroTemperatura registros[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Ingrese la fecha para el día " << i + 1 << ": ";
        cin >> registros[i].fecha;
        cout << "Ingrese la temperatura de la mañana: ";
        cin >> registros[i].manana;
        cout << "Ingrese la temperatura de la tarde: ";
        cin >> registros[i].tarde;
        cout << "Ingrese la temperatura de la noche: ";
        cin >> registros[i].noche;
    }
}

// Función para mostrar los registros de temperatura
void mostrarRegistros(RegistroTemperatura registros[], int n) {
    cout << "Registros de temperatura:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Fecha: " << registros[i].fecha << endl;
        cout << "Mañana: " << registros[i].manana << "°C" << endl;
        cout << "Tarde: " << registros[i].tarde << "°C" << endl;
        cout << "Noche: " << registros[i].noche << "°C" << endl;
        cout << endl;
    }
}

// Función para calcular el promedio de temperatura del día
float promedioTemperaturaDia(const RegistroTemperatura& registro) {
    return (registro.manana + registro.tarde + registro.noche) / 3.0;
}

// Función para calcular el promedio de temperatura de todos los registros
float promedioTemperaturaTotal(RegistroTemperatura registros[], int n) {
    float sumaTotal = 0;
    for (int i = 0; i < n; ++i) {
        sumaTotal += promedioTemperaturaDia(registros[i]);
    }
    return sumaTotal / n;
}

int main() {
    const int n = 3; // Número de días
    RegistroTemperatura registros[n];

    // Ingresar los registros de temperatura
    ingresarRegistros(registros, n);

    // Mostrar los registros de temperatura
    mostrarRegistros(registros, n);

    // Calcular y mostrar el promedio de temperatura del día
    cout << "Promedio de temperatura del día:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Día " << i + 1 << ": " << promedioTemperaturaDia(registros[i]) << "°C" << endl;
    }

    // Calcular y mostrar el promedio de temperatura de todos los registros
    cout << "Promedio de temperatura de todos los registros: " << promedioTemperaturaTotal(registros, n) << "°C" << endl;

    return 0;
}
