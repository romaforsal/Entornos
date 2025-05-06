#include <iostream>
using namespace std;
double a, b, c, X1, X2, discriminante;
int numSols;
void pedir() {
    
    cout << "aX² + bX + c\n";
    cout << "Di el valor a: ";
    do {
        cin >> a;
    } while (a == 0);
    
    
    cout << "Di el valor b: ";
    cin >> b;
    cout << "Di el valor c: ";
    cin >> c;
}
void discriminar() {
    
    discriminante = b * b - 4 * a * c;
    if (discriminante < 0) {
        numSols = 0;
    } else if (discriminante == 0) {
        numSols = 1;
    }
    else if (discriminante > 0) {
        numSols = 2;
    }
    X1 = (-b + sqrt(discriminante)) / (2 * a);
    X2 = (-b - sqrt(discriminante)) / (2 * a);
}
void mostrarRes() {
    if (numSols == 0) {
        cout << "No se puede resolver ya que el discriminante da negativo";
    }
    else if (numSols == 1) {
        cout << "Solo hay 1 solucion X = " << X1;

    }
    else if (numSols == 2) {
        cout << "Las soluciones son X1 = " << X1 << " X2 = " << X2;
    }
}
int main() {
    pedir();
    discriminar();
    mostrarRes();
    system("pause");
    return 0;
}