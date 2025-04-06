#include <iostream>
using namespace std;

void convertirABinario(int n) {
    if (n > 1) {
        convertirABinario(n / 2);
    }
    cout << n % 2;
}

int main() {
    int numero;
    cout << "Ingrese un numero decimal: ";
    cin >> numero;
    cout << "El numero en binario es: ";
    convertirABinario(numero);
    cout << endl;
    return 0;
}

