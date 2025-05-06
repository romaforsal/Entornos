#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Boss.h"

using namespace std;

int main()
{
    // Inicializar generador de números aleatorios
    srand(static_cast<unsigned int>(time(nullptr)));

    // Imprimir título del juego
    cout << "============================" << endl;
    cout << "      RPG BATTLE GAME       " << endl;
    cout << "============================" << endl << endl;

    // Crear personajes para el juego
    Player hero("Aragorn", 150, 25);
    Enemy enemy("Goblin", 100, 15);
    Boss finalBoss("Sauron", 200, 30, "Llamarada Oscura");

    // Variables de estado del juego
    bool fightingBoss = false;
    bool gameOver = false;
    Character* currentEnemy = &enemy;

    // Variables para cooldowns
    int playerSpecialCooldown = 0;
    int enemySpecialCooldown = 0;
    int bossSpecialCooldown = 0;

    // Variable para el efecto de quemadura del jefe
    int burnEffect = 0;

    // Mostrar instrucciones iniciales
    cout << "Controles:" << endl;
    cout << "1 - Ataque normal" << endl;
    cout << "2 - Ataque especial (Cooldown: 3 turnos)" << endl;
    cout << "0 - Salir del juego" << endl << endl;

    // Bucle principal del juego
    while (!gameOver)
    {
        // Mostrar estado actual
        cout << "Estado del juego:" << endl;
        cout << hero.getStatus() << endl;
        cout << currentEnemy->getStatus() << endl;

        // Mostrar información de cooldown
        cout << "\nCooldown de ataque especial: ";
        if (playerSpecialCooldown > 0) {
            cout << playerSpecialCooldown << " turnos restantes" << endl;
        }
        else {
            cout << "¡Listo para usar!" << endl;
        }

        // Mostrar efecto de quemadura si está activo
        if (burnEffect > 0) {
            cout << "¡Estás sufriendo efectos de quemadura! (" << burnEffect << " turnos restantes)" << endl;
        }

        if (fightingBoss) {
            cout << "\n¡BATALLA FINAL CONTRA EL JEFE!" << endl;
        }

        // Solicitar acción al jugador
        int choice = 0;
        cout << "\nElige tu acción (1-Ataque normal, 2-Ataque especial, 0-Salir): ";
        cin >> choice;

        // Procesar la acción del jugador
        switch (choice) {
        case 0:
            cout << "Saliendo del juego..." << endl;
            return 0;

        case 1: // Ataque normal
            // Jugador ataca
            hero.attack(*currentEnemy);
            break;

        case 2: // Ataque especial
            if (playerSpecialCooldown > 0) {
                cout << "¡Tu ataque especial aún no está listo! Debes esperar "
                    << playerSpecialCooldown << " turnos más." << endl;
                continue; // Volver a pedir acción
            }

            // Jugador usa ataque especial
            hero.specialAttack(*currentEnemy);
            // Establecer cooldown
            playerSpecialCooldown = 3;
            break;

        default:
            cout << "Opción no válida. Intenta de nuevo." << endl;
            continue; // Volver a pedir acción
        }

        // Verificar si el enemigo fue derrotado
        if (currentEnemy->getHP() <= 0) {
            if (!fightingBoss) {
                // Pasar al jefe final
                cout << "\n¡Has derrotado al " << currentEnemy->getName() << "!" << endl;
                cout << "¡Prepárate para enfrentar al jefe final!" << endl;
                currentEnemy = &finalBoss;
                fightingBoss = true;

                // Recuperar algo de salud
                int healthBonus = 50;
                hero.setHp(hero.getHP() + healthBonus);
                cout << "Has recuperado " << healthBonus << " puntos de vida." << endl;

                // Reiniciar cooldowns para la batalla final
                playerSpecialCooldown = 0;
                enemySpecialCooldown = 0;
            }
            else {
                // Victoria final
                gameOver = true;
                continue;
            }
        }

        // Aplicar efecto de quemadura si está activo
        if (burnEffect > 0) {
            int burnDamage = 10;
            hero.setHp(hero.getHP() - burnDamage);
            cout << "¡La quemadura te causa " << burnDamage << " puntos de daño!" << endl;
            burnEffect--;

            // Verificar si el jugador fue derrotado por la quemadura
            if (hero.getHP() <= 0) {
                gameOver = true;
                continue;
            }
        }

        // Turno del enemigo
        if (fightingBoss) {
            // Lógica de ataque del jefe
            if (bossSpecialCooldown <= 0 && rand() % 3 == 0) {
                // El jefe usa su ataque especial ocasionalmente
                cout << finalBoss.getName() << " usa su habilidad especial: "
                    << "¡Llamarada Oscura!" << endl;

                int ultimateDamage = 25 + (rand() % 15); // 25-39 puntos de daño
                hero.setHp(hero.getHP() - ultimateDamage);
                cout << "¡Recibes " << ultimateDamage << " puntos de daño!" << endl;

                // Aplicar efecto de quemadura
                burnEffect = 3;
                cout << "¡La llamarada te ha quemado! Sufrirás daño durante "
                    << burnEffect << " turnos adicionales." << endl;

                // Establecer cooldown
                bossSpecialCooldown = 4;
            }
            else {
                // Ataque normal del jefe
                finalBoss.attack(hero);
            }
        }
        else {
            // Lógica de ataque del enemigo normal
            if (enemySpecialCooldown <= 0 && rand() % 4 == 0) {
                // El enemigo usa su ataque especial ocasionalmente
                enemy.specialAttack(hero);
                enemySpecialCooldown = 3;
            }
            else {
                // Ataque normal del enemigo
                currentEnemy->attack(hero);
            }
        }

        // Verificar si el jugador fue derrotado
        if (hero.getHP() <= 0) {
            gameOver = true;
            continue;
        }

        // Reducir cooldowns
        if (playerSpecialCooldown > 0) {
            playerSpecialCooldown--;
        }
        if (enemySpecialCooldown > 0) {
            enemySpecialCooldown--;
        }
        if (bossSpecialCooldown > 0) {
            bossSpecialCooldown--;
        }

        // Pequeña pausa entre turnos para mejor legibilidad
        cout << "\nPresiona Enter para continuar...";
        cin.ignore();
        cin.get();
        cout << "\n\n";
    }

    // Mostrar resultado final
    if (hero.getHP() > 0) {
        cout << "¡VICTORIA!" << endl << endl;
        cout << "Has derrotado a todos los enemigos y salvado el reino." << endl;
        cout << "Estadísticas finales:" << endl;
        cout << hero.getStatus() << endl;
    }
    else {
        cout << "GAME OVER" << endl << endl;
        cout << "Has sido derrotado por " << currentEnemy->getName() << endl;
    }

    return 0;
}