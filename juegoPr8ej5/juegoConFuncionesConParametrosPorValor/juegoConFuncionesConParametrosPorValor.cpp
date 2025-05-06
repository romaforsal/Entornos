#include <iostream>
using namespace std;

int main() {
    int vidaJugador = 100;
    int vidaEnemigo = 100;
    int probabilidadAtk = 75;
    int gameover = 0;
    int defendiendo = 0;
    int ataqueCertero = 0;
    int defendiendoEnemigo = 0;
    int ataqueCerteroEnemigo = 0;
    int decision;

    while (gameover == 0) {
        representarStats(vidaJugador, vidaEnemigo);
        opcionJugador(decision, defendiendo, ataqueCertero, defendiendoEnemigo, ataqueCerteroEnemigo);
        opcionEnemigo(defendiendoEnemigo, ataqueCerteroEnemigo);
        gameover = comprobar(vidaJugador, vidaEnemigo, defendiendo, ataqueCertero, defendiendoEnemigo, ataqueCerteroEnemigo);
        reset(defendiendo, ataqueCertero, defendiendoEnemigo, ataqueCerteroEnemigo);
    }

}

static void reset(int defendiendo, int ataqueCertero, int defendiendoEnemigo, int ataqueCerteroEnemigo) {
    defendiendo = 0;
    ataqueCertero = 0;
    defendiendoEnemigo = 0;
    ataqueCerteroEnemigo = 0;
}

static void opcionJugador(int decision, int defendiendo, int ataqueCertero, int defendiendoEnemigo, int ataqueCerteroEnemigo) {
    cin >> decision;
    if (decision == 1) {
        double aleatorio = (double)rand() / RAND_MAX * 100;
        aleatorio = (int)aleatorio;
        if (aleatorio < 75) {
            ataqueCertero = 1;
        }
    }
    else if (decision == 2) {
        defendiendo = 1;
    }
    else {
        cout << "Opcion invalida" << endl;
    }
}

static void opcionEnemigo(int defendiendoEnemigo, int ataqueCerteroEnemigo) {
    int decisionEnemigo = rand() % 2 + 1;
    if (decisionEnemigo == 1) {
        double aleatorioEne = (double)rand() / RAND_MAX * 100;
        aleatorioEne = (int)aleatorioEne;
        if (aleatorioEne < 75) {
            ataqueCerteroEnemigo = 1;
        }
    }
    else if (decisionEnemigo == 2) {
        defendiendoEnemigo = 1;
    }
    else {
        cout << "Opcion invalida" << endl;
    }
}

static int comprobar(int vidaJugador, int vidaEnemigo, int defendiendo, int ataqueCertero, int defendiendoEnemigo, int ataqueCerteroEnemigo) {
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
    return 0;
}

static void representarStats(int vidaJugador, int vidaEnemigo) {
    cout << "Vida enemigo: " << vidaEnemigo << endl;
    cout << "Vida jugador: " << vidaJugador << "\n" << endl;
    cout << "Que quieres hacer?\n1.Atacar    2.Defender (50% red. daño)" << endl;
}