//
// Created by shiwe on 11/15/2023.
//

#include <iomanip>
#include "EmployeeContact.h"

using namespace std;

const string EmployeeContact::DEFAULT_TITLE = "Software Engineer";
const string EmployeeContact::DEFAULT_DEPARTMENT = "Engineering";

EmployeeContact::EmployeeContact()
        : Contact(),
          title(EmployeeContact::DEFAULT_TITLE),
          department(EmployeeContact::DEFAULT_DEPARTMENT) {}

EmployeeContact::EmployeeContact(
        const string &first_name,
        const string &last_name,
        const string &phone,
        const string &email_arg,
        int location_arg,
        const string &title_arg,
        const string &department_arg)
        : Contact(first_name, last_name, phone, email_arg, location_arg),
          title(title_arg),
          department(department_arg) {}

EmployeeContact::~EmployeeContact() {}

void EmployeeContact::ShowContact() const {
    // in order to print nicely
    ostringstream ss;
    ss << "Room " << location;

    cout << left << setw(18) << name << setw(26) << title << setw(17) << department
         << setw(10) << ss.str() << setw(16) << business_phone << setw(25) << email << endl;
}

// getter and setter
const string &EmployeeContact::get_title() const {
    return title;
}

void EmployeeContact::set_title(const string &title) {
    this->title = title;
}

const string &EmployeeContact::get_department() const {
    return department;
}

void EmployeeContact::set_department(const string &department) {
    this->department = department;
}
