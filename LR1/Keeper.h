//
// Created by Павел Жуков on 17/10/2021.
//

#ifndef LR1_KEEPER_H
#define LR1_KEEPER_H

#include "Monster.h"
#include "Villain.h"
#include "Hero.h"
#include "CourtCase.h"
#include "useful.h"

class Keeper {
    static Keeper* instance;
    int amt_officers;
    Hero* officers;
    int amt_villains;
    Villain* villains;
    int amt_monsters;
    Monster* monsters;
    int amt_cases;
    CourtCase* cases;
    Keeper();
public:
    static Keeper* getInstance();
    ~Keeper();

    void CreateOfficer();
    void CreateVillain();
    void CreateMonster();
    void CreateCase();

    void DeleteOfficer();
    void DeleteVillain();
    void DeleteMonster();
    void DeleteCase();

    void PrintAvailableCases();
    void PrintAvailableMonsters();
    void PrintAvailableVillains();
    void PrintAvailableOfficers();

    void PrintCase();
    void PrintMonster();
    void PrintVillain();
    void PrintOfficer();

    void EditOfficer();
    void EditVillain();
    void EditMonster();
    void EditCase();

    std::string getStringForFile();

    friend std::ofstream& operator<<(std::ofstream& stream, Keeper& a);
    friend std::ostream& operator<<(std::ostream& stream, Keeper& a);
};


#endif //LR1_KEEPER_H
