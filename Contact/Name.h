//
// Created by shiwe on 11/15/2023.
//

#ifndef CS2B_ASSIGNMENT3_NAME_H
#define CS2B_ASSIGNMENT3_NAME_H

#include <string>
#include <iostream>

using namespace std;

class Name {

private:
    string first_name;
    string last_name;

public:
    Name(); // default constructor

    Name(const string &first, const string &last);

    bool operator==(const Name &other) const;

    friend std::ostream &operator<<(ostream &os, const Name &name);

    // getter and setter
    const string &get_first_name() const;

    const string &get_last_name() const;

    void set_first_name(const string &first_name);

    void set_last_name(const string &last_name);

};

#endif //CS2B_ASSIGNMENT3_NAME_H
