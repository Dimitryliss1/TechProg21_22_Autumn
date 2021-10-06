//
// Created by Павел Жуков on 06/10/2021.
//

#include "Characters.h"
#include <iostream>

Characters::~Characters() {
    std::cout << "Base " << type << " destroyed!" << std::endl;
}

Characters::Characters(): type(std::string("null")){
    std::cout << "Null base object created!" << std::endl;
}

Characters::Characters(std::string newType): type(newType) {
    std::cout << "Base " << type << " created!" << std::endl;
}

std::string Characters::getType() {
    return type;
}

Characters::Characters(const Characters &character): type(character.type) {
    std::cout << "Base " << type << " copied!" << std::endl;
}
