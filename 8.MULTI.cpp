#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
    int numero;
    char respuesta;

    do {
        cout << "\nDigite un numero: ";
        cin >> numero;

        cout << "\nTabla de multiplicar del " << numero << ":\n";
        for (int i = 1; i <= 20; i++) {
            cout << numero << " * " << i << " = " << numero * i << endl;
        }

        cout << "\n¿Desea multiplicar otro numero? (s/n): ";
        cin >> respuesta;

    } while (respuesta == 's' || respuesta == 'S');

    cout << "\nPrograma finalizado.\n";
    system("pause");
    return 0;
}

