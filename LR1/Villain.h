//
// Created by Павел Жуков on 17/10/2021.
//

#ifndef LR1_VILLAIN_H
#define LR1_VILLAIN_H


#ifndef LR1_BASE_H
#include "Base.h"
#endif

#include <iostream>

class Villain: public Base {
    std::string name;
    std::string weaponType;
    std::string placeOfLiving;
public:
    void printParams(std::ostream &out) override;
    Villain();
    Villain(std::string& name, std::string& weaponType, std::string& newPlace);
    Villain(Villain& src);
    ~Villain();
    const std::string &getName() const;
    void setName(const std::string &name);
    const std::string &getWeaponType() const;
    void setWeaponType(const std::string &weaponType);
    const std::string &getPlaceOfLiving() const;
    void setPlaceOfLiving(const std::string &placeOfLiving);
};


#endif //LR1_VILLAIN_H
