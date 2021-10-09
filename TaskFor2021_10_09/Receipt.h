//
// Created by Павел Жуков on 09/10/2021.
//

#ifndef TASKFOR2021_10_09_RECEIPT_H
#define TASKFOR2021_10_09_RECEIPT_H

#ifndef TASKFOR2021_10_09_PURCHASE_H
#include "Purchase.h"
#endif

#include <iostream>

//#ifndef TASKFOR2021_10_09_PRODUCT_H
//#include "Product.h"
//#endif

#ifndef TASKFOR2021_10_09_EXC_H
#include "exc.h"
#endif

class Receipt: public Purchase{
public:
    Receipt();
    ~Receipt() override;
    void printPurchase() override;
    bool isEmpty();
};


#endif //TASKFOR2021_10_09_RECEIPT_H
