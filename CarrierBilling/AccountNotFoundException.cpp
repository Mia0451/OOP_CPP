//
// Created by shiwe on 11/28/2023.
//
#include <iostream>
#include "AccountNotFoundException.h"
#include <string>

using namespace std;

AccountNotFoundException::AccountNotFoundException(const string &number)
        : phone_number(number), msg("Account " + phone_number + " does not exist!") {}

const char *AccountNotFoundException::what() const noexcept {
    // If I concatenate the message string here, there is an error, I resorted to
    // do concatenation in constructor.
    return msg.c_str();
}
