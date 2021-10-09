//
// Created by Павел Жуков on 09/10/2021.
//

#ifndef TASKFOR2021_10_09_EXC_H
#define TASKFOR2021_10_09_EXC_H

#include <iostream>

class NotFoundInListException: public std::exception
{
private:
    std::string m_error;

public:
    explicit NotFoundInListException(const std::string& error);
    const char* what() const noexcept;
};


#endif //TASKFOR2021_10_09_EXC_H
