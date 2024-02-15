//
// Created by shiwe on 11/15/2023.
//

#ifndef CS2B_ASSIGNMENT3_ADDRESSBOOK_H
#define CS2B_ASSIGNMENT3_ADDRESSBOOK_H

#include <iostream>
#include <string>
#include "Contact.h"
#include "ContactList.h"

using namespace std;

class AddressBook {

private:
    string company_name;
    ContactList contact_list;

public:
    static const string DEFAULT_COMPANY_NAME;

    AddressBook();

    AddressBook(const string &company);

    ~AddressBook();

    void Init();

    void Run();

private:
    void Menu() const;

    int GetUserOption() const;

    void ShowAllContacts() const;

    void SearchByName() const;

    void SearchByDepartment() const;

    void RemoveContactByName();

    void Quit() const;

};

#endif //CS2B_ASSIGNMENT3_ADDRESSBOOK_H
