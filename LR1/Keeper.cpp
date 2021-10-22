//
// Created by Павел Жуков on 17/10/2021.
//

#include <fstream>
#include "Keeper.h"

Keeper *Keeper::getInstance() {
    static Keeper instance;
    return &instance;
}

Keeper::Keeper(): amt_cases(0), amt_monsters(0), amt_officers(0), amt_villains(0) {
    cases = (CourtCase**) calloc(amt_cases, sizeof(CourtCase));
    monsters = (Monster**) calloc(amt_monsters, sizeof(Monster));
    officers = (Hero**) calloc(amt_officers, sizeof(Hero));
    villains = (Villain**) calloc(amt_villains, sizeof(Villain));
    std::cout << "Created Keeper!" << std::endl;
}

Keeper::~Keeper() {
    for(int i = 0; i < amt_cases; i++){
        delete cases[i];
    }
    free(cases);

    for(int i = 0; i < amt_officers; i++){
        delete officers[i];
    }
    free(officers);

    for(int i = 0; i < amt_villains; i++){
        delete villains[i];
    }
    free(villains);

    for(int i = 0; i < amt_monsters; i++){
        delete monsters[i];
    }
    free(monsters);
    std::cout << "Destroyed Keeper!" << std::endl;
}

void Keeper::CreateOfficer() {
    std::string name, weapon, abilities;
    std::cout << "Pass officer's name: ";
    std::getline(std::cin >> std::ws, name);
    int index = 0;
    bool flag = false;
    for (int i = 0; i < amt_officers; i++) {
        if (to_lower(officers[i]->getName()) == to_lower(name)) {
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
        std::getline(std::cin, tmp);
        if (tmp.empty()){
            break;
        }
        abilities += tmp + "\n";
    }
    if (amt_officers == 0){
        officers = (Hero**) calloc (++amt_officers, sizeof(Hero));
        officers[0] = new Hero(name, weapon, abilities);
        return;
    }
    if (flag) {
        officers[index] = new Hero(name, weapon, abilities);
    } else {
        amt_officers += 1;
        officers = (Hero**) realloc (officers, amt_officers*sizeof(Hero));
        officers[amt_officers-1] = new Hero(name, weapon, abilities);
    }
}

void Keeper::CreateVillain() {
    std::string name, weapon, place, abilities;
    std::cout << "Pass villain's name: ";
    std::getline(std::cin >> std::ws, name);
    int index = 0;
    bool flag = false;
    for (int i = 0; i < amt_villains; i++) {
        if (villains[i]->getNormalName() == to_lower(name)) {
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
    std::cout << "Pass villain's abilities. When you want to stop, hit Enter twice after string\n";
    while (true){
        std::string tmp;
        std::getline(std::cin, tmp);
        if (tmp.empty()){
            break;
        }
        abilities += tmp + "\n";
    }
    if (amt_villains == 0){
        villains = (Villain**) calloc (++amt_villains, sizeof(Villain));
        villains[0] = new Villain(name, weapon, place, abilities);
        return;
    }
    if (flag) {
        villains[index] = new Villain(name, weapon, place, abilities);
    } else {
        amt_villains += 1;
        villains = (Villain**) realloc (villains, amt_villains*sizeof(Villain));
        villains[amt_villains-1] = new Villain(name, weapon, place, abilities);
    }
}

void Keeper::CreateMonster() {
    std::string name, description;
    std::cout << "Pass monster's name: ";
    std::getline(std::cin >> std::ws, name);
    int index = 0;
    bool flag = false;
    for (int i = 0; i < amt_monsters; i++) {
        if (monsters[i]->getNormalName() == to_lower(name)) {
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
        std::cin.ignore();
    }
    std::cout << "Pass monster's description. When you want to stop, hit Enter twice after string\n";
    while (true){
        std::string tmp;
        std::getline(std::cin, tmp);
        if (tmp.empty()){
            break;
        }
        description += tmp + "\n";
    }
    if (amt_monsters == 0){
        monsters = (Monster**) calloc (++amt_monsters, sizeof(Monster));
        monsters[0] = new Monster(name, description);
        return;
    }
    if (flag) {
        monsters[index] = new Monster(name, description);
    } else {
        amt_monsters += 1;
        monsters = (Monster**) realloc (monsters, amt_monsters*sizeof(Monster));
        monsters[amt_monsters-1] = new Monster(name, description);
    }
}

void Keeper::CreateCase() {
    if(amt_monsters == 0 || amt_villains == 0 || amt_officers == 0){
        std::cout << "You need to create at least 1 monster, villain and officer to start the case.\n";
        return;
    }
    std::cout << "Opening case..." << std::endl;
    if (amt_cases == 0) cases = (CourtCase**) calloc (++amt_cases, sizeof(CourtCase));
    else cases = (CourtCase**) realloc (cases, ++amt_cases*sizeof(CourtCase));
    cases[amt_cases-1] = new CourtCase();
    std::cout << "Pass title of case: ";
    std::string title;
    std::getline(std::cin >> std::ws, title);
    while (true){
        bool flag = false;
        for(int i = 0; i < amt_cases - 1; i++){
            if (to_lower(cases[i]->getTitle()) == to_lower(title)){
                flag = true;
                break;
            }
        }
        if (!flag){
            cases[amt_cases-1]->setTitle(title);
            break;
        } else {
            std::cout << "Case with such name already exists.\n"
                         "Pass new name: ";
            std::getline(std::cin >> std::ws, title);
        }
    }

    std::cout << "Who is the villain? Choose id from the list below: \n";
    PrintAvailableVillains();
    std::cout << "Your choice: ";
    int villain = safe_input();
    while (villain < 0 || villain > amt_villains){
        std::cout << "No such villain.\n"
                     "Try again: ";
        villain = safe_input();
    }

    cases[amt_cases-1]->setCriminal(*villains[villain]);
    std::cout << "Now type in ids of monsters participated.\nOne string = one monster.\nAvailable monsters listed below:\n";
    PrintAvailableMonsters();
    std::cout << "When you are done, pass -1\n";
    while (true){
        std::cout << "Monster ID: ";
        int id = safe_input();
        if (id == -1) break;
        while (id < 0 || id > amt_monsters){
            std::cout << "No such monster.\n"
                         "Try again: ";
            id = safe_input();
        }
        cases[amt_cases-1]->addMonster(*monsters[id]);
    }

    std::cout << "Who will be responsible for this case? Choose id from list below:\n";
    PrintAvailableOfficers();
    std::cout << "Your choice: ";
    int officer = safe_input();
    while (officer < 0 || officer > amt_officers){
        std::cout << "No such officer.\n"
                     "Try again: ";
        officer = safe_input();
    }
    std::cin.ignore();
    cases[amt_cases-1]->setResponsible(*officers[officer]);
    std::cout << "What happened? Write down here.\n"
                 "When you want to stop, hit Enter twice after string\n";
    std::string descr;
    while (true){
        std::string tmp;
        std::getline(std::cin, tmp);
        if (tmp.empty()){
            break;
        }
        descr += tmp+"\n";
    }
    cases[amt_cases-1]->setDescription(descr);
}

void Keeper::DeleteOfficer() {
    try {
        PrintAvailableOfficers();
        std::cout << "Choose the officer you want to delete: ";
        int choice = safe_input();
        while (choice < 0 || choice > amt_officers) {
            std::cout << "No such officer.\n"
                         "Try again: ";
            choice = safe_input();
        }
        Hero** tmp = (Hero**) calloc (--amt_officers, sizeof(Hero));
        int flag = 0;
        for(int i = 0; i < amt_officers + 1; i++){
            if (i != choice){
                tmp[i-flag] = officers[i];
            } else {
                flag = 1;
            }
        }
        delete officers[choice];
        free(officers);
        officers = (Hero**) calloc (amt_officers, sizeof(Hero));
        for(int i = 0; i < amt_officers; i++){
            officers[i] = tmp[i];
        }
        free(tmp);
    } catch (EmptyListException& a){
        std::cout << a.what() << std::endl;
    }
}

void Keeper::DeleteVillain() {
    try {
        PrintAvailableVillains();
        std::cout << "Choose the villain you want to delete: ";
        int choice = safe_input();
        while (choice < 0 || choice > amt_villains) {
            std::cout << "No such villain.\n"
                         "Try again: ";
            choice = safe_input();
        }
        Villain** tmp = (Villain**) calloc (--amt_villains, sizeof(Villain));
        int flag = 0;
        for(int i = 0; i < amt_villains + 1; i++){
            if (i != choice){
                tmp[i-flag] = villains[i];
            } else {
                flag = 1;
            }
        }
        delete villains[choice];
        free(villains);
        villains = (Villain**) calloc (amt_villains, sizeof(Villain));
        for(int i = 0; i < amt_villains; i++){
            villains[i] = tmp[i];
        }
        free(tmp);
    } catch (EmptyListException& a){
        std::cout << a.what() << std::endl;
    }
}

void Keeper::DeleteMonster() {
    try {
        PrintAvailableMonsters();
        std::cout << "Choose the monster you want to delete: ";
        int choice = safe_input();
        while (choice < 0 || choice > amt_monsters) {
            std::cout << "No such monster.\n"
                         "Try again: ";
            choice = safe_input();
        }
        Monster** tmp = (Monster**) calloc (--amt_monsters, sizeof(Monster));
        int flag = 0;
        for(int i = 0; i < amt_monsters + 1; i++){
            if (i != choice){
                tmp[i-flag] = monsters[i];
            } else {
                flag = 1;
            }
        }
        delete monsters[choice];
        free(monsters);
        monsters = (Monster**) calloc (amt_monsters, sizeof(Monster));
        for(int i = 0; i < amt_monsters; i++){
            monsters[i] = tmp[i];
        }
        free(tmp);
    } catch (EmptyListException& a){
        std::cout << a.what() << std::endl;
    }
}

void Keeper::DeleteCase() {
    try {
        PrintAvailableCases();
        std::cout << "Choose the case you want to delete: ";
        int choice = safe_input();
        while (choice < 0 || choice > amt_cases) {
            std::cout << "No such case.\n"
                         "Try again: ";
            choice = safe_input();
        }
        int flag = 0;
        CourtCase** tmp = (CourtCase**) calloc (--amt_cases, sizeof(CourtCase));
        for(int i = 0; i < amt_cases + 1; i++){
            if (i != choice){
                tmp[i-flag] = cases[i];
            } else {
                flag = 1;
            }
        }
        delete cases[choice];
        free(cases);
        cases = (CourtCase**) calloc (amt_cases, sizeof(CourtCase));
        for(int i = 0; i < amt_cases; i++){
            cases[i] = tmp[i];
        }
        free(tmp);
    } catch (EmptyListException& a){
        std::cout << a.what() << std::endl;
    }
}

void Keeper::PrintAvailableCases() {
    if (amt_cases == 0){
        throw EmptyListException("List is empty");
    }
    for(int i = 0; i < amt_cases; i++){
        std::cout << i << ". " << cases[i]->getTitle() << std::endl;
    }
}

void Keeper::PrintAvailableMonsters() {
    if (amt_monsters == 0){
        throw EmptyListException("List is empty");
    }
    for(int i = 0; i < amt_monsters; i++){
        std::cout << i << ". " << monsters[i]->getName() << std::endl;
    }
}

void Keeper::PrintAvailableVillains() {
    if (amt_villains == 0){
        throw EmptyListException("List is empty");
    }
    for(int i = 0; i < amt_villains; i++){
        std::cout << i << ". " << villains[i]->getName() << std::endl;
    }
}

void Keeper::PrintAvailableOfficers() {
    if (amt_officers == 0){
        throw EmptyListException("List is empty");
    }
    for(int i = 0; i < amt_officers; i++){
        std::cout << i << ". " << officers[i]->getName() << std::endl;
    }
}

void Keeper::PrintCase() {
    try {
        PrintAvailableCases();
        std::cout << "Choose the case you want to see more about: ";
        int choice = safe_input();
        while (choice < 0 || choice > amt_cases) {
            std::cout << "No such case.\n"
                         "Try again: ";
            choice = safe_input();
        }
        cases[choice]->printInfo(std::cout);
    } catch (EmptyListException& a){
        std::cout << a.what() << std::endl;
    }
}

void Keeper::PrintMonster() {
    try {
        PrintAvailableMonsters();
        std::cout << "Choose the monster you want to see more about: ";
        int choice = safe_input();
        while (choice < 0 || choice > amt_monsters) {
            std::cout << "No such monster.\n"
                         "Try again: ";
            choice = safe_input();
        }
        monsters[choice]->printParams();
    } catch (EmptyListException& a){
        std::cout << a.what() << std::endl;
    }
}

void Keeper::PrintVillain() {
    try {
        PrintAvailableVillains();
        std::cout << "Choose the villain you want to see more about: ";
        int choice = safe_input();
        while (choice < 0 || choice > amt_villains) {
            std::cout << "No such villain.\n"
                         "Try again: ";
            choice = safe_input();
        }
        villains[choice]->printParams();
    } catch (EmptyListException& a){
        std::cout << a.what() << std::endl;
    }
}

void Keeper::PrintOfficer() {
    try {
        PrintAvailableOfficers();
        std::cout << "Choose the officer you want to see more about: ";
        int choice = safe_input();
        while (choice < 0 || choice > amt_officers) {
            std::cout << "No such officer.\n"
                         "Try again: ";
            choice = safe_input();
        }
        Hero* tmp = officers[choice];
        tmp->printParams();
    } catch (EmptyListException& a){
        std::cout << a.what() << std::endl;
    }
}

void Keeper::EditOfficer() {
    try {
        PrintAvailableOfficers();
        std::cout << "Choose the officer you want to edit: ";
        int choice = safe_input();
        while (choice < 0 || choice > amt_officers) {
            std::cout << "No such officer.\n"
                         "Try again: ";
            choice = safe_input();
        }
        while(true){
            std::cout << "Choose what you want to edit:\n"
                         "1. Change name\n"
                         "2. Change weapon\n"
                         "3. Add ability\n"
                         "0. Quit\n"
                         "Your choice: ";
            int in_c = safe_input();
            while (in_c < 0 || in_c > 3){
                std::cout << "No such choice.\n"
                             "Try again: ";
                in_c = safe_input();
            }
            if (in_c == 0) break;
            else if (in_c == 1){
                std::cout << "Type in new name: ";
                std::string name;
                std::getline(std::cin >> std::ws, name);
                while(true){
                    bool flag = false;
                    for (int i = 0; i < amt_officers; i++){
                        if (officers[i]->getNormalName() == to_lower(name) && i != choice){
                            flag = true;
                            break;
                        }
                    }
                    if (flag) {
                        std::cout << "Officer with such name already exists.\nTry again: ";
                        std::getline(std::cin >> std::ws, name);
                    } else {
                        officers[choice]->setName(name);
                        break;
                    }
                }
            } else if (in_c == 2){
                std::cout << "Pass new weapon type: ";
                std::string weapon;
                std::getline(std::cin >> std::ws, weapon);
                officers[choice]->setWeaponType(weapon);
            } else if (in_c == 3){
                std::cout << "Pass officer's ability. When you want to stop, hit Enter twice after string\n";
                std::string abilities;
                std::getline(std::cin >> std::ws, abilities);
                officers[choice]->addAbility(abilities);
            }
        }
    } catch (EmptyListException& a){
        std::cout << a.what() << std::endl;
    }
}

void Keeper::EditVillain() {
    try {
        PrintAvailableVillains();
        std::cout << "Choose the villain you want to edit: ";
        int choice = safe_input();
        while (choice < 0 || choice > amt_villains) {
            std::cout << "No such villain.\n"
                         "Try again: ";
            choice = safe_input();
        }
        while(true){
            std::cout << "Choose what you want to edit:\n"
                         "1. Change name\n"
                         "2. Change weapon\n"
                         "3. Change place of living\n"
                         "4. Add ability\n"
                         "0. Quit\n"
                         "Your choice: ";
            int in_c = safe_input();
            while (in_c < 0 || in_c > 4){
                std::cout << "No such choice.\n"
                             "Try again: ";
                in_c = safe_input();
            }
            if (in_c == 0) break;
            else if (in_c == 1){
                std::cout << "Type in new name: ";
                std::string name;
                std::getline(std::cin >> std::ws, name);
                while(true){
                    bool flag = false;
                    for (int i = 0; i < amt_villains; i++){
                        if (villains[i]->getNormalName() == to_lower(name) && i != choice){
                            flag = true;
                            break;
                        }
                    }
                    if (flag) {
                        std::cout << "Villain with such name already exists.\nTry again: ";
                        std::getline(std::cin >> std::ws, name);
                    } else {
                        villains[choice]->setName(name);
                        break;
                    }
                }
            } else if (in_c == 2){
                std::cout << "Pass new weapon type: ";
                std::string weapon;
                std::getline(std::cin >> std::ws, weapon);
                villains[choice]->setWeaponType(weapon);
            } else if (in_c == 3){
                std::cout << "Pass new place: ";
                std::string place;
                std::getline(std::cin >> std::ws, place);
                villains[choice]->setPlaceOfLiving(place);
            } else if (in_c == 4){
                std::cout << "Pass new ability: ";
                std::string ability;
                std::getline(std::cin >> std::ws, ability);
                villains[choice]->AddAbilities(ability);
            }

        }
    } catch (EmptyListException& a){
        std::cout << a.what() << std::endl;
    }
}

void Keeper::EditMonster() {
    try {
        PrintAvailableMonsters();
        std::cout << "Choose the monster you want to edit: ";
        int choice = safe_input();
        while (choice < 0 || choice > amt_monsters) {
            std::cout << "No such monster.\n"
                         "Try again: ";
            choice = safe_input();
        }
        while(true){
            std::cout << "Choose what you want to edit:\n"
                         "1. Change name\n"
                         "2. Change description\n"
                         "0. Quit\n"
                         "Your choice: ";
            int in_c = safe_input();
            while (in_c < 0 || in_c > 2){
                std::cout << "No such choice.\n"
                             "Try again: ";
                in_c = safe_input();
            }
            if (in_c == 0) break;
            else if (in_c == 1){
                std::cout << "Type in new name: ";
                std::string name;
                std::getline(std::cin >> std::ws, name);
                while(true){
                    bool flag = false;
                    for (int i = 0; i < amt_monsters; i++){
                        if (monsters[i]->getNormalName() == to_lower(name) && i != choice){
                            flag = true;
                            break;
                        }
                    }
                    if (flag) {
                        std::cout << "Monster with such name already exists.\nTry again: ";
                        std::getline(std::cin >> std::ws, name);
                    } else {
                        monsters[choice]->setName(name);
                        break;
                    }
                }
            } else if (in_c == 2){
                std::cin.ignore();
                std::cout << "Pass monster's description. When you want to stop, hit Enter twice after string\n";
                std::string description;
                while (true){
                    std::string tmp;
                    std::getline(std::cin, tmp);
                    if (tmp.empty()){
                        break;
                    }
                    description += tmp;
                }
                monsters[choice]->setDescription(description);
            }
        }
    } catch (EmptyListException& a){
        std::cout << a.what() << std::endl;
    }
}

void Keeper::EditCase() {
    try {
        PrintAvailableCases();
        std::cout << "Choose the case you want to edit: ";
        int choice = safe_input();
        while (choice < 0 || choice > amt_cases) {
            std::cout << "No such case.\n"
                         "Try again: ";
            choice = safe_input();
        }
        while (true){
            std::cout << "Choose what you want to change:\n"
                         "1. Change responsible\n"
                         "2. Change villain\n"
                         "3. Add monster\n"
                         "4. Change description\n"
                         "5. Change title\n"
                         "0. Close case\n"
                         "Your choice: ";
            int in_c = safe_input();
            while (in_c < 0 || in_c > 5){
                std::cout << "No such choice.\n"
                             "Try again: ";
                in_c = safe_input();
            }
            if (in_c == 0) {
                return;
            } else if (in_c == 1){
                try {
                    PrintAvailableOfficers();
                    std::cout << "Choose the officer you want to assign: ";
                    int of = safe_input();
                    while (of < 0 || of > amt_officers) {
                        std::cout << "No such officer.\n"
                                     "Try again: ";
                        of = safe_input();
                    }
                    cases[choice]->setResponsible(*officers[of]);
                } catch (EmptyListException& a){
                    std::cout << a.what() << std::endl;
                }
            } else if (in_c == 2){
                try {
                    PrintAvailableVillains();
                    std::cout << "Choose the villain you want to assign: ";
                    int of = safe_input();
                    while (of < 0 || of > amt_officers) {
                        std::cout << "No such villain.\n"
                                     "Try again: ";
                        of = safe_input();
                    }
                    cases[choice]->setCriminal(*villains[of]);
                } catch (EmptyListException& a){
                    std::cout << a.what() << std::endl;
                }
            } else if (in_c == 3){
                try {
                    PrintAvailableMonsters();
                    std::cout << "Choose the monster you want to assign: ";
                    int of = safe_input();
                    while (of < 0 || of > amt_monsters) {
                        std::cout << "No such monster.\n"
                                     "Try again: ";
                        of = safe_input();
                    }
                    cases[choice]->addMonster(*monsters[of]);
                } catch (EmptyListException& a){
                    std::cout << a.what() << std::endl;
                }
            } else if (in_c == 4) {
                std::cout << "Pass case's description. When you want to stop, hit Enter twice after string\n";
                std::string description;
                while (true){
                    std::string tmp;
                    std::getline(std::cin >> std::ws, tmp);
                    if (tmp == "\n"){
                        break;
                    }
                    description += tmp;
                }
                cases[choice]->setDescription(description);
            } else if (in_c == 5){
                std::cout << "Pass case's title: ";
                std::string title;
                std::getline(std::cin >> std::ws, title);
                while(true) {
                    bool flag = false;
                    for (int i = 0; i < amt_cases; i++) {
                        if (to_lower(cases[i]->getTitle()) == to_lower(title) && i != choice) {
                            flag = true;
                            break;
                        }
                    }
                    if (!flag){
                        cases[choice]->setTitle(title);
                        break;
                    } else {
                        std::cout << "The case with this title already exists.\nTry again: ";
                        std::getline(std::cin, title);
                    }
                }
            }
        }
    } catch (EmptyListException& a){
        std::cout << a.what() << std::endl;
    }
}

std::string Keeper::getStringForFile() {
    std::string res;
    res += std::to_string(amt_officers) + "\n";
    for (int i = 0; i < amt_officers; i++){
        res += officers[i]->getInfoForFile();
    }

    res += std::to_string(amt_villains) + "\n";
    for (int i = 0; i < amt_villains; i++){
        res += villains[i]->getInfoForFile();
    }

    res += std::to_string(amt_monsters) + "\n";
    for (int i = 0; i < amt_monsters; i++){
        res += monsters[i]->getInfoForFile();
    }

    res += std::to_string(amt_cases) + "\n";
    for (int i = 0; i < amt_cases; i++){
        res += cases[i]->getInfoForFile();
    }
    return res;
}

std::ostream &operator<<(std::ostream &stream, Keeper &a) {
    std::string tmp = a.getStringForFile();
    stream << tmp;
    return stream;
}

void Keeper::readFromFile(std::string& path) {
    std::ifstream in;
    in.open(path);
    if (in.fail()) {
        std::cout << "No such file or error in file path\n";
        return;
    }
    for(int i = 0; i < amt_cases; i++){
        delete cases[i];
    }
    free(cases);

    for(int i = 0; i < amt_officers; i++){
        delete officers[i];
    }
    free(officers);

    for(int i = 0; i < amt_villains; i++){
        delete villains[i];
    }
    free(villains);

    for(int i = 0; i < amt_monsters; i++){
        delete monsters[i];
    }
    free(monsters);

    in >> amt_officers;
    if (in.fail() || !in){
        throw FormatException("Error reading file");
    }

    if (amt_officers > 0) in.ignore();
    officers = (Hero**) calloc(amt_officers, sizeof(Hero));

    for(int hero = 0; hero < amt_officers; hero++){
        Hero* tmp = new Hero();
        try {
            in >> tmp;
        } catch(FormatException& a){
            throw a;
        }
        officers[hero] = tmp;
    }

    in >> amt_villains;

    if (in.fail() || !in){
        throw FormatException("Error reading file");
    }
    if (amt_villains > 0) in.ignore();

    villains = (Villain**) calloc(amt_villains, sizeof(Villain));

    for(int hero = 0; hero < amt_villains; hero++){
        Villain* tmp = new Villain();
        try {
            in >> tmp;
        } catch(FormatException& a){
            throw a;
        }
        villains[hero] = tmp;
    }

    in >> amt_monsters;

    if (in.fail() || !in){
        throw FormatException("Error reading file");
    }
    if (amt_monsters > 0) in.ignore();
    monsters = (Monster**) calloc(amt_monsters, sizeof(Monster));
    for(int hero = 0; hero < amt_monsters; hero++){
        Monster* tmp = new Monster();
        try {
            in >> tmp;
        } catch(FormatException& a){
            throw a;
        }
        monsters[hero] = tmp;
    }

    in >> amt_cases;
    if (amt_cases > 0) in.ignore();
    if (in.fail()){
        throw FormatException("Error reading file");
    }
    cases = (CourtCase**) calloc(amt_cases, sizeof(CourtCase));
    for(int hero = 0; hero < amt_cases; hero++){
        CourtCase* tmp = new CourtCase();
        try {
            in >> tmp;
        } catch(FormatException& a){
            throw a;
        }
        cases[hero] = tmp;
    }
}

