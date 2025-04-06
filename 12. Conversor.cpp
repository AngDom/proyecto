#include <iostream>
using namespace std;

int main() {
    int digito[20];
    int decimal, residuo, resultado, valor = 0;

    cout << "Ingrese el valor a convertir de decimal a hexadecimal: ";
    cin >> decimal;

    do {
        residuo = decimal % 16;
        resultado = decimal / 16;
        digito[valor] = residuo;
        decimal = resultado;
        valor++;
    } while (resultado > 15);

    digito[valor] = resultado;

    cout << "La conversion equivalente a hexadecimal es: ";

    for (int m = valor; m >= 0; m--) {
        if (digito[m] == 10) {
            cout << "A";
        } else if (digito[m] == 11) {
            cout << "B";
        } else if (digito[m] == 12) {
            cout << "C";
        } else if (digito[m] == 13) {
            cout << "D";
        } else if (digito[m] == 14) {
            cout << "E";
        } else if (digito[m] == 15) {
            cout << "F";
        } else {
            cout <<digito[m];
        }
    }

    cout << endl;
}
