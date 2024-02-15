//
// Created by shiwe on 11/15/2023.
//
#include <iomanip>
#include "ContractorContact.h"

using namespace std;

const string ContractorContact::DEFAULT_COMPANY = "TK Consultings";
const int ContractorContact::DEFAULT_DURATION = 6;

ContractorContact::ContractorContact(
) : Contact(),
    company(ContractorContact::DEFAULT_COMPANY),
    assignment_duration(ContractorContact::DEFAULT_DURATION) {}

ContractorContact::ContractorContact(
        const string &first_name,
        const string &last_name,
        const string &phone,
        const string &email,
        int location,
        const string &company_arg,
        int duration
) : Contact(first_name, last_name, phone, email, location),
    company(company_arg),
    assignment_duration(duration) {}

ContractorContact::~ContractorContact() {}

void ContractorContact::ShowContact() const {
    // in order to print nicely.
    ostringstream ss;
    ss << assignment_duration << " months (contractor)";

    // in order to print nicely
    ostringstream ss1;
    ss1 << "Room " << location;

    cout << left << setw(18) << name << setw(26) << ss.str() << setw(17) << company
         << setw(10) << ss1.str() << setw(16) << business_phone << setw(25) << email << endl;
}

// getter and setter
const string &ContractorContact::get_company() const {
    return company;
}

void ContractorContact::set_company(const string &company) {
    this->company = company;
}

int ContractorContact::get_assignment_duration() const {
    return assignment_duration;
}

void ContractorContact::set_assignment_duration(int assignment_duration) {
    this->assignment_duration = assignment_duration;
}
