#ifndef BOSS_H
#define BOSS_H

#include "Enemy.h"
#include <string>

class Boss : public Enemy {
private:
    std::string ultimate_name;

public:
    Boss(std::string name, int hp, int attack_power, std::string ultimate_name);

    void ultimateAttack(Character& target);

    std::string getStatus() const override;
};

#endif