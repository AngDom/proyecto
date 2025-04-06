#include <iostream>
using namespace std;

int main() {
    int n, suma = 0;

    // Solicitar al usuario que ingrese un número
    cout << "Ingrese un número entero positivo: ";
    cin >> n;

    // Verificar si el número ingresado es positivo
    if (n < 1) {
        cout << "Por favor ingrese un número mayor que 0." << endl;
        return 1; // Salir si el número es inválido
    }

    // Calcular la suma de los primeros 'n' números
    for (int i = 1; i <= n; i++) {
        suma += i;  // suma = suma + i;
    }

    // Imprimir el resultado
    cout << "La suma de los primeros " << n << " números es: " << suma << endl;

    return 0;
}
