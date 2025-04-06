#include <iostream>
#include <string>

using namespace std;

// Estados del cajero
enum Estado {
    INICIO,
    MENU,
    CONSULTAR_SALDO,
    RETIRAR_DINERO,
    SALIR
};

int main() {
    Estado estadoActual = INICIO;
    string usuario, pin;
    double saldo = 8000.0; // Saldo inicial
    bool sesionIniciada = false;

    while (estadoActual != SALIR) {
        switch (estadoActual) {
            case INICIO:
                cout << "Bienvenido al Cajero Automatico\n";
                cout << "Ingrese su usuario: ";
                cin >> usuario;
                cout << "Ingrese su PIN: ";
                cin >> pin;

                // Validamos usuario y pin (simulado)
                if (usuario == "Audias" && pin == "1234") {
                    sesionIniciada = true;
                    estadoActual = MENU;
                } else {
                    cout << "Usuario o PIN incorrecto. Intente de nuevo.\n\n";
                }
                break;

            case MENU:
                int opcion;
                cout << "\n--- Menu Principal ---\n";
                cout << "1. Consultar Saldo\n";
                cout << "2. Retirar Dinero\n";
                cout << "3. Salir\n";
                cout << "Seleccione una opcion: ";
                cin >> opcion;

                switch (opcion) {
                    case 1:
                        estadoActual = CONSULTAR_SALDO;
                        break;
                    case 2:
                        estadoActual = RETIRAR_DINERO;
                        break;
                    case 3:
                        estadoActual = SALIR;
                        break;
                    default:
                        cout << "Opcion invalida. Intente de nuevo.\n";
                }
                break;

            case CONSULTAR_SALDO:
                cout << "\nSu saldo actual es: Q" << saldo << "\n\n";
                estadoActual = MENU;
                break;

            case RETIRAR_DINERO:
                double retiro;
                cout << "\nIngrese la cantidad a retirar: Q";
                cin >> retiro;
                if (retiro <= saldo && retiro > 0) {
                    saldo -= retiro;
                    cout << "Retiro exitoso. Saldo restante: Q" << saldo << "\n\n";
                } else {
                    cout << "Fondos insuficientes o cantidad invalida.\n\n";
                }
                estadoActual = MENU;
                break;

            case SALIR:
                cout << "Gracias por usar el cajero. ¡Hasta pronto!\n";
                break;
        }
    }

    return 0;
}

