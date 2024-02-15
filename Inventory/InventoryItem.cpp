//
// Created by shiwe on 10/22/2023.
//
#include <iostream>
#include <iomanip>
#include "InventoryItem.h"

using namespace std;

const int InventoryItem::DEFAULT_ITEM_ID = 9999;
const bool InventoryItem::DEFAULT_RESTOCKING = false;

InventoryItem::InventoryItem() : item_id(InventoryItem::DEFAULT_ITEM_ID), restocking(InventoryItem::DEFAULT_RESTOCKING) {}

InventoryItem::InventoryItem(int id, bool restock) : item_id(id), restocking(restock) {}

InventoryItem::~InventoryItem() {
    cout << "InventoryItem " << setw(4) << setfill('0') << item_id
         << " with " << (restocking ? "true" : "false") << " restocking destroyed ..." << endl;
}

// setter and getter
void InventoryItem::set_item_id(int id) {
    item_id = id;
}

int InventoryItem::get_item_id() const {
    return item_id;
}

void InventoryItem::set_restocking(bool restock) {
    restocking = restock;
}

bool InventoryItem::get_restocking() const {
    return restocking;
}

void InventoryItem::Display() const {
    cout << "InventoryItem " << setw(4) << setfill('0') << item_id << " with "
         << (restocking ? "true" : "false") << " restocking" << endl;
}