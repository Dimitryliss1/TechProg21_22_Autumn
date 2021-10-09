//
// Created by Павел Жуков on 09/10/2021.
//

#ifndef TASKFOR2021_10_09_USEFUL_H
#define TASKFOR2021_10_09_USEFUL_H

#include <iostream>
#include <vector>

#ifndef TASKFOR2021_10_09_RECEIPT_H
#include "Receipt.h"
#endif

#ifndef TASKFOR2021_10_09_PRODUCT_H
#include "Product.h"
#endif

#include <algorithm>
#include <cctype>
#include <locale>

void ltrim(std::string &s);
void rtrim(std::string &s);
std::string trim(std::string s);

int safe_input();
std::string safe_input_str();

void printStatsForAllReceipts(const std::vector<Receipt>& receipts);

void printStatsForProduct(std::string name, const std::vector<Product>& available_prods, const std::vector<Receipt>& receipts);

#endif //TASKFOR2021_10_09_USEFUL_H
