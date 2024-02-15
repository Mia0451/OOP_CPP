//
// Created by shiwe on 10/22/2023.
//

#ifndef CS2B_ASSIGNMENT2_INVENTORYSYSTEM_H
#define CS2B_ASSIGNMENT2_INVENTORYSYSTEM_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include "InventoryItem.h"
using namespace std;

// An inventory management system
class InventorySystem {
public:
    static const int ARRAY_SIZE;
    static const string DEFAULT_STORE_NAME;
    static const int DEFAULT_PRODUCT_COUNT;
    static const string DEFAULT_INPUT_FILE_NAME;
    static const string DEFAULT_OUTPUT_FILE_NAME;

    // constructors and destructor
    InventorySystem();

    InventorySystem(const string &name);

    ~InventorySystem();

    // setter and getter
    string get_store_name() const;
    void set_store_name(const string &name);
    // only getter for product_count
    int get_product_count() const;

    // behavior functions
    // build the inventory system with reading from file
    void BuildInventory();
    // Show all products information in the inventory
    void ShowInventory() const;
    // Update product information in the inventory
    void UpdateInventory();
    // Write all product information to file
    void Terminate();
    // Discontinue a product in the inventory
    void Discontinue();

private:
    string store_name;
    InventoryItem** product_list; // pointer to an array of pointers
    int product_count;

    // behavior functions
    InventoryItem *FindInventoryItem(int item_id);
};

#endif //CS2B_ASSIGNMENT2_INVENTORYSYSTEM_H
