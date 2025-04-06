#include <iostream>
#include <math.h>

using namespace std;

int main(){
	int catop, catady, hipo;
	
	cout<<"Para obtener la hipotenusa, necesitamos el Cateto opuesto y el Cat adyacente."<<endl;
	cout<<"Ingrese el cateto opuesto: ";
	cin>>catop;
	
	cout<<"Ingrese el cateto adyacente: ";
	cin>>catady;
	
	hipo = sqrt(pow(catady,2)+pow(catop,2));
	cout<<"El resultado de la hipotenusa es = "<<hipo<<endl;
	
	system("pause");
}
