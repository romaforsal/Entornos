#include "Boss.h"
#include <iostream>
#include <sstream>
#include <cstdlib>

Boss::Boss(std::string name, int hp, int attack_power, std::string ultimate_name)
    : Enemy(name, hp, attack_power), ultimate_name(ultimate_name) {
}

void Boss::ultimateAttack(Character& target) {
    int damage = attack_power * 2;

    target.setHp(target.getHP() - damage);

    std::cout << name << " usa " << ultimate_name << " causando "
        << damage << " puntos de daño!" << std::endl;
}

std::string Boss::getStatus() const {
    std::stringstream ss;
    ss << "JEFE FINAL: " << name << " - HP: " << hp << " - Poder de Ataque: " << attack_power;
    ss << " - Habilidad: " << ultimate_name;
    return ss.str();
}