#include <iostream>
#include <cmath> // Para sqrt y pow

using namespace std;

int main() {
    double cateto1, cateto2, hipotenusa;

    cout << "Ingrese el primer cateto: ";
    cin >> cateto1;
    cout << "Ingrese el segundo cateto: ";
    cin >> cateto2;

    hipotenusa = sqrt(pow(cateto1, 2) + pow(cateto2, 2));

    cout << "La hipotenusa es: " << hipotenusa << endl;

    return 0;
}

