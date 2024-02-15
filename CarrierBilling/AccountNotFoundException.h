//
// Created by shiwe on 11/28/2023.
//

#ifndef CS2B_ASSIGNMENT4_ACCOUNTNOTFOUNDEXCEPTION_H
#define CS2B_ASSIGNMENT4_ACCOUNTNOTFOUNDEXCEPTION_H


#include <stdexcept>
#include <string>

using namespace std;

class AccountNotFoundException : public std::exception {
private:
    string phone_number;
    string msg; // I have to use this otherwise temporary string in what()
    // will be out of scope?

public:
    AccountNotFoundException(const string &number);

    const char *what() const noexcept override;
};


#endif //CS2B_ASSIGNMENT4_ACCOUNTNOTFOUNDEXCEPTION_H
