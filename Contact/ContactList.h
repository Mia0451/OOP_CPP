//
// Created by shiwe on 11/15/2023.
//

#ifndef CS2B_ASSIGNMENT3_CONTACTLIST_H
#define CS2B_ASSIGNMENT3_CONTACTLIST_H

#include "Contact.h"

using namespace std;

class ContactList {

private:
    Contact *head;

public:
    ContactList();

    ~ContactList();

    void Init();

    // display all contacts
    void ShowAllContacts() const;

    // search for employees in a specified department
    void SearchByDepartment(const string &department) const;

    void SearchByName(const Name &target) const;

    // Remove the contact by the name.
    // Return true means delete successfully; otherwise false
    bool RemoveByName(const Name &target);

    // no setter or getter.
private:
    // search for a contact by target
    Contact *FindContact(const Name &target) const;

    // insert a Contact object at head
    void Insert(Contact *p_contact);

};

#endif //CS2B_ASSIGNMENT3_CONTACTLIST_H
