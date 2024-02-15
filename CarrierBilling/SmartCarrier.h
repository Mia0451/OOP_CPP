//
// Created by shiwe on 11/28/2023.
//

#ifndef CS2B_ASSIGNMENT4_SMARTCARRIER_H
#define CS2B_ASSIGNMENT4_SMARTCARRIER_H


#include <map>
#include <vector>
#include <string>
#include "Message.h"
#include "AccountNotFoundException.h"
#include "Media.h"

using namespace std;

class SmartCarrier {
private:
    string carrier_name;
    bool init;
    map<string, vector<Message<Media> *>> account_list;

public:
    static const string DEFAULT_CARRIER_NAME;
    static const bool DEFAULT_INIT;

    SmartCarrier();

    SmartCarrier(const string &name);

    ~SmartCarrier();

    void Init();

    void StartService();

private:
    void Menu() const;

    int GetChoice() const;

    void ListAccounts() const;

    void InsertMessage();

    void PurgeLargeMessages();

    void DisconnectAccount();
};


#endif //CS2B_ASSIGNMENT4_SMARTCARRIER_H
