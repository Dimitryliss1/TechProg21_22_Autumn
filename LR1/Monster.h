//
// Created by Павел Жуков on 17/10/2021.
//

#ifndef LR1_MONSTER_H
#define LR1_MONSTER_H

#include <iostream>
#ifndef LR1_BASE_H
#include "Base.h"
#endif

class Monster: public Base {
    std::string name;
    std::string description;
public:
    void printParams(std::ostream& out) override;
    Monster();
    Monster(std::string& name, std::string& description);
    Monster(const Monster& src);
    ~Monster();
    const std::string &getName() const;
    void setName(const std::string &name);
    const std::string &getDescription() const;
    void setDescription(const std::string &description);
    bool operator==(const Monster &rhs) const;
    std::string getInfoForFile() override;
    std::string getNormalName()
};


#endif //LR1_MONSTER_H
