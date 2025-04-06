#include <iostream>
#include <cmath> // Para sqrt() y pow()
#include <cstdlib>   // Para rand() y srand()
#include <ctime>     // Para time()
#include <string>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <vector>

using namespace std;
//Funcion de programa 5
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
//Funcion de programa 4
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

//Funcion de programa 6
// Función para convertir la parte entera a texto
string convertirUnidades(int numero) {
    string unidades[] = {"", "uno", "dos", "tres", "cuatro", "cinco",
                         "seis", "siete", "ocho", "nueve"};
    return unidades[numero];
}

string convertirDecenas(int numero) {
    string especiales[] = {"diez", "once", "doce", "trece", "catorce", "quince",
                           "dieciséis", "diecisiete", "dieciocho", "diecinueve"};
    string decenas[] = {"", "", "veinte", "treinta", "cuarenta", "cincuenta",
                        "sesenta", "setenta", "ochenta", "noventa"};

    if (numero < 10)
        return convertirUnidades(numero);
    else if (numero >= 10 && numero < 20)
        return especiales[numero - 10];
    else {
        int dec = numero / 10;
        int uni = numero % 10;
        if (uni == 0)
            return decenas[dec];
        else
            return decenas[dec] + " y " + convertirUnidades(uni);
    }
}

string convertirCentenas(int numero) {
    string centenas[] = {"", "ciento", "doscientos", "trescientos", "cuatrocientos",
                         "quinientos", "seiscientos", "setecientos", "ochocientos", "novecientos"};
    if (numero == 100)
        return "cien";

    int cent = numero / 100;
    int resto = numero % 100;

    return centenas[cent] + (resto > 0 ? " " + convertirDecenas(resto) : "");
}
//Funcion del programa 10 
void imprimirEspacios(int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        cout << " ";
    }
}

int contarDigitos(int numero) {
    int digitos = 0;
    do {
        numero /= 10;
        digitos++;
    } while (numero > 0);
    return digitos;
 
	}   
	//Funcion programa 11
	void convertirABinario(int n) {
    if (n > 1) {
        convertirABinario(n / 2);
    }
    cout << n % 2;
}
//Funcion del programa 15
// Estados del cajero
enum Estado {
    INICIO,
    MENU,
    CONSULTAR_SALDO,
    RETIRAR_DINERO,
    SALIR
	};
	
//Funcion del programa 17
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
string convertirMiles(int numero) {
    if (numero < 1000)
        return convertirCentenas(numero);

    int miles = numero / 1000;
    int resto = numero % 1000;

    string milesTexto = (miles == 1) ? "mil" : convertirCentenas(miles) + " mil";
    if (resto > 0)
        return milesTexto + " " + convertirCentenas(resto);
    else
        return milesTexto;
}

string numeroATexto(double numero) {
    int parteEntera = static_cast<int>(numero);
    int parteDecimal = static_cast<int>((numero - parteEntera) * 100 + 0.5);  // redondeo

    string texto = convertirMiles(parteEntera);

    if (parteDecimal > 0) {
        texto += " punto";
        if (parteDecimal < 10) {
            texto += " " + convertirUnidades(parteDecimal);
        } else {
            texto += " " + convertirDecenas(parteDecimal);
        }
    }

    return texto;
}

