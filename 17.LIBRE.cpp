#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <ctime>

using namespace std;

const int ancho = 40;
const int alto = 20;
const int numObstaculos = 10;

int x, y;
int frutaX, frutaY;
int puntaje;
bool gameOver;
enum Direccion { STOP = 0, IZQ, DER, ARR, ABAJO };
Direccion dir;

vector<pair<int, int> > cola;
vector<pair<int, int> > obstaculos;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x; coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void ocultarCursor() {
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 100;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hCon, &cci);
}

bool esObstaculo(int x, int y) {
    for (int i = 0; i < obstaculos.size(); i++) {
        if (obstaculos[i].first == x && obstaculos[i].second == y)
            return true;
    }
    return false;
}

void dibujar() {
    system("cls");

    for (int i = 0; i < ancho + 2; i++) cout << "#";
    cout << "\n";

    for (int i = 0; i < alto; i++) {
        for (int j = 0; j < ancho; j++) {
            if (j == 0) cout << "#";

            if (i == y && j == x)
                cout << "O";
            else if (i == frutaY && j == frutaX)
                cout << "*";
            else if (esObstaculo(j, i))
                cout << "#"; // Obstáculo interno
            else {
                bool cuerpo = false;
                for (int k = 0; k < cola.size(); k++) {
                    if (cola[k].first == j && cola[k].second == i) {
                        cout << "o";
                        cuerpo = true;
                        break;
                    }
                }
                if (!cuerpo) cout << " ";
            }

            if (j == ancho - 1) cout << "#";
        }
        cout << "\n";
    }

    for (int i = 0; i < ancho + 2; i++) cout << "#";
    cout << "\n";

    cout << "Puntaje: " << puntaje << endl;
}

void input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a': dir = IZQ; break;
            case 'd': dir = DER; break;
            case 'w': dir = ARR; break;
            case 's': dir = ABAJO; break;
            case 'x': gameOver = true; break;
        }
    }
}

void logic() {
    int prevX = x, prevY = y;
    int prev2X, prev2Y;

    switch (dir) {
        case IZQ: x--; break;
        case DER: x++; break;
        case ARR: y--; break;
        case ABAJO: y++; break;
        default: break;
    }

    // Actualizar cuerpo
    for (int i = 0; i < cola.size(); i++) {
        prev2X = cola[i].first;
        prev2Y = cola[i].second;
        cola[i].first = prevX;
        cola[i].second = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    // Colisión con cuerpo
    for (int i = 0; i < cola.size(); i++) {
        if (cola[i].first == x && cola[i].second == y)
            gameOver = true;
    }

    // Colisión con bordes
    if (x >= ancho || x < 0 || y >= alto || y < 0)
        gameOver = true;

    // Colisión con obstáculo
    if (esObstaculo(x, y))
        gameOver = true;

    // Comer fruta
    if (x == frutaX && y == frutaY) {
        puntaje += 10;

        // Nueva fruta en lugar libre
        do {
            frutaX = rand() % ancho;
            frutaY = rand() % alto;
        } while (esObstaculo(frutaX, frutaY));

        cola.push_back(make_pair(0, 0));
    }
}

void generarObstaculos() {
    obstaculos.clear();
    for (int i = 0; i < numObstaculos; i++) {
        int ox, oy;
        do {
            ox = rand() % ancho;
            oy = rand() % alto;
        } while ((ox == x && oy == y) || esObstaculo(ox, oy)); // Evitar solapamientos
        obstaculos.push_back(make_pair(ox, oy));
    }
}

void setup() {
    srand(time(0));
    gameOver = false;
    dir = STOP;
    x = ancho / 2;
    y = alto / 2;
    frutaX = rand() % ancho;
    frutaY = rand() % alto;
    puntaje = 0;
    cola.clear();
    generarObstaculos();
    ocultarCursor();
}

int main() {
    setup();

    while (!gameOver) {
        dibujar();
        input();
        logic();
        Sleep(100);
    }

    cout << "\nFin del juego. Tu puntaje fue: " << puntaje << "\n";
    system("pause");
    return 0;
}

