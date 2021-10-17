//
// Created by Павел Жуков on 17/10/2021.
//

#include "Monster.h"
#ifndef LR1_USEFUL_H
#include "useful.h"
#endif

const std::string &Monster::getName() const {
    return name;
}

void Monster::setName(const std::string &name) {
    Monster::name = name;
}

const std::string &Monster::getDescription() const {
    return description;
}

void Monster::setDescription(const std::string &description) {
    Monster::description = description;
}

void Monster::printParams(std::ostream &out) {
    out << "Name: " << name << std::endl
        << "Description: " << description << std::endl;
}

Monster::Monster(): Base("Monster"),
                    name("null"),
                    description("null"){
    std::cout << "Empty monster created!" << std::endl;
}

Monster::Monster(std::string &name, std::string &description): Base("Monster"),
                                                               name(name),
                                                               description(description){
    std::cout << "Monster with parameters created!" << std::endl;
}

Monster::Monster(const Monster &src): Base(src.getType()),
                                name(src.getName()),
                                description(src.getDescription()){
    std::cout << "Monster copied!" << std::endl;
}

Monster::~Monster() {
    std::cout << "Monster destroyed!" << std::endl;
}

bool Monster::operator==(const Monster &rhs) const {
    return name == rhs.name && description == rhs.description;
}

std::string Monster::getInfoForFile() {
    char *tmp = nullptr;
    sprintf(tmp, "%d", get_amt_of_strings(description));
    std::string a(tmp);
    delete tmp;
    return std::string(getType() + "\n" + name + "\n" + a + "\n" + description + "\n");
}

std::string Monster::getNormalName() {
    return *to_lower(name);
}




