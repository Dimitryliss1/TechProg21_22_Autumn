//
// Created by Павел Жуков on 17/10/2021.
//

#include "Keeper.h"

Keeper *Keeper::getInstance() {
    if (instance == nullptr){
        instance = new Keeper();
    }
    return instance;
}

Keeper::Keeper(): amt_cases(0), amt_monsters(0), amt_officers(0), amt_villains(0) {
    cases = (CourtCase*) calloc(amt_cases, sizeof(CourtCase));
    monsters = (Monster*) calloc(amt_monsters, sizeof(Monster));
    officers = (Hero*) calloc(amt_officers, sizeof(Hero));
    villains = (Villain*) calloc(amt_villains, sizeof(Villain));
    std::cout << "Created Keeper!" << std::endl;
}

Keeper::~Keeper() {
    delete [] cases;
    delete [] monsters;
    delete [] officers;
    delete [] villains;
    std::cout << "Destroyed Keeper!" << std::endl;
}

void Keeper::CreateOfficer() {
    std::string name, weapon, abilities;
    std::cout << "Pass officer's nam: ";
    std::getline(std::cin, name);

    bool flag = false;
    for(int i = 0; i < amt_officers; i++){
        if (officers[i].getNormalName() == *to_lower(name)){
            flag = true;
            break;
        }
    }

    std::cout << "Pass officer's weapon: ";
}
