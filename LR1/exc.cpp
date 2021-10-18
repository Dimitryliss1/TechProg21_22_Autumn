//
// Created by Павел Жуков on 18/10/2021.
//

#include "exc.h"

EmptyListException::EmptyListException(const std::string &error): m_error(error) {}

const char *EmptyListException::what() const noexcept{
    return m_error.c_str();
}
