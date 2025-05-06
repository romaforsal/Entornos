#include "Enemy.h"
#include <iostream>
#include <sstream>
#include <cstdlib>

Enemy::Enemy(std::string name, int hp, int attack_power)
    : Character(name, hp, attack_power) {
}

void Enemy::attack(Character& target) {
    int damage = attack_power - 2 + (rand() % 5);

    target.setHp(target.getHP() - damage);

    std::cout << name << " ataca a " << target.getName()
        << " causando " << damage << " puntos de daño!" << std::endl;
}

void Enemy::specialAttack(Character& target) {
    int damage = static_cast<int>(attack_power * 1.8);

    target.setHp(target.getHP() - damage);

    std::cout << name << " usa Ataque Despiadado contra " << target.getName()
        << " causando " << damage << " puntos de daño!" << std::endl;
}

std::string Enemy::getStatus() const {
    std::stringstream ss;
    ss << "ENEMIGO: " << name << " - HP: " << hp << " - Poder de Ataque: " << attack_power;
    return ss.str();
}