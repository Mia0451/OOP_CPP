#include "InventorySystem.h"
using namespace std;

// A simple menu for discontinuing product
// create a menu for all behaviors together?
void Menu() {
    cout << "Want to discontinue product?" << endl;
    cout << "==============================" << endl;
    cout << " 1. yes" << endl;
    cout << " 2. no" << endl;
    cout << "==============================" << endl;
}

int main() {

    InventorySystem* p_inventory = nullptr;

    p_inventory = new  InventorySystem("Wenyi's Store");
    p_inventory->BuildInventory();
    p_inventory->ShowInventory();
    p_inventory->UpdateInventory();

    Menu();
    int choice;
    do {
        cout << "Enter your choice: " << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                p_inventory->Discontinue();  // Example discontinue a product
                break;
            case 2:
                break;
            default:
                Menu();
        }
    } while (choice != 2);

    p_inventory->Terminate();

    delete p_inventory;

    return 0;
}

