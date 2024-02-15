//
// Created by shiwe on 11/15/2023.
//

#include "ContactList.h"
#include "EmployeeContact.h"
#include "ContractorContact.h"

using namespace std;

ContactList::ContactList() : head(nullptr) {}

ContactList::~ContactList() {
    // Delete all nodes in the linked list.
    while (head != nullptr) {
        Contact *p_contact = head;
        head = head->get_next();
        delete p_contact;
    }
}

void ContactList::Init() {
    // Example of adding contacts
    Insert(
            new EmployeeContact(
                    "James",
                    "West",
                    "1-408-790-8251",
                    "jamesw@tpcommunications.com",
                    41,
                    "Marketing Analyst",
                    "Marketing"
            )
    );
    Insert(
            new ContractorContact(
                    "Cindy",
                    "Lincoln",
                    "1-408-790-7372",
                    "cindyl@tpcommunications.com",
                    9,
                    "TK Consultings",
                    6
            )
    );
    Insert(
            new EmployeeContact(
                    "David",
                    "Summer",
                    "1-408-790-1682",
                    "davids@tpcommuniations",
                    24,
                    "Software Engineer",
                    "IT"
            )
    );
    Insert(
            new EmployeeContact(
                    "Jennifer",
                    "Hans",
                    "1-408-790-2381",
                    "jenniferh@tpcommuniations",
                    17,
                    "HR Representative",
                    "Human Resources"
            )
    );
    Insert(
            new ContractorContact(
                    "Cindy",
                    "Morgan",
                    "1-408-790-3953",
                    "cindym@tpcommuniations",
                    43,
                    "TK Consultings",
                    12
            )
    );
    Insert(
            new EmployeeContact(
                    "Bob",
                    "West",
                    "1-448-078-8251",
                    "bobw@tpcommunications.com",
                    20,
                    "Mechanical Engineer",
                    "Engineering"
            )
    );
    Insert(
            new ContractorContact(
                    "Kate",
                    "Marsan",
                    "1-308-760-1072",
                    "katem@tpcommunications.com",
                    10,
                    "TK Consultings",
                    6
            )
    );
    Insert(
            new EmployeeContact(
                    "Joyce",
                    "Li",
                    "1-408-790-1682",
                    "joyce.li@tpcommuniations",
                    89,
                    "Product Support Engineer",
                    "Sales"
            )
    );
    Insert(
            new EmployeeContact(
                    "Emma",
                    "Bruce",
                    "1-101-708-1381",
                    "emma.b@tpcommuniations",
                    57,
                    "HR Representative",
                    "Human Resources"
            )
    );
    Insert(
            new ContractorContact(
                    "Jensen",
                    "James",
                    "1-891-930-9553",
                    "jensen@tpcommuniations",
                    43,
                    "TK Consultings",
                    12
            )
    );
    Insert(
            new EmployeeContact(
                    "Thomas",
                    "Yang",
                    "1-481-001-8531",
                    "thmoas.yang@tpcommunications.com",
                    23,
                    "Admin Assistant",
                    "Finance"
            )
    );
    Insert(
            new ContractorContact(
                    "Edward",
                    "Lincoln",
                    "1-098-790-1372",
                    "edward@tpcommunications.com",
                    12,
                    "TK Consultings",
                    6
            )
    );
    Insert(
            new EmployeeContact(
                    "Christopher",
                    "RJ",
                    "1-108-950-6862",
                    "christopher@tpcommuniations",
                    23,
                    "Hardware Engineer",
                    "IT"
            )
    );
    Insert(
            new EmployeeContact(
                    "Daniel",
                    "Hans",
                    "1-468-720-5381",
                    "daniel.h@tpcommuniations",
                    17,
                    "Business Analyst",
                    "Finance"
            )
    );
    Insert(
            new ContractorContact(
                    "Paul",
                    "K",
                    "1-348-590-1953",
                    "paul.k@tpcommuniations",
                    43,
                    "TK Consultings",
                    10
            )
    );
    Insert(
            new EmployeeContact(
                    "Jeffrey",
                    "Dai",
                    "1-476-171-9251",
                    "j.dai@tpcommunications.com",
                    25,
                    "HR Representative",
                    "Customer Support"
            )
    );
    Insert(
            new ContractorContact(
                    "William",
                    "Marsan",
                    "1-908-650-1672",
                    "william@tpcommunications.com",
                    45,
                    "TK Consultings",
                    6
            )
    );
    Insert(
            new EmployeeContact(
                    "George",
                    "Hua",
                    "1-408-790-1682",
                    "george.hua@tpcommuniations",
                    37,
                    "Product Support Engineer",
                    "Manufacturer"
            )
    );
    Insert(
            new EmployeeContact(
                    "Donald",
                    "Michael",
                    "1-101-708-1381",
                    "donald.m@tpcommuniations",
                    67,
                    "HR Representative",
                    "Customer Support"
            )
    );
    Insert(
            new ContractorContact(
                    "Richard",
                    "Jeff",
                    "1-891-930-9553",
                    "richard.jeff@tpcommuniations",
                    78,
                    "TK Consultings",
                    12
            )
    );
}

// display all contacts
void ContactList::ShowAllContacts() const {
    Contact *p_contact = head;
    while (p_contact != nullptr) {
        p_contact->ShowContact();
        p_contact = p_contact->get_next();
    }
}

void ContactList::SearchByName(const Name &target) const {
    Contact *p_found = FindContact(target);
    if (p_found != nullptr) {
        p_found->ShowContact();
    } else {
        cout << target << " not found!!!" << endl;
    }
}

bool ContactList::RemoveByName(const Name &target) {
    if (head == nullptr) {
        return false;
    }

    if (head->get_name() == target) {
        Contact* p_temp = head;
        head = head->get_next();
        delete p_temp; // delete the contact
        return true;
    }

    Contact *p_contact = head;
    while (p_contact->get_next() != nullptr) {
        Contact* p_node = p_contact->get_next();
        if (p_node->get_name() == target) {
            p_contact->set_next(p_node->get_next());
            delete p_node;
            return true;
        }
        p_contact = p_contact->get_next();
    }

    return false;
}

// search for employees in a specified department
void ContactList::SearchByDepartment(const std::string &department) const {
    bool found = false; // indicate whether there are employees in the specified department
    Contact *p_contact = head;
    while (p_contact != nullptr) {
        EmployeeContact *p_employee_contact = dynamic_cast<EmployeeContact *>(p_contact);
        if (p_employee_contact != nullptr && p_employee_contact->get_department() == department) {
            p_employee_contact->ShowContact();
            found = true;
        }
        p_contact = p_contact->get_next();
    }
    if (!found) {
        cout << "No employee in " << department << endl;
    }
}

// search for a contact by name
Contact *ContactList::FindContact(const Name &target) const {
    Contact *p_contact = head;
    while (p_contact != nullptr) {
        if (p_contact->get_name() == target) {
            return p_contact;
        }
        p_contact = p_contact->get_next();
    }
    return nullptr;
}

// insert a Contact object at head
void ContactList::Insert(Contact *p_contact) {
    p_contact->set_next(head);
    head = p_contact;
}

