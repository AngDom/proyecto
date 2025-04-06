#include <iostream>

using namespace std;

void cuadrado(int lado) {
    for (int i = 0; i < lado; i++) {
        for (int j = 0; j < lado; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

void triangulo(int altura) {
    for (int i = 1; i <= altura; i++) {
        for (int j = 0; j < i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

void rectangulo(int ancho, int alto) {
    for (int i = 0; i < alto; i++) {
        for (int j = 0; j < ancho; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

int main() {
    int opcion;
    cout << "Seleccione una figura:\n";
    cout << "1. Cuadrado\n2. Triangulo\n3. Rectangulo\n";
    cin >> opcion;

    switch (opcion) {
        case 1:
            int lado;
            cout << "Ingrese el tamaño del lado: ";
            cin >> lado;
            cuadrado(lado);
            break;
        case 2:
            int altura;
            cout << "Ingrese la altura del triangulo: ";
            cin >> altura;
            triangulo(altura);
            break;
        case 3:
            int ancho, alto;
            cout << "Ingrese el ancho: ";
            cin >> ancho;
            cout << "Ingrese el alto: ";
            cin >> alto;
            rectangulo(ancho, alto);
            break;
        default:
            cout << "Opcion invalida.\n";
    }

    return 0;
}

