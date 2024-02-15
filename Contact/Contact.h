//
// Created by shiwe on 11/15/2023.
//

#ifndef CS2B_ASSIGNMENT3_CONTACT_H
#define CS2B_ASSIGNMENT3_CONTACT_H

#include <iostream>
#include <string>
#include "Name.h"

using namespace std;

class Contact {

private:
    Contact *next;

protected:
    Name name;
    string business_phone;
    string email;
    int location;

public:
    static const string DEFAULT_PHONE;
    static const string DEFAULT_EMAIL;
    static const int DEFAULT_LOCATION;

    Contact();

    Contact(const string &first_name,
            const string &last_name,
            const string &phone,
            const string &email,
            int location);

    virtual ~Contact();

    virtual void ShowContact() const = 0;

    // getter and setter
    const Name &get_name() const;

    void set_name(const Name &name);

    const string &get_business_phone() const;

    void set_business_phone(const string &business_phone);

    const string &get_email() const;

    void set_email(const string &email);

    int get_location() const;

    void set_location(int location);

    Contact *get_next() const;

    void set_next(Contact *p_next);

};

#endif //CS2B_ASSIGNMENT3_CONTACT_H
