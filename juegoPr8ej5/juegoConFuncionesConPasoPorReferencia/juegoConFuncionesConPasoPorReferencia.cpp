#include <iostream>
using namespace std;

void representarStats(int vidaJugador, int vidaEnemigo);
void opcionJugador(int& vidaJugador, int& defendiendo, int& ataqueCertero);
void opcionEnemigo(int& vidaEnemigo, int& defendiendoEnemigo, int& ataqueCerteroEnemigo);
int comprobar(int& vidaJugador, int& vidaEnemigo, int defendiendo, int ataqueCertero, int defendiendoEnemigo, int ataqueCerteroEnemigo);
void reset(int& defendiendo, int& ataqueCertero, int& defendiendoEnemigo, int& ataqueCerteroEnemigo);

int main() {
    int vidaJugador = 100;
    int vidaEnemigo = 100;
    int gameover = 0;

    while (gameover == 0) {
        representarStats(vidaJugador, vidaEnemigo);
        int defendiendo = 0, ataqueCertero = 0;
        opcionJugador(vidaJugador, defendiendo, ataqueCertero);

        int defendiendoEnemigo = 0, ataqueCerteroEnemigo = 0;
        opcionEnemigo(vidaEnemigo, defendiendoEnemigo, ataqueCerteroEnemigo);

        gameover = comprobar(vidaJugador, vidaEnemigo, defendiendo, ataqueCertero, defendiendoEnemigo, ataqueCerteroEnemigo);

        reset(defendiendo, ataqueCertero, defendiendoEnemigo, ataqueCerteroEnemigo);
    }

    return 0;
}

void representarStats(int vidaJugador, int vidaEnemigo) {
    cout << "Vida enemigo: " << vidaEnemigo << endl;
    cout << "Vida jugador: " << vidaJugador << "\n" << endl;
    cout << "¿Qué quieres hacer?\n1. Atacar    2. Defender (50% reducción de daño)" << endl;
}

void opcionJugador(int& vidaJugador, int& defendiendo, int& ataqueCertero) {
    int decision;
    while (true) {  // Asegurarse de que se ingresa una opción válida
        cin >> decision;
        if (decision == 1) {
            double aleatorio = static_cast<double>(rand()) / RAND_MAX * 100;
            if (aleatorio < 75) {
                ataqueCertero = 1;
            }
            break;  // Salir del ciclo si la decisión es válida
        }
        else if (decision == 2) {
            defendiendo = 1;
            break;
        }
        else {
            cout << "Opción inválida, elige 1 para Atacar o 2 para Defender: ";
        }
    }
}

void opcionEnemigo(int& vidaEnemigo, int& defendiendoEnemigo, int& ataqueCerteroEnemigo) {
    int decisionEnemigo = rand() % 2 + 1;
    if (decisionEnemigo == 1) {
        double aleatorioEne = static_cast<double>(rand()) / RAND_MAX * 100;
        if (aleatorioEne < 75) {
            ataqueCerteroEnemigo = 1;
        }
    }
    else if (decisionEnemigo == 2) {
        defendiendoEnemigo = 1;
    }
}

int comprobar(int& vidaJugador, int& vidaEnemigo, int defendiendo, int ataqueCertero, int defendiendoEnemigo, int ataqueCerteroEnemigo) {
    if (ataqueCertero == 1) {
        if (defendiendoEnemigo == 1) {
            vidaEnemigo -= 5;
        }
        else {
            vidaEnemigo -= 10;
        }
    }

    if (ataqueCerteroEnemigo == 1) {
        if (defendiendo == 1) {
            vidaJugador -= 5;
        }
        else {
            vidaJugador -= 10;
        }
    }

    if (vidaJugador <= 0) {
        cout << "Has muerto" << endl;
        return 1;
    }

    if (vidaEnemigo <= 0) {
        cout << "Has ganado!" << endl;
        return 1;
    }

    return 0;
}

void reset(int& defendiendo, int& ataqueCertero, int& defendiendoEnemigo, int& ataqueCerteroEnemigo) {
    defendiendo = 0;
    ataqueCertero = 0;
    defendiendoEnemigo = 0;
    ataqueCerteroEnemigo = 0;
}
