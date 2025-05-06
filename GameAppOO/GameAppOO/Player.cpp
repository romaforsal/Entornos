#include "Player.h"
#include <iostream>
#include <sstream>
#include <cstdlib>

Player::Player(std::string name, int hp, int attack_power)
    : Character(name, hp, attack_power) {
}

void Player::attack(Character& target) {
    int critChance = rand() % 100;
    int damage = attack_power;

    if (critChance < 20) {
        damage = static_cast<int>(attack_power * 1.5);
        std::cout << "¡Golpe crítico! ";
    }

    target.setHp(target.getHP() - damage);

    std::cout << name << " ataca a " << target.getName()
        << " causando " << damage << " puntos de daño!" << std::endl;
}

void Player::specialAttack(Character& target) {
    int damage = attack_power * 2;

    target.setHp(target.getHP() - damage);

    std::cout << name << " usa Ataque Heroico contra " << target.getName()
        << " causando " << damage << " puntos de daño!" << std::endl;
}

std::string Player::getStatus() const {
    std::stringstream ss;
    ss << "HÉROE: " << name << " - HP: " << hp << " - Poder de Ataque: " << attack_power;
    return ss.str();
}