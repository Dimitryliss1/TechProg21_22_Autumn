//
// Created by Павел Жуков on 09/10/2021.
//

#include "Product.h"

std::string to_lower(std::string src){
    for (char & i : src){
        i = tolower(i);
    }
    return src;
}

unsigned int Product::getProductPrice() const {
    return productPrice;
}

void Product::setProductPrice(unsigned int newPrice) {
    Product::productPrice = newPrice;
}

const std::string &Product::getProductName() const {
    return productName;
}

void Product::setProductName(const std::string &newName) {
    Product::productName = newName;
}

Product::Product(): productPrice(0), productName("null") {}

Product::Product(unsigned int newPrice, std::string &newName): productPrice(newPrice),
                                                               productName(newName){}

bool Product::operator==(const Product &rhs) const {
    return productPrice == rhs.productPrice &&
           productName == rhs.productName;
}
