//
// Created by Павел Жуков on 07/10/2021.
//

#include "Hero.h"
#include "useful.h"

const std::string &Hero::getName() const {
    return name;
}

void Hero::setName(const std::string &name) {
    Hero::name = name;
}

const std::string &Hero::getWeaponType() const {
    return weaponType;
}

void Hero::setWeaponType(const std::string &weaponType) {
    Hero::weaponType = weaponType;
}

const std::string &Hero::getAbilities() const {
    return abilities;
}

void Hero::addAbility(const std::string &Ability) {
    abilities += "\n" + Ability;
}

void Hero::printParams() {
    std::cout << "Name: " << name << std::endl
        << "Weapon Used: " << weaponType << std::endl
        << "Abilities: " << abilities << std::endl;
}

Hero::Hero() : Base("Hero"),
               name("null null"),
               weaponType("null-47"),
               abilities("None"){
    std::cout << "Empty Hero created!" << std::endl;
}

Hero::Hero(std::string& newName, std::string& newWeaponType, std::string& newAbilities) : Base("Hero"),
                                                                                          name(newName),
                                                                                          weaponType(newWeaponType),
                                                                                          abilities(newAbilities) {
    std::cout << "Hero with parameters created!" << std::endl;
}

Hero::Hero(const Hero &character) : Base(character.getType()),
                                    name(character.getName()),
                                    weaponType(character.getWeaponType()),
                                    abilities(character.getAbilities()){
    std::cout << "Hero copied!" << std::endl;
}

Hero::~Hero() {
    std::cout << "Hero destroyed" << std::endl;
}

std::string Hero::getInfoForFile() {
    return std::string("\n" +
                       name +
                       "\n" +
                       weaponType +
                       "\n" +
                       std::to_string(get_amt_of_strings(abilities)) +
                       "\n" +
                       abilities);
}

const std::string Hero::getNormalName() const {

    return to_lower(name);
}
