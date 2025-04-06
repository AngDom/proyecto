#include <iostream>
using namespace std;

int main() {
    double ingresos, egresos, deudas, meta, ahorroMensual;
    string objetivo;

    cout << "Ingrese su ingreso mensual: ";
    cin >> ingresos;
    cout << "Ingrese sus egresos mensuales: ";
    cin >> egresos;
    cout << "Ingrese sus deudas mensuales: ";
    cin >> deudas;
    cout << "Ingrese el monto que desea ahorrar (ej. carro, casa): ";
    cin >> meta;
    cin.ignore(); 
    cout << "Escriba el motivo del ahorro: ";
    getline(cin, objetivo);

    ahorroMensual = ingresos - egresos - deudas;

    if (ahorroMensual <= 0) {
        cout << "No es posible ahorrar con los ingresos actuales." << endl;
    } else {
        int meses = meta / ahorroMensual;
        cout << "Puede ahorrar " << ahorroMensual << " quetzales por mes." << endl;
        cout << "Tardara aproximadamente " << meses << " meses en ahorrar para su " << objetivo << "." << endl;
    }

    return 0;
}

