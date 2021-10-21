//
// Created by Павел Жуков on 18/10/2021.
//

#ifndef LR1_EXC_H
#define LR1_EXC_H


#include <iostream>


class EmptyListException: public std::exception
{
private:
    std::string m_error;

public:
    explicit EmptyListException(const std::string& error);
    const char* what() const noexcept;
};

class FormatException: public std::exception
{
private:
    std::string m_error;

public:
    explicit FormatException(const std::string& error);
    const char* what() const noexcept;
};

#endif //LR1_EXC_H
