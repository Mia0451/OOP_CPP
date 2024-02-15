//
// Created by shiwe on 11/15/2023.
//

#ifndef CS2B_ASSIGNMENT3_EMPLOYEECONTACT_H
#define CS2B_ASSIGNMENT3_EMPLOYEECONTACT_H

#include <string>
#include "Contact.h"

using namespace std;

class EmployeeContact : public Contact {

private:
    string title;
    string department;

public:
    static const string DEFAULT_TITLE;
    static const string DEFAULT_DEPARTMENT;

    EmployeeContact();

    EmployeeContact(
            const string &first_name,
            const string &last_name,
            const string &phone,
            const string &email,
            int location,
            const string &title,
            const string &department);

    virtual ~EmployeeContact();

    virtual void ShowContact() const;

    // getter and setter
    const string &get_title() const;

    void set_title(const string &title);

    const string &get_department() const;

    void set_department(const string &department);

};

#endif //CS2B_ASSIGNMENT3_EMPLOYEECONTACT_H
