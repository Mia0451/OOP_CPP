//
// Created by shiwe on 10/22/2023.
//

#include "InventorySystem.h"
#include "Product.h"

const int InventorySystem::ARRAY_SIZE = 512;
const string InventorySystem::DEFAULT_STORE_NAME = "My Store";
const int InventorySystem::DEFAULT_PRODUCT_COUNT = 0;
const string InventorySystem::DEFAULT_INPUT_FILE_NAME = "input.txt";
const string InventorySystem::DEFAULT_OUTPUT_FILE_NAME = "output.txt";

InventorySystem::InventorySystem()
        : store_name(InventorySystem::DEFAULT_STORE_NAME), product_count(InventorySystem::DEFAULT_PRODUCT_COUNT) {
    product_list = new InventoryItem*[InventorySystem::ARRAY_SIZE];
    for (auto i = 0; i < InventorySystem::ARRAY_SIZE; ++i) {
        product_list[i] = nullptr;
    }
}

InventorySystem::InventorySystem(const string &name)
        : store_name(name), product_count(InventorySystem::DEFAULT_PRODUCT_COUNT) {
    product_list = new InventoryItem*[InventorySystem::ARRAY_SIZE];
    for (auto i = 0; i < InventorySystem::ARRAY_SIZE; ++i) {
        product_list[i] = nullptr;
    }
}

InventorySystem::~InventorySystem() {
    for (auto i = 0; i < product_count; ++i) {
        Product* p_product = static_cast<Product*>(product_list[i]);
        delete p_product;
    }
    // also delete the array.
    delete[] product_list;
}

void InventorySystem::BuildInventory() {
    product_count = 0; // reset to 0
    ifstream input_file(InventorySystem::DEFAULT_INPUT_FILE_NAME);

    if (!input_file) {
        cout << "ERROR!!! Cannot open file: " << InventorySystem::DEFAULT_INPUT_FILE_NAME << endl;
        return;
    }

    string line;
    while (getline(input_file, line)) {
        // now parse each line with the corresponding data for one product
        int first_semi_colon = line.find(';');
        int id = stoi(line.substr(0, first_semi_colon));

        int second_semi_colon = line.find(';', first_semi_colon + 1);
        string name = line.substr(first_semi_colon + 1, second_semi_colon - first_semi_colon - 1);

        int third_semi_colon = line.find(';', second_semi_colon + 1);
        int quantity = stoi(line.substr(second_semi_colon + 1, third_semi_colon - second_semi_colon - 1));

        double price = stod(line.substr(third_semi_colon + 1));

        product_list[product_count] = new Product(id, (quantity == 0), name, quantity, price);
        if (quantity == 0) {
            product_list[product_count]->set_restocking(true);
        }

        product_count++;
    }

    input_file.close();
}

void InventorySystem::ShowInventory() const {
    cout << "============================================================" << endl;
    cout << "===============         " << store_name << "         ==============" << endl;
    cout << "============================================================" << endl;
    for (auto i = 0; i < product_count; ++i) {
        Product* p_product = static_cast<Product*>(product_list[i]);
        p_product->Display();
    }
    cout << "============================================================" << endl;
    cout << "============================================================" << endl;
}

void InventorySystem::UpdateInventory() {
    int id;
    int num;
    cout << "Please input the item id of the product you want to update: " << endl;
    cin >> id;
    cout << "Please input the quantity to deduct: " << endl;
    cin >> num;
    if (num <= 0) {
        cout << "ERROR!!! Quantity to deduct must be positive number" << endl;
        return;
    }

    InventoryItem* p_inventory_item = FindInventoryItem(id);
    if (p_inventory_item != nullptr) {
        Product* p_product = static_cast<Product*>(p_inventory_item);
        int current_count = p_product->get_quantity();

        if (num > current_count) {
            cout << "ERROR!!! Product #" << id << " only has " << current_count << " count" << endl;
            return;
        }

        double total_cost = p_product->Cost(num);
        cout << "Total cost for buying " << num << " " << p_product->get_name() << " is $" << total_cost << endl;

        p_product->set_quantity(current_count - num);

        if (current_count - num == 0) {
            p_product->set_restocking(true);
            cout << "WARNING!!! " << p_product->get_name() << " is out of stock, please restock" << endl;
        }
    } else {
        cout << "ERROR!!! Product #" << setw(4) << setfill('0') << id << " not found." << endl;
    }
}

void InventorySystem::Terminate() {
    ofstream output_file(InventorySystem::DEFAULT_OUTPUT_FILE_NAME);

    for (auto i = 0; i < product_count; ++i) {
        Product* p_product = static_cast<Product*>(product_list[i]);
        output_file << p_product->get_item_id() << ";" << p_product->get_name() << ";"
        << p_product->get_quantity() << ";" << p_product->get_price() << endl;
    }

    output_file.close();
}

void InventorySystem::Discontinue() {
    int id;
    cout << "Please input the item id of the product you want to discontinue: " << endl;
    cin >> id;

    InventoryItem *p_inventory_item = FindInventoryItem(id);
    if (p_inventory_item != nullptr) {

        int target_index = -1;
        for (auto i = 0; i < product_count; i++) {
            if (product_list[i] == p_inventory_item) {
                // found the product
                target_index = i;
                break;
            }
        }

        if (target_index != -1) {
            Product* p_product = static_cast<Product*>(p_inventory_item);
            delete p_product;
            product_list[target_index] = nullptr;

            for (auto i = target_index + 1; i < product_count; i++) {
                product_list[i - 1] = product_list[i]; // move forward
            }

            product_list[product_count - 1] = nullptr; // set the last to null
            product_count--;
        }
    } else {
        cout << "ERROR!!! Product with ID " << setw(4) << setfill('0') << id << " not found" << endl;
    }
}

string InventorySystem::get_store_name() const {
    return store_name;
}

void InventorySystem::set_store_name(const string &name) {
    store_name = name;
}

// Only getter for product_count
int InventorySystem::get_product_count() const {
    return product_count;
}

InventoryItem *InventorySystem::FindInventoryItem(int item_id) {
    for (auto i = 0; i < product_count; ++i) {
        if (product_list[i]->get_item_id() == item_id) {
            return product_list[i];
        }
    }
    return nullptr;
}

