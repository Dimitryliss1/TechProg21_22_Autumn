//
// Created by Павел Жуков on 06/10/2021.
//

#ifndef LR1_CHARACTERS_H
#define LR1_CHARACTERS_H

#include <iostream>

class Characters {
    std::string type;
public:
    virtual void printParams(std::ostream &out) = 0;
    virtual ~Characters();
    Characters();
    explicit Characters(std::string newType);
    Characters(const Characters& character);
    std::string getType();
};


#endif //LR1_CHARACTERS_H
