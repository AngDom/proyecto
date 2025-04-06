#include <iostream>
#include <locale.h>
using namespace std;

int main() {
    setlocale(LC_ALL, "");

    int numero;

    while (true) {
        cout << "\nDigita un número en el rango de 0 a 9999 (o -1 para salir): ";
        cin >> numero;

        if (numero == -1) {
            cout << "Programa terminado.\n";
            break;
        }

        if (numero >= 0 && numero <= 9999) {
            int unidad = numero % 10;
            numero /= 10;
            int decena = numero % 10;
            numero /= 10;
            int centena = numero % 10;
            numero /= 10;
            int unimil = numero % 10;

            // UNIDADES DE MIL
            switch (unimil) {
                case 0: cout << ""; break;
                case 1: cout << "mil "; break;
                case 2: cout << "dos mil "; break;
                case 3: cout << "tres mil "; break;
                case 4: cout << "cuatro mil "; break;
                case 5: cout << "cinco mil "; break;
                case 6: cout << "seis mil "; break;
                case 7: cout << "siete mil "; break;
                case 8: cout << "ocho mil "; break;
                case 9: cout << "nueve mil "; break;
            }

            // CENTENAS
            switch (centena) {
                case 0: break;
                case 1:
                    if (decena == 0 && unidad == 0) {
                        cout << "cien ";
                    } else {
                        cout << "ciento ";
                    }
                    break;
                case 2: cout << "doscientos "; break;
                case 3: cout << "trescientos "; break;
                case 4: cout << "cuatrocientos "; break;
                case 5: cout << "quinientos "; break;
                case 6: cout << "seiscientos "; break;
                case 7: cout << "setecientos "; break;
                case 8: cout << "ochocientos "; break;
                case 9: cout << "novecientos "; break;
            }

            // DECENAS Y UNIDADES
            if (decena == 1) {
                switch (unidad) {
                    case 0: cout << "diez"; break;
                    case 1: cout << "once"; break;
                    case 2: cout << "doce"; break;
                    case 3: cout << "trece"; break;
                    case 4: cout << "catorce"; break;
                    case 5: cout << "quince"; break;
                    case 6: cout << "dieciséis"; break;
                    case 7: cout << "diecisiete"; break;
                    case 8: cout << "dieciocho"; break;
                    case 9: cout << "diecinueve"; break;
                }
            } else if (decena == 2) {
                switch (unidad) {
                    case 0: cout << "veinte"; break;
                    case 1: cout << "veintiuno"; break;
                    case 2: cout << "veintidós"; break;
                    case 3: cout << "veintitrés"; break;
                    case 4: cout << "veinticuatro"; break;
                    case 5: cout << "veinticinco"; break;
                    case 6: cout << "veintiséis"; break;
                    case 7: cout << "veintisiete"; break;
                    case 8: cout << "veintiocho"; break;
                    case 9: cout << "veintinueve"; break;
                }
            } else {
                switch (decena) {
                    case 3: cout << "treinta"; break;
                    case 4: cout << "cuarenta"; break;
                    case 5: cout << "cincuenta"; break;
                    case 6: cout << "sesenta"; break;
                    case 7: cout << "setenta"; break;
                    case 8: cout << "ochenta"; break;
                    case 9: cout << "noventa"; break;
                }

                if (decena >= 3 && unidad != 0) {
                    cout << " y ";
                }

                if (decena != 1 && decena != 2) {
                    switch (unidad) {
                        case 1: cout << "uno"; break;
                        case 2: cout << "dos"; break;
                        case 3: cout << "tres"; break;
                        case 4: cout << "cuatro"; break;
                        case 5: cout << "cinco"; break;
                        case 6: cout << "seis"; break;
                        case 7: cout << "siete"; break;
                        case 8: cout << "ocho"; break;
                        case 9: cout << "nueve"; break;
                        case 0:
                            if (unimil == 0 && centena == 0 && decena == 0)
                                cout << "cero";
                            break;
                    }
                }
            }

        } else {
            cout << "ERROR: Debes ingresar un valor entre 0 y 9999.";
        }

        cout << "\n";
    }

    return 0;
}

