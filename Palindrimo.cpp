#include <iostream>
#include <string>
using namespace std;

bool esPalindromo(string str) {
    int inicio = 0;
    int fin = str.length() - 1;

    while (inicio < fin) {
    if (str[inicio] != str[fin]) {
    return false;
    }
    inicio++;
    fin--;
    }
    return true;
}

int main() {
    string entrada;
    cout<<"Ingrese una palabra o un numero: ";
    cin>>entrada;

    
    if (esPalindromo(entrada)) {
    cout<< "Lo ingresado es un palindromo."<<endl;
    } else {
    cout<< "La ingresado no es un palindromo."<<endl;
    }

    system("pause");
}
