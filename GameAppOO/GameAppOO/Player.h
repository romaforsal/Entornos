#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

class Player : public Character {
public:
    Player(std::string name, int hp, int attack_power);

    void attack(Character& target) override;
    void specialAttack(Character& target) override;
    std::string getStatus() const override;
};

#endif