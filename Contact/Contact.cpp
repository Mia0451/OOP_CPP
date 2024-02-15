//
// Created by shiwe on 11/15/2023.
//

#include <string>
#include "Name.h"
#include "Contact.h"

using namespace std;

const string Contact::DEFAULT_PHONE = "1-408-222-8888";
const string Contact::DEFAULT_EMAIL = "jamesw@tpcommunications.com";
const int Contact::DEFAULT_LOCATION = 4;

Contact::Contact()
        : name(Name()),
          business_phone(Contact::DEFAULT_PHONE),
          email(Contact::DEFAULT_EMAIL),
          location(Contact::DEFAULT_LOCATION),
          next(nullptr) {}

Contact::Contact(
        const string &first_name,
        const string &last_name,
        const string &phone_arg,
        const string &email_arg,
        int location_arg)
        : name(Name(first_name, last_name)),
          business_phone(phone_arg),
          email(email_arg),
          location(location_arg),
          next(nullptr) {}

Contact::~Contact() {
    cout << name << " has gone home..." << endl;
}

// getter and setter
const Name &Contact::get_name() const {
    return name;
}

void Contact::set_name(const Name &name) {
    this->name = name;
}

const string &Contact::get_business_phone() const {
    return business_phone;
}

void Contact::set_business_phone(const string &business_phone) {
    this->business_phone = business_phone;
}

const string &Contact::get_email() const {
    return email;
}

void Contact::set_email(const string &email) {
    this->email = email;
}

int Contact::get_location() const {
    return location;
}

void Contact::set_location(int location) {
    this->location = location;
}

Contact *Contact::get_next() const {
    return next;
}

void Contact::set_next(Contact *p_next) {
    this->next = p_next;
}


