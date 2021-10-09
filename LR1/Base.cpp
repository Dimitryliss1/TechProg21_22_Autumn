//
// Created by Павел Жуков on 06/10/2021.
//

#include "Base.h"
#include <iostream>

Base::~Base() {
    std::cout << "Base " << type << " destroyed!" << std::endl;
}

Base::Base(): type(std::string("null")){
    std::cout << "Null base character created!" << std::endl;
}

Base::Base(std::string newType): type(newType) {
    std::cout << "Base " << type << " created!" << std::endl;
}

std::string Base::getType() const {
    return type;
}

Base::Base(const Base &character): type(character.type) {
    std::cout << "Base " << type << " copied!" << std::endl;
}
