#include <iostream>
#include <string>
#include <sstream>
using namespace std;

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

// Programa principal
int main() {
    double numero;

    cout << "Ingrese un numero decimal: ";
    cin >> numero;

    cout << "\nEn letras: " << numeroATexto(numero) << endl;

    return 0;
}


