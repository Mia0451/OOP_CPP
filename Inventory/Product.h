//
// Created by shiwe on 10/22/2023.
//

#ifndef CS2B_ASSIGNMENT2_PRODUCT_H
#define CS2B_ASSIGNMENT2_PRODUCT_H

#include "InventoryItem.h"

class Product : public InventoryItem {
private:
    string name;
    int quantity;
    double price;

public:
    static const string DEFAULT_NAME;
    static const int DEFAULT_QUANTITY;
    static const double DEFAULT_PRICE;

    // constructors and destructor
    Product();
    Product(int id, bool restocking, const string &prod_name, int prod_quantity, double prod_price);
    ~Product();

    // setter and getter
    void set_name(const string &prod_name);

    string get_name() const;

    void set_quantity(int prod_quantity);

    int get_quantity() const;

    void set_price(double prod_price);

    double get_price() const;

    // behavior functions
    void Display() const;
    double Cost(int buy_num) const;
};

#endif //CS2B_ASSIGNMENT2_PRODUCT_H
