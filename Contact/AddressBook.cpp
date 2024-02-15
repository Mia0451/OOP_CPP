//
// Created by shiwe on 11/15/2023.
//

#include "AddressBook.h"
#include "EmployeeContact.h"

using namespace std;

const string AddressBook::DEFAULT_COMPANY_NAME = "TP Communications";

AddressBook::AddressBook() : company_name(AddressBook::DEFAULT_COMPANY_NAME) {}

AddressBook::AddressBook(const string &company_arg) : company_name(company_arg) {}

AddressBook::~AddressBook() {}

void AddressBook::Init() {
    contact_list.Init();
}

void AddressBook::Run() {
    int option = 0;
    do {
        Menu();
        option = GetUserOption();

        switch (option) {
            case 1:
                ShowAllContacts();
                break;
            case 2:
                SearchByName();
                break;
            case 3:
                SearchByDepartment();
                break;
            case 4:
                RemoveContactByName();
                break;
            case 5:
                Quit();
                break;
            default:
                break;
        }
    } while (option != 5);
}

void AddressBook::Menu() const {
    cout << "==================================================" << endl;
    cout << "==================================================" << endl;
    cout << company_name << " Address Book Menu" << endl;
    cout << "1. View all contacts" << endl;
    cout << "2. Search by name" << endl;
    cout << "3. Search by department" << endl;
    cout << "4. Remove contact by name" << endl;
    cout << "5. Quit" << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
}

int AddressBook::GetUserOption() const {
    int option = 0;
    cout << "Select an option (1-5):" << endl;
    cin >> option;
    return option;
}

void AddressBook::ShowAllContacts() const {
    contact_list.ShowAllContacts();
}

void AddressBook::SearchByName() const {
    string first_name, last_name;
    cout << "Enter a contact first name:" << endl;
    cin >> first_name;
    cout << "Enter a contact last name:" << endl;
    cin >> last_name;

    contact_list.SearchByName(Name(first_name, last_name));
}

void AddressBook::SearchByDepartment() const {
    string department = "";
    cout << "Enter a department:" << endl;
    cin.ignore();
    getline(std::cin, department);
    contact_list.SearchByDepartment(department);
}

void AddressBook::RemoveContactByName() {
    string first_name, last_name;
    cout << "Enter first name of the to be deleted contact:" << endl;
    cin >> first_name;
    cout << "Enter last name of the to be deleted contact:" << endl;
    cin >> last_name;

    bool successful = contact_list.RemoveByName(Name(first_name, last_name));
    if (successful) {
        cout << "Contact removed successfully." << endl;
    } else {
        cout << "Contact doesn't exist!!!" << endl;
    }
}

void AddressBook::Quit() const {
    cout << "Thanks for using our AddressBook. See you again!" << endl;
}


