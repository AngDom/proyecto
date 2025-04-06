#include <iostream>
#include <cstdlib>   // Para rand() y srand()
#include <ctime>     // Para time()

using namespace std;

int main() {
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

    system("pause");
}

