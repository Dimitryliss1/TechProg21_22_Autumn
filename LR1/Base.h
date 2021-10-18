//
// Created by Павел Жуков on 06/10/2021.
//

#ifndef LR1_BASE_H
#define LR1_BASE_H

#include <iostream>

class Base {
    std::string type;
public:
    virtual void printParams() = 0;
    virtual ~Base();
    Base();
    explicit Base(std::string newType);
    Base(const Base& character);
    std::string getType() const;
    virtual std::string getInfoForFile() = 0;
};


#endif //LR1_BASE_H
