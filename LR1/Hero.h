//
// Created by Павел Жуков on 07/10/2021.
//

#ifndef LR1_HERO_H
#define LR1_HERO_H

#ifndef LR1_BASE_H
#include "Base.h"
#endif

#include <iostream>

class Hero : public Base{
    std::string name, weaponType;
    std::string abilities;
public:
    void printParams() override;
    Hero();
    Hero(std::string& newName, std::string& newWeaponType, std::string& newAbilities);
    Hero(const Hero& character);
    ~Hero();
    const std::string &getName() const;
    void setName(const std::string &name);
    const std::string &getWeaponType() const;
    void setWeaponType(const std::string &weaponType);
    const std::string &getAbilities() const;
    void addAbility(const std::string& Ability);
    std::string getInfoForFile() override;

    const std::string getNormalName() const;
    friend std::istream& operator>> (std::istream& in, Hero* a);
};


#endif //LR1_HERO_H
