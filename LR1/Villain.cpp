//
// Created by Павел Жуков on 17/10/2021.
//

#include "Villain.h"
#include "useful.h"

void Villain::printParams() {
    std::cout << "Name: " << name << std::endl
        << "Weapon used: " << weaponType << std::endl
        << "Place of Living: " << placeOfLiving << std::endl
        << "Abilities: " << abilities << std::endl;
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
                    weaponType("null"),
                    placeOfLiving("null"),
                    abilities("null"){
    std::cout << "Empty villain created!" << std::endl;
}

Villain::Villain(std::string &name, std::string &weaponType, std::string& newPlace, std::string& abilities): Base("Villain"),
                                                                                     name(name),
                                                                                     weaponType(weaponType),
                                                                                     placeOfLiving(newPlace),
                                                                                     abilities(abilities){
    std::cout << "Villain with parameters created!" << std::endl;
}

Villain::Villain(const Villain &src): Base(src.getType()),
                                name(src.getName()),
                                weaponType(src.getWeaponType()),
                                placeOfLiving(src.getPlaceOfLiving()),
                                abilities(src.getAbilities()){
    std::cout << "Villain copied!" << std::endl;
}

Villain::~Villain() {
    std::cout << "Villain destroyed!" << std::endl;
}

const std::string &Villain::getPlaceOfLiving() const {
    return placeOfLiving;
}

void Villain::setPlaceOfLiving(const std::string &placeOfLiving) {
    Villain::placeOfLiving = placeOfLiving;
}

std::string Villain::getInfoForFile() {
    return std::string(getType() +
                       "\n" +
                       name +
                       "\n" +
                       weaponType +
                       "\n" +
                       placeOfLiving +
                       "\n" +
                       std::to_string(get_amt_of_strings(abilities)) +
                       "\n" +
                       abilities);
}

std::string Villain::getNormalName() {
    return to_lower(name);
}

const std::string &Villain::getAbilities() const {
    return abilities;
}

void Villain::AddAbilities(const std::string &abilities){
    Villain::abilities += '\n' + abilities;
}

