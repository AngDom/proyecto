#include <iostream>
using namespace std;

void imprimirEspacios(int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        cout << " ";
    }
}

int contarDigitos(int numero) {
    int digitos = 0;
    do {
        numero /= 10;
        digitos++;
    } while (numero > 0);
    return digitos;
}

int main() {
    int a = 45;
    int b = 32;

    int unidad = b % 10;
    int decena = b / 10;

    int parcial1 = a * unidad;
    int parcial2 = a * decena;
    int total = parcial1 + parcial2 * 10;

    // Contar la cantidad de dígitos del total para saber cuánto alinear
    int ancho = contarDigitos(total);

    imprimirEspacios(ancho - contarDigitos(a));
    cout << a << endl;

    cout << "x ";
    imprimirEspacios(ancho - contarDigitos(b) - 2); // -2 por "x "
    cout << b << endl;

    for (int i = 0; i < ancho; i++) cout << "-";
    cout << endl;

    imprimirEspacios(ancho - contarDigitos(parcial1));
    cout << parcial1 << endl;

    imprimirEspacios(ancho - contarDigitos(parcial2) - 1); // -1 para simular el desplazamiento
    cout << parcial2 << "0" << endl; // agregar el 0 a la derecha

    for (int i = 0; i < ancho; i++) cout << "-";
    cout << endl;

    cout << total << endl;

    return 0;
}


