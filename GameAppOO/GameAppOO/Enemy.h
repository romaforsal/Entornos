#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"

class Enemy : public Character {
public:
    Enemy(std::string name, int hp, int attack_power);

    void attack(Character& target) override;
    void specialAttack(Character& target) override;
    std::string getStatus() const override;
};

#endif