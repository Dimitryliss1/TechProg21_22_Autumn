//
// Created by Павел Жуков on 09/10/2021.
//

#ifndef TASKFOR2021_10_09_PRODUCT_H
#define TASKFOR2021_10_09_PRODUCT_H

#include <iostream>

std::string to_lower(std::string src);

class Product {
    unsigned int productID;
    unsigned int productPrice;
    std::string productName;
public:
    Product();
    Product(unsigned int newID, unsigned int newPrice, std::string& newName);
    unsigned int getProductId() const;
    void setProductId(unsigned int productId);
    unsigned int getProductPrice() const;
    void setProductPrice(unsigned int productPrice);
    const std::string &getProductName() const;
    void setProductName(const std::string &productName);
    bool operator==(const Product &rhs) const;
};


#endif //TASKFOR2021_10_09_PRODUCT_H
