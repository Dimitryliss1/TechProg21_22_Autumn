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
    std::cout << "Pass officer's name: ";
    std::getline(std::cin >> std::ws, name);
    int index = 0;
    bool flag = false;
    for (int i = 0; i < amt_officers; i++) {
        if (officers[i].getNormalName() == *to_lower(name)) {
            flag = true;
            index = i;
            break;
        }
    }
    if (flag) {
        std::cout << "Officer with such name already exists.\n"
                     "If you wish to proceed, this record will be updated.\n"
                     "Continue? 0 -- No, 1 -- Yes\n"
                     "Your choice: ";
        int choice = safe_input();
        while (choice < 0 || choice > 1) {
            std::cout << "No such choice!\n";
            std::cout << "Try again: ";
            choice = safe_input();
        }
        if (choice == 0) {
            std::cout << "Aborting.\n";
            return;
        }
    }
    std::cout << "Pass officer's weapon: ";
    std::getline(std::cin >> std::ws, weapon);
    std::cout << "Pass officer's abilities. When you want to stop, hit Enter twice after string\n";
    while (true){
        std::string tmp;
        std::getline(std::cin >> std::ws, tmp);
        if (tmp == "\n"){
            break;
        }
        abilities += tmp;
    }

    if (flag) {
        officers[index] = Hero(name, weapon, abilities);
    } else {
        amt_officers += 1;
        officers = (Hero*) realloc (officers, amt_officers*sizeof(Hero));
        officers[amt_officers-1] = Hero(name, weapon, abilities);
    }
}

void Keeper::CreateVillain() {
    std::string name, weapon, place;
    std::cout << "Pass villain's name: ";
    std::getline(std::cin >> std::ws, name);
    int index = 0;
    bool flag = false;
    for (int i = 0; i < amt_villains; i++) {
        if (villains[i].getNormalName() == *to_lower(name)) {
            flag = true;
            index = i;
            break;
        }
    }
    if (flag) {
        std::cout << "Villain with such name already exists.\n"
                     "If you wish to proceed, this record will be updated.\n"
                     "Continue? 0 -- No, 1 -- Yes\n"
                     "Your choice: ";
        int choice = safe_input();
        while (choice < 0 || choice > 1) {
            std::cout << "No such choice!\n";
            std::cout << "Try again: ";
            choice = safe_input();
        }
        if (choice == 0) {
            std::cout << "Aborting.\n";
            return;
        }
    }
    std::cout << "Pass villain's weapon: ";
    std::getline(std::cin >> std::ws, weapon);
    std::cout << "Pass villain's place of living: ";
    std::getline(std::cin >> std::ws, place);

    if (flag) {
        villains[index] = Villain(name, weapon, place);
    } else {
        amt_villains += 1;
        villains = (Villain*) realloc (villains, amt_villains*sizeof(Villain));
        villains[amt_villains-1] = Villain(name, weapon, place);
    }
}

void Keeper::CreateMonster() {
    std::string name, description;
    std::cout << "Pass monster's name: ";
    std::getline(std::cin >> std::ws, name);
    int index = 0;
    bool flag = false;
    for (int i = 0; i < amt_monsters; i++) {
        if (monsters[i].getNormalName() == *to_lower(name)) {
            flag = true;
            index = i;
            break;
        }
    }
    if (flag) {
        std::cout << "Monster with such name already exists.\n"
                     "If you wish to proceed, this record will be updated.\n"
                     "Continue? 0 -- No, 1 -- Yes\n"
                     "Your choice: ";
        int choice = safe_input();
        while (choice < 0 || choice > 1) {
            std::cout << "No such choice!\n";
            std::cout << "Try again: ";
            choice = safe_input();
        }
        if (choice == 0) {
            std::cout << "Aborting.\n";
            return;
        }
    }
    std::cout << "Pass monster's description. When you want to stop, hit Enter twice after string\n";
    while (true){
        std::string tmp;
        std::getline(std::cin >> std::ws, tmp);
        if (tmp == "\n"){
            break;
        }
        description += tmp;
    }

    if (flag) {
        monsters[index] = Monster(name, description);
    } else {
        amt_monsters += 1;
        monsters = (Monster*) realloc (officers, amt_monsters*sizeof(Hero));
        monsters[amt_monsters-1] = Monster(name, description);
    }
}

void Keeper::CreateCase() {

}

void Keeper::DeleteOfficer() {

}

void Keeper::DeleteVillain() {

}

void Keeper::DeleteMonster() {

}

void Keeper::DeleteCase() {

}

void Keeper::PrintAvailableCases() {

}

void Keeper::PrintAvailableMonsters() {

}

void Keeper::PrintAvailableVillains() {

}

void Keeper::PrintAvailableOfficers() {

}

void Keeper::PrintCase() {

}

void Keeper::PrintMonster() {

}

void Keeper::PrintVillain() {

}

void Keeper::PrintOfficer() {

}

void Keeper::EditOfficer() {

}

void Keeper::EditVillain() {

}

void Keeper::EditMonster() {

}

void Keeper::EditCase() {

}

std::string Keeper::getStringForFile() {
    return std::string();
}

