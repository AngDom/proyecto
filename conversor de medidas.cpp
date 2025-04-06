#include <iostream>
using namespace std;

int main() {
    int opcion;
    double valor;

    
    cout << "Seleccione una opcion de conversion:"<< endl;
    cout << "1. Kilometros a Millas"<< endl;
    cout << "2. Metros a Pulgadas"<< endl;
    cout << "3. Libras a Kilos"<< endl;
    cout << "4. Kilos a Libras"<< endl;
    cout << "5. Millas a Kilometros"<< endl;
    cout << "6. Pulgadas a Metros"<< endl;
    cout << "Ingrese el numero de la opcion que desea: ";
    cin >> opcion;

    
    cout << "Ingrese el valor a convertir: ";
    cin >> valor;

    
    switch(opcion) {
        case 1: 
            cout <<valor<< " kilometros son "<< valor * 0.621371<< " millas."<< endl;
            break;
        case 2: 
            cout <<valor<< " metros son "<< valor * 39.3701<< " pulgadas."<< endl;
            break;
        case 3: 
            cout <<valor<< " libras son "<< valor * 0.453592<< " kilos."<< endl;
            break;
        case 4: 
            cout <<valor<< " kilos son "<< valor * 2.20462<< " libras."<< endl;
            break;
        case 5: 
            cout <<valor<< " millas son "<< valor / 0.621371<< " kilometros."<< endl;
            break;
        case 6: 
            cout <<valor<< " pulgadas son "<< valor / 39.3701<< " metros."<< endl;
            break;
        default:
            cout <<"Opcion no valida."<< endl;
    }

    system("pause");
}
