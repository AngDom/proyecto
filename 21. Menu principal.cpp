#include <iostream>
#include <cmath> // Para sqrt() y pow()
#include <cstdlib>   // Para rand() y srand()
#include <ctime>     // Para time()
using namespace std;

int main() {
    int select;

    cout << "Ingrese la funcion que desea realizar: ";
    cin >> select;

    switch (select) {
        case 12: {
            int digito[20];
            int decimal, residuo, resultado, valor = 0;

            cout << "Ingrese el valor a convertir de decimal a hexadecimal: ";
            cin >> decimal;

            do {
                residuo = decimal % 16;
                resultado = decimal / 16;
                digito[valor] = residuo;
                decimal = resultado;
                valor++;
            } while (resultado > 15);

            digito[valor] = resultado;

            cout << "La conversion equivalente a hexadecimal es: ";

            for (int m = valor; m >= 0; m--) {
                if (digito[m] == 10) cout << "A";
                else if (digito[m] == 11) cout << "B";
                else if (digito[m] == 12) cout << "C";
                else if (digito[m] == 13) cout << "D";
                else if (digito[m] == 14) cout << "E";
                else if (digito[m] == 15) cout << "F";
                else cout << digito[m];
            }
            cout << endl;
            break;
        }

        case 16: {
            double catop, catady, hipo;

            cout << "Para obtener la hipotenusa, necesitamos el cateto opuesto y el cateto adyacente." << endl;
            cout << "Ingrese el cateto opuesto: ";
            cin >> catop;

            cout << "Ingrese el cateto adyacente: ";
            cin >> catady;

            hipo = sqrt(pow(catady, 2) + pow(catop, 2));
            cout << "El resultado de la hipotenusa es = " << hipo << endl;
            break;
        }
		
		case 20:{
			int numeroSecreto, intento, intentos = 0;

    // Inicializamos la semilla aleatoria
    srand(time(0));

    // Generar número aleatorio entre 1 y 100
    numeroSecreto = rand() % 10 + 1;

    cout << "Bienvenido al juego de adivinanzas!" << endl;
    cout << "Estoy pensando en un numero entre 1 y 10..." << endl;

    // Bucle hasta que el usuario adivine
    do {
        cout << "Introduce tu intento: ";
        cin >> intento;
        intentos++;

        if (intento < numeroSecreto) {
            cout << "El numero secreto es mayor. ??\n";
        } else if (intento > numeroSecreto) {
            cout << "El numero secreto es menor. ??\n";
        } else {
            cout << "Felicidades, Adivinaste el numero en " << intentos << " intento(s).\n";
        }

    } while (intento != numeroSecreto);

			break;
		}
        default:
            cout << "Opcion invalida." << endl;
    }

    return 0;
}

