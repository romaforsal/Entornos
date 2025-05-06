#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character {
protected:
    std::string name;
    int hp;
    int attack_power;

public:
    Character(std::string name, int hp, int attack_power);

    virtual void attack(Character& target);
    virtual void specialAttack(Character& target);
    virtual std::string getStatus() const;

    std::string getName() const;
    int getHP() const;
    int getAttackPower() const;
    void setHp(int newHp);
};

#endif