//Funcion de programa 13.
void cuadrado(int lado) {
    for (int i = 0; i < lado; i++) {
        for (int j = 0; j < lado; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

void triangulo(int altura) {
    for (int i = 1; i <= altura; i++) {
        for (int j = 0; j < i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

void rectangulo(int ancho, int alto) {
    for (int i = 0; i < alto; i++) {
        for (int j = 0; j < ancho; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}


int main() {
    int select;
cout << "===== MENU PRINCIPAL =====" << endl;
    cout << "1. Suma, Resta, Multiplicacion y Division de dos numeros" << endl;
    cout << "2. Determinar si un numero es par o impar" << endl;
    cout << "3. Conversion de kilometros a millas, metros a pulgadas, libras a kilos y viceversa" << endl;
    cout << "4. Determinar si una palabra o numero es palindromo" << endl;
    cout << "5. Conversion de numeros arabigos a romanos (minimo 1000)" << endl;
    cout << "6. Conversion de numeros enteros a letras" << endl;
    cout << "7. Conversion de numeros con decimal a letras" << endl;
    cout << "8. Una tabla de multiplicar" << endl;
    cout << "9. Todas las tablas de multiplicar del 1 al 10" << endl;
    cout << "10. Multiplicacion manual grafica" << endl;
    cout << "11. Conversion de numeros decimales a binario" << endl;
    cout << "12. Conversion de numeros decimales a hexadecimales" << endl;
    cout << "13. Crear Figuras Geometricas Basicas" << endl;
    cout << "14. Mover un punto en toda la pantalla" << endl;
    cout << "15. Simulacion de un Cajero (Automata)" << endl;
    cout << "16. Calcular la hipotenusa" << endl;
    cout << "17. Libre (programa personalizado 1)" << endl;
    cout << "18. Libre (programa personalizado 2)" << endl;
    cout << "19. Libre (programa personalizado 3)" << endl;
    cout << "20. Libre (programa personalizado 4)" << endl;
    cout << "0. Salir" << endl;
    cout << "==========================" << endl;
    cout << "Seleccione una opcion del 1 al 20 o 0 para salir." << endl;
    cout << "Ingrese la funcion que desea realizar: ";
    cin >> select;
do {
 
    
    switch (select) {
    	case 1: {
    		int n1,n2,suma=0, resta=0, multiplicacion=0, division=0;
 			cout<<"Inserte un digito:"; 
 			cin>>n1;
			cout<<"Inserte el siguiente  digito:"; 
 			cin>>n2;
 
			 suma=n1+n2;
			 resta=n1-n2;
			 multiplicacion=n1*n2;
			 division=n1/n2;
 
			 cout<<"\n El resultado de la suma es:"<<suma<<endl; 
			 cout<<"\n El resultado de la resta es:"<<resta<<endl;
			 cout<<"\n El resultado de la multiplicacion  es:"<<multiplicacion<<endl;  
			 cout<<"\n El resultado de la divion es:"<<division<<endl; 
	
			break;
		}
		
		case 2: {
    int numero;
    
    cout << "Ingrese un numero arabigo (del 1 al 1000): ";
    cin >> numero;
    
    if (numero >= 1 && numero <= 1000) {
        string romano = convertirARomanos(numero);
        cout << "El numero " << numero << " en numeros romanos es: " << romano << endl;
    } else {
        cout << "El numero debe estar entre 1 y 1000." << endl;
    }

			break;
	
	}
		case 3: {
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
			break;
		}
		
		case 4: {
			int numero;
					 
			 cout<<"Ingrese un numero:";
			 cin>>numero;
			 if(numero==0){
			 cout<<"El numero es 0:"<<endl;
			 }else if(numero%2==0){
			 cout<<"El numero es par"<<endl;	
			 }else{
			 cout<<"El numero es impar"<<endl;
			 }
			break;
		}
		
		case 5: {
			string entrada;
		    cout<<"Ingrese una palabra o un numero: ";
		    cin>>entrada;
		
		    
		    if (esPalindromo(entrada)) {
		    cout<< "Lo ingresado es un palindromo."<<endl;
		    } else {
		    cout<< "La ingresado no es un palindromo."<<endl;
		    }
			break;
		}
		
		case 6: {
			 double numero;

    cout << "Ingrese un numero decimal: ";
    cin >> numero;

    cout << "\nEn letras: " << numeroATexto(numero) << endl;

			break;
		}
		
		case 7: {
				    setlocale(LC_ALL, "");

    int numero;

    while (true) {
        cout << "\nDigita un número en el rango de 0 a 9999 (o -1 para salir): ";
        cin >> numero;

        if (numero == -1) {
            cout << "Programa terminado.\n";
            break;
        }

        if (numero >= 0 && numero <= 9999) {
            int unidad = numero % 10;
            numero /= 10;
            int decena = numero % 10;
            numero /= 10;
            int centena = numero % 10;
            numero /= 10;
            int unimil = numero % 10;

            // UNIDADES DE MIL
            switch (unimil) {
                case 0: cout << ""; break;
                case 1: cout << "mil "; break;
                case 2: cout << "dos mil "; break;
                case 3: cout << "tres mil "; break;
                case 4: cout << "cuatro mil "; break;
                case 5: cout << "cinco mil "; break;
                case 6: cout << "seis mil "; break;
                case 7: cout << "siete mil "; break;
                case 8: cout << "ocho mil "; break;
                case 9: cout << "nueve mil "; break;
            }

            // CENTENAS
            switch (centena) {
                case 0: break;
                case 1:
                    if (decena == 0 && unidad == 0) {
                        cout << "cien ";
                    } else {
                        cout << "ciento ";
                    }
                    break;
                case 2: cout << "doscientos "; break;
                case 3: cout << "trescientos "; break;
                case 4: cout << "cuatrocientos "; break;
                case 5: cout << "quinientos "; break;
                case 6: cout << "seiscientos "; break;
                case 7: cout << "setecientos "; break;
                case 8: cout << "ochocientos "; break;
                case 9: cout << "novecientos "; break;
            }

            // DECENAS Y UNIDADES
            if (decena == 1) {
                switch (unidad) {
                    case 0: cout << "diez"; break;
                    case 1: cout << "once"; break;
                    case 2: cout << "doce"; break;
                    case 3: cout << "trece"; break;
                    case 4: cout << "catorce"; break;
                    case 5: cout << "quince"; break;
                    case 6: cout << "dieciséis"; break;
                    case 7: cout << "diecisiete"; break;
                    case 8: cout << "dieciocho"; break;
                    case 9: cout << "diecinueve"; break;
                }
            } else if (decena == 2) {
                switch (unidad) {
                    case 0: cout << "veinte"; break;
                    case 1: cout << "veintiuno"; break;
                    case 2: cout << "veintidós"; break;
                    case 3: cout << "veintitrés"; break;
                    case 4: cout << "veinticuatro"; break;
                    case 5: cout << "veinticinco"; break;
                    case 6: cout << "veintiséis"; break;
                    case 7: cout << "veintisiete"; break;
                    case 8: cout << "veintiocho"; break;
                    case 9: cout << "veintinueve"; break;
                }
            } else {
                switch (decena) {
                    case 3: cout << "treinta"; break;
                    case 4: cout << "cuarenta"; break;
                    case 5: cout << "cincuenta"; break;
                    case 6: cout << "sesenta"; break;
                    case 7: cout << "setenta"; break;
                    case 8: cout << "ochenta"; break;
                    case 9: cout << "noventa"; break;
                }

                if (decena >= 3 && unidad != 0) {
                    cout << " y ";
                }

                if (decena != 1 && decena != 2) {
                    switch (unidad) {
                        case 1: cout << "uno"; break;
                        case 2: cout << "dos"; break;
                        case 3: cout << "tres"; break;
                        case 4: cout << "cuatro"; break;
                        case 5: cout << "cinco"; break;
                        case 6: cout << "seis"; break;
                        case 7: cout << "siete"; break;
                        case 8: cout << "ocho"; break;
                        case 9: cout << "nueve"; break;
                        case 0:
                            if (unimil == 0 && centena == 0 && decena == 0)
                                cout << "cero";
                            break;
                    }
                }
            }

        } else {
            cout << "ERROR: Debes ingresar un valor entre 0 y 9999.";
        }

        cout << "\n";
    }

			break;
		}
		
		case 8: {
			 int numero;
    char respuesta;

    do {
        cout << "\nDigite un numero: ";
        cin >> numero;

        cout << "\nTabla de multiplicar del " << numero << ":\n";
        for (int i = 1; i <= 20; i++) {
            cout << numero << " * " << i << " = " << numero * i << endl;
        }

        cout << "\n¿Desea multiplicar otro numero? (s/n): ";
        cin >> respuesta;

    } while (respuesta == 's' || respuesta == 'S');

    cout << "\nPrograma finalizado.\n";
			break;
		}
		
		case 9: {
			  for (int i = 1; i <= 10; i++) {
        cout << "Tabla del " << i << ":" << endl;
        for (int j = 1; j <= 10; j++) {
            cout << i << " x " << j << " = " << i * j << endl;
        }
        cout << endl;
    }
			break;
		}
		
		case 10: {
			int a = 45;
    int b = 32;

    int unidad = b % 10;
    int decena = b / 10;

    int parcial1 = a * unidad;
    int parcial2 = a * decena;
    int total = parcial1 + parcial2 * 10;

    // Contar la cantidad de dígitos del total para saber cuánto alinear
    int ancho = contarDigitos(total);

    imprimirEspacios(ancho - contarDigitos(a));
    cout << a << endl;

    cout << "x ";
    imprimirEspacios(ancho - contarDigitos(b) - 2); // -2 por "x "
    cout << b << endl;

    for (int i = 0; i < ancho; i++) cout << "-";
    cout << endl;

    imprimirEspacios(ancho - contarDigitos(parcial1));
    cout << parcial1 << endl;

    imprimirEspacios(ancho - contarDigitos(parcial2) - 1); // -1 para simular el desplazamiento
    cout << parcial2 << "0" << endl; // agregar el 0 a la derecha

    for (int i = 0; i < ancho; i++) cout << "-";
    cout << endl;

    cout << total << endl;

			break;
		}
		
		case 11: {
			int numero;
    cout << "Ingrese un numero decimal: ";
    cin >> numero;
    cout << "El numero en binario es: ";
    convertirABinario(numero);
    cout << endl;
			break;
		}
		
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
			case 13: {
				int opcion;
    cout << "Seleccione una figura:\n";
    cout << "1. Cuadrado\n2. Triangulo\n3. Rectangulo\n";
    cin >> opcion;

    switch (opcion) {
        case 1:
            int lado;
            cout << "Ingrese el tamaño del lado: ";
            cin >> lado;
            cuadrado(lado);
            break;
        case 2:
            int altura;
            cout << "Ingrese la altura del triangulo: ";
            cin >> altura;
            triangulo(altura);
            break;
        case 3:
            int ancho, alto;
            cout << "Ingrese el ancho: ";
            cin >> ancho;
            cout << "Ingrese el alto: ";
            cin >> alto;
            rectangulo(ancho, alto);
            break;
        default:
            cout << "Opcion invalida.\n";
    }

				break;
			}
			
			case 14: {
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
				break;
			}
			
			case 15: {
				Estado estadoActual = INICIO;
    string usuario, pin;
    double saldo = 8000.0; // Saldo inicial
    bool sesionIniciada = false;

    while (estadoActual != SALIR) {
        switch (estadoActual) {
            case INICIO:
                cout << "Bienvenido al Cajero Automatico\n";
                cout << "Ingrese su usuario: ";
                cin >> usuario;
                cout << "Ingrese su PIN: ";
                cin >> pin;

                // Validamos usuario y pin (simulado)
                if (usuario == "Audias" && pin == "1234") {
                    sesionIniciada = true;
                    estadoActual = MENU;
                } else {
                    cout << "Usuario o PIN incorrecto. Intente de nuevo.\n\n";
                }
                break;

            case MENU:
                int opcion;
                cout << "\n--- Menu Principal ---\n";
                cout << "1. Consultar Saldo\n";
                cout << "2. Retirar Dinero\n";
                cout << "3. Salir\n";
                cout << "Seleccione una opcion: ";
                cin >> opcion;

                switch (opcion) {
                    case 1:
                        estadoActual = CONSULTAR_SALDO;
                        break;
                    case 2:
                        estadoActual = RETIRAR_DINERO;
                        break;
                    case 3:
                        estadoActual = SALIR;
                        break;
                    default:
                        cout << "Opcion invalida. Intente de nuevo.\n";
                }
                break;

            case CONSULTAR_SALDO:
                cout << "\nSu saldo actual es: Q" << saldo << "\n\n";
                estadoActual = MENU;
                break;

            case RETIRAR_DINERO:
                double retiro;
                cout << "\nIngrese la cantidad a retirar: Q";
                cin >> retiro;
                if (retiro <= saldo && retiro > 0) {
                    saldo -= retiro;
                    cout << "Retiro exitoso. Saldo restante: Q" << saldo << "\n\n";
                } else {
                    cout << "Fondos insuficientes o cantidad invalida.\n\n";
                }
                estadoActual = MENU;
                break;

            case SALIR:
                cout << "Gracias por usar el cajero. ¡Hasta pronto!\n";
                break;
        }
    }

    return 0;
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
		
		case 17: {
			setup();

    while (!gameOver) {
        dibujar();
        input();
        logic();
        Sleep(100);
    }

    cout << "\nFin del juego. Tu puntaje fue: " << puntaje << "\n";
    system("pause");
			break;
		}
		
		case 18: {
			double ingresos, egresos, deudas, meta, ahorroMensual;
    string objetivo;

    cout << "Ingrese su ingreso mensual: ";
    cin >> ingresos;
    cout << "Ingrese sus egresos mensuales: ";
    cin >> egresos;
    cout << "Ingrese sus deudas mensuales: ";
    cin >> deudas;
    cout << "Ingrese el monto que desea ahorrar (ej. carro, casa): ";
    cin >> meta;
    cin.ignore(); 
    cout << "Escriba el motivo del ahorro: ";
    getline(cin, objetivo);

    ahorroMensual = ingresos - egresos - deudas;

    if (ahorroMensual <= 0) {
        cout << "No es posible ahorrar con los ingresos actuales." << endl;
    } else {
        int meses = meta / ahorroMensual;
        cout << "Puede ahorrar " << ahorroMensual << " quetzales por mes." << endl;
        cout << "Tardara aproximadamente " << meses << " meses en ahorrar para su " << objetivo << "." << endl;
    }

			break;
		}
		
		case 19: {
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
		
	case 0: {
		cout<<"Saliendo del programa..."<<endl;
		break;
		 default:
            cout << "Opcion invalida, intente de nuevo."<<endl;
	}
       
    }
 
}while (select != 0);
system("pause");
    return 0;
}

