//
// Created by shiwe on 10/22/2023.
//

#include "Product.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const string Product::DEFAULT_NAME = "No Product";
const int Product::DEFAULT_QUANTITY = 0;
const double Product::DEFAULT_PRICE = 0.99;

Product::Product() : InventoryItem(), name(Product::DEFAULT_NAME), quantity(Product::DEFAULT_QUANTITY), price(Product::DEFAULT_PRICE) {}

Product::Product(int id, bool restocking, const string &prod_name, int prod_quantity, double prod_price)
        : InventoryItem(id, restocking), name(prod_name), quantity(prod_quantity), price(prod_price) {}

Product::~Product() {
    cout << "Product: " << setw(4) << setfill('0') << item_id << ", Name: " << name << ", quantity: " << quantity
    << ", price: " << fixed << setprecision(2) << price
    << ", restocking<" << (restocking ? "true" : "false") << "> destroyed ..." << endl;
}

void Product::set_name(const string &prod_name) {
    name = prod_name;
}

string Product::get_name() const {
    return name;
}

void Product::set_quantity(int prod_quantity) {
    quantity = prod_quantity;
}

int Product::get_quantity() const {
    return quantity;
}

void Product::set_price(double prod_price) {
    price = prod_price;
}

double Product::get_price() const {
    return price;
}

double Product::Cost(int buy_num) const {
    return price * buy_num;
}

void Product::Display() const {
    InventoryItem::Display();
    if (restocking) {
        cout << "*****";
    }
    cout << "Name: " << name << "; Quantity: " << quantity
    << "; Price: $" << fixed << setprecision(2) << price << endl;
}
