#include <iostream>
#include <string>
using namespace std;

string convertirARomanos(int num) {
    string romano = "";
    
    string valores[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    int numeros[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    
    for (int i = 0; i < 13; i++) {
    while (num >= numeros[i]) {
    romano += valores[i];
    num -= numeros[i];
        }
    }
    
    return romano;
}

int main() {
    int numero;
    
    cout << "Ingrese un numero arabigo (del 1 al 1000): ";
    cin >> numero;
    
    if (numero >= 1 && numero <= 1000) {
        string romano = convertirARomanos(numero);
        cout << "El numero " << numero << " en numeros romanos es: " << romano << endl;
    } else {
        cout << "El numero debe estar entre 1 y 1000." << endl;
    }

    system("pause");
}
