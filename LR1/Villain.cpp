//
// Created by Павел Жуков on 17/10/2021.
//

#include "Villain.h"

void Villain::printParams(std::ostream &out) {
    out << "Name: " << name << std::endl
        << "Weapon used: " << weaponType << std::endl;
}

const std::string &Villain::getName() const {
    return name;
}

void Villain::setName(const std::string &name) {
    Villain::name = name;
}

const std::string &Villain::getWeaponType() const {
    return weaponType;
}

void Villain::setWeaponType(const std::string &weaponType) {
    Villain::weaponType = weaponType;
}

Villain::Villain(): Base("Villain"),
                    name("null"),
                    weaponType("null"){
    std::cout << "Empty villain created!" << std::endl;
}

Villain::Villain(std::string &name, std::string &weaponType): Base("Villain"),
                                                              name(name),
                                                              weaponType(weaponType){
    std::cout << "Villain with parameters created!" << std::endl;
}

Villain::Villain(Villain &src): Base(src.getType()),
                                name(src.getName()),
                                weaponType(src.getWeaponType()){
    std::cout << "Villain copied!" << std::endl;
}

Villain::~Villain() {
    std::cout << "Villain destroyed!" << std::endl;
}


