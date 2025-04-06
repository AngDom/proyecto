#include <iostream>
#include <windows.h> // Para GetCursorPos y system("cls")

using namespace std;

int main() {
    POINT cursorPos; // Estructura para guardar posición del mouse

    while (true) {
        if (GetCursorPos(&cursorPos)) {
            int x = cursorPos.x / 10; // Escalar la posición para que quepa en consola
            int y = cursorPos.y / 20; // Escalar altura

            system("cls"); // Limpiar pantalla

            // Imprimir el punto en la posición del mouse
            for (int i = 0; i < y; i++) cout << endl;
            for (int i = 0; i < x; i++) cout << " ";
            cout << "*";

            Sleep(30); // 
        }
    }

    return 0;
}

