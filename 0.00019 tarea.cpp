#include <iostream>
using namespace std;

int main() {
    int n, suma = 0;

    // Solicitar al usuario que ingrese un n�mero
    cout << "Ingrese un n�mero entero positivo: ";
    cin >> n;

    // Verificar si el n�mero ingresado es positivo
    if (n < 1) {
        cout << "Por favor ingrese un n�mero mayor que 0." << endl;
        return 1; // Salir si el n�mero es inv�lido
    }

    // Calcular la suma de los primeros 'n' n�meros
    for (int i = 1; i <= n; i++) {
        suma += i;  // suma = suma + i;
    }

    // Imprimir el resultado
    cout << "La suma de los primeros " << n << " n�meros es: " << suma << endl;

    return 0;
}
