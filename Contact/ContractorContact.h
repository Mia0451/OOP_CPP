//
// Created by shiwe on 11/15/2023.
//

#ifndef CS2B_ASSIGNMENT3_CONTRACTORCONTACT_H
#define CS2B_ASSIGNMENT3_CONTRACTORCONTACT_H

#include <string>
#include "Contact.h"

using namespace std;

class ContractorContact : public Contact {

private:
    string company;
    int assignment_duration;

public:
    static const string DEFAULT_COMPANY;
    static const int DEFAULT_DURATION;

    ContractorContact();

    ContractorContact(
            const string &first_name,
            const string &last_name,
            const string &phone,
            const string &email,
            int location,
            const string &company,
            int duration);

    virtual ~ContractorContact();

    virtual void ShowContact() const;

    // getter and setter
    const string &get_company() const;

    void set_company(const string &company);

    int get_assignment_duration() const;

    void set_assignment_duration(int assignment_duration);

};

#endif //CS2B_ASSIGNMENT3_CONTRACTORCONTACT_H
