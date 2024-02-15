//
// Created by shiwe on 10/22/2023.
//

#ifndef CS2B_ASSIGNMENT2_INVENTORYITEM_H
#define CS2B_ASSIGNMENT2_INVENTORYITEM_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

// InventoryItem class which is used for an inventory item
class InventoryItem {
protected:
    int item_id;
    bool restocking;

public:
    static const int DEFAULT_ITEM_ID;
    static const bool DEFAULT_RESTOCKING;

    // constructors and destructor
    InventoryItem();
    InventoryItem(int id, bool restock);
    ~InventoryItem();

    // setter and getter
    void set_item_id(int id);
    int get_item_id() const;
    void set_restocking(bool restock);
    bool get_restocking() const;

    // behavior functions
    void Display() const;
};

#endif //CS2B_ASSIGNMENT2_INVENTORYITEM_H
