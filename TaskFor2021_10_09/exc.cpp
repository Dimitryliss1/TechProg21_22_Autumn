//
// Created by Павел Жуков on 09/10/2021.
//

#include "exc.h"

NotFoundInListException::NotFoundInListException(const std::string& error): m_error(error) {}

const char *NotFoundInListException::what() const noexcept {
    return m_error.c_str();
}
