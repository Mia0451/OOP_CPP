//
// Created by shiwe on 11/15/2023.
//

#include <sstream>
#include "Name.h"

using namespace std;

// default constructor initialize first name, last name to empty string
Name::Name() : first_name(""), last_name("") {}

Name::Name(const string &first, const string &last) : first_name(first), last_name(last) {}

bool Name::operator==(const Name &other) const {
    return (first_name == other.first_name) && (last_name == other.last_name);
}

// getter and setter
const string &Name::get_first_name() const {
    return first_name;
}

const string &Name::get_last_name() const {
    return last_name;
}

void Name::set_first_name(const string &first_name) {
    this->first_name = first_name;
}

void Name::set_last_name(const string &last_name) {
    this->last_name = last_name;
}

ostream &operator<<(std::ostream &os, const Name &name) {
    // in order to print first name and last name nicely.
    ostringstream ss;
    ss << name.first_name << " " << name.last_name;
    os << ss.str();
    return os;
}

