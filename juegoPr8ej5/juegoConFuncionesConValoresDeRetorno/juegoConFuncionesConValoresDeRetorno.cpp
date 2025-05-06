#include <iostream>
using namespace std;

void representarStats(int vidaJugador, int vidaEnemigo);
int opcionJugador(int defendiendo, int ataqueCertero);
int opcionEnemigo(int defendiendoEnemigo, int ataqueCerteroEnemigo);
int comprobar(int vidaJugador, int vidaEnemigo, int defendiendo, int ataqueCertero, int defendiendoEnemigo, int ataqueCerteroEnemigo);
void reset(int defendiendo, int ataqueCertero, int defendiendoEnemigo, int ataqueCerteroEnemigo);

int main() {
    int vidaJugador = 100;
    int vidaEnemigo = 100;
    int gameover = 0;

    while (gameover == 0) {
        representarStats(vidaJugador, vidaEnemigo);

        int defendiendo = 0, ataqueCertero = 0;
        opcionJugador(defendiendo, ataqueCertero);

        int defendiendoEnemigo = 0, ataqueCerteroEnemigo = 0;
        opcionEnemigo(defendiendoEnemigo, ataqueCerteroEnemigo);

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

int opcionJugador(int defendiendo, int ataqueCertero) {
    int decision;
    cin >> decision;
    if (decision == 1) {
        double aleatorio = static_cast<double>(rand()) / RAND_MAX * 100;
        if (aleatorio < 75) {
            ataqueCertero = 1;
        }
    }
    else if (decision == 2) {
        defendiendo = 1;
    }
    else {
        cout << "Opción inválida" << endl;
    }
    return decision;
}

int opcionEnemigo(int defendiendoEnemigo, int ataqueCerteroEnemigo) {
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
    else {
        cout << "Opción inválida" << endl;
    }
    return decisionEnemigo;
}

// Función para comprobar el estado después de cada acción
int comprobar(int vidaJugador, int vidaEnemigo, int defendiendo, int ataqueCertero, int defendiendoEnemigo, int ataqueCerteroEnemigo) {
    if (ataqueCertero == 1) {
        if (defendiendoEnemigo == 1) {
            vidaEnemigo -= 5;
        }
        else if (defendiendoEnemigo == 0) {
            vidaEnemigo -= 10;
        }
    }

    if (ataqueCerteroEnemigo == 1) {
        if (defendiendo == 1) {
            vidaJugador -= 5;
        }
        else if (defendiendo == 0) {
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

    return 0; // El juego continúa
}

// Función para reiniciar las variables del turno
void reset(int defendiendo, int ataqueCertero, int defendiendoEnemigo, int ataqueCerteroEnemigo) {
    defendiendo = 0;
    ataqueCertero = 0;
    defendiendoEnemigo = 0;
    ataqueCerteroEnemigo = 0;
}
