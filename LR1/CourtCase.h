//
// Created by Павел Жуков on 17/10/2021.
//

#ifndef LR1_COURTCASE_H
#define LR1_COURTCASE_H

#ifndef LR1_HERO_H
#include "Hero.h"
#endif

#ifndef LR1_VILLAIN_H
#include "Villain.h"
#endif

#ifndef LR1_MONSTER_H_H
#include "Monster.h"
#endif

#include <iostream>


struct Pair{
    Monster first;
    int second;
};

class CourtCase {
    Hero responsible;
    Villain criminal;
    Pair* monsters;
    int unique_monsters_amt;
    std::string title;
    std::string description;
public:
    CourtCase();
    CourtCase(CourtCase& src);
    const Hero &getResponsible() const;
    void setResponsible(const Hero &responsible);
    const Villain &getCriminal() const;
    void setCriminal(const Villain &criminal);
    int getMonstersAmt() const;
    const std::string &getTitle() const;
    void setTitle(const std::string &title);
    const std::string &getDescription() const;
    void setDescription(const std::string &description);
    void addMonster(const Monster& monster);
    void printInfo(std::ostream& out);
    std::string getInfoForFile();
};


#endif //LR1_COURTCASE_H
