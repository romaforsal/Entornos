#include "Character.h"
#include <iostream>
#include <sstream>

Character::Character(std::string name, int hp, int attack_power)
    : name(name), hp(hp), attack_power(attack_power) {
}

void Character::attack(Character& target) {
    int damage = attack_power;

    target.hp -= damage;
    if (target.hp < 0) target.hp = 0;

    std::cout << name << " ataca a " << target.getName()
        << " causando " << damage << " puntos de daño!" << std::endl;
}

void Character::specialAttack(Character& target) {
    int damage = attack_power * 1.5;

    target.hp -= damage;
    if (target.hp < 0) target.hp = 0;

    std::cout << name << " usa ataque especial contra " << target.getName()
        << " causando " << damage << " puntos de daño!" << std::endl;
}

std::string Character::getStatus() const {
    std::stringstream ss;
    ss << name << " - HP: " << hp << " - Poder de Ataque: " << attack_power;
    return ss.str();
}

std::string Character::getName() const {
    return name;
}

int Character::getHP() const {
    return hp;
}

int Character::getAttackPower() const {
    return attack_power;
}

void Character::setHp(int newHp) {
    hp = newHp;
    if (hp < 0) hp = 0;
}