#include <iostream>
using namespace std;
double a, b, suma, resta, multiplicacion, division;
void pedirDatos() {
	cout << "Ingrese el primer numero: ";
	cin >> a;
	cout << "Ingrese el segundo numero: ";
	cin >> b;
}
void sumar() {
	suma = a + b;
}
void restar() {
	resta = a - b;
}
void multiplicar() {
	multiplicacion = a * b;
}
void dividir() {
	division = a / b;
}
void mostrarResultado() {
	cout << "La suma es: " << suma << endl;
}
int main()
{
	pedirDatos();
	sumar();
	mostrarResultado();
	system("pause");
	return 0;
}