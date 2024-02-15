//
// Created by shiwe on 11/28/2023.
//

#include <iostream>
#include <iomanip>
#include "Media.h"
#include "Message.h"
#include "SmartCarrier.h"

using namespace std;

const string SmartCarrier::DEFAULT_CARRIER_NAME = "XYZ Wireless";
const bool SmartCarrier::DEFAULT_INIT = false;

SmartCarrier::SmartCarrier() : carrier_name(SmartCarrier::DEFAULT_CARRIER_NAME), init(SmartCarrier::DEFAULT_INIT) {}

SmartCarrier::SmartCarrier(const string &name) : carrier_name(name), init(SmartCarrier::DEFAULT_INIT) {}

SmartCarrier::~SmartCarrier() {
    for (map<string, vector<Message<Media> *>>::iterator ite = account_list.begin(); ite != account_list.end(); ++ite) {
        for (vector<Message<Media> *>::iterator message_ite = ite->second.begin();
             message_ite != ite->second.end(); ++message_ite) {
            Message<Media> *p_message = *message_ite;
            delete p_message;
        }
        ite->second.clear();
    }
    account_list.clear();
}

void SmartCarrier::Init() {
    // 1. To add an account without messages
    account_list["669-444-4444"];

    // 2. To add an account with only one message which is large message
    account_list["831-777-7777"].push_back(
            new Message<Media>("408-222-2222", Media(120.0)));

    // 3. To add an account with only one message which is small message.
    account_list["736-465-2836"].push_back(
            new Message<Media>("516-373-8484", Media(10.0)));

    // 4. To add an account with multiple messages.
    account_list["408-111-1111"].push_back(new Message<Media>("415-678-9011", Media(2.08)));
    account_list["408-111-1111"].push_back(new Message<Media>("408-555-8888", Media(875.35)));
    account_list["408-111-1111"].push_back(new Message<Media>("669-000-1234", Media(357.59)));

    // 5. To add an account with multiple messages, large at the beginning.
    account_list["983-183-1228"].push_back(new Message<Media>("415-678-9011", Media(123.08)));
    account_list["983-183-1228"].push_back(new Message<Media>("408-555-8888", Media(7.35)));
    account_list["983-183-1228"].push_back(new Message<Media>("669-000-1234", Media(37.59)));

    // 6. To add an account with multiple messages, large in the middle.
    account_list["847-847-4282"].push_back(new Message<Media>("415-678-9011", Media(6.28)));
    account_list["847-847-4282"].push_back(new Message<Media>("408-555-8888", Media(175.35)));
    account_list["847-847-4282"].push_back(new Message<Media>("669-000-1234", Media(38.25)));

    // 7. To add an account with multiple messages, large at end.
    account_list["746-264-0729"].push_back(new Message<Media>("415-678-9011", Media(13.11)));
    account_list["746-264-0729"].push_back(new Message<Media>("408-555-8888", Media(75.31)));
    account_list["746-264-0729"].push_back(new Message<Media>("669-000-1234", Media(837.09)));

    // 8. To add an account with multiple messages which are all large message.
    account_list["208-781-1761"].push_back(new Message<Media>("215-688-1011", Media(223.08)));
    account_list["208-781-1761"].push_back(new Message<Media>("208-525-8288", Media(575.35)));
    account_list["208-781-1761"].push_back(new Message<Media>("659-060-1274", Media(7767.62)));
    account_list["208-781-1761"].push_back(new Message<Media>("367-153-9483", Media(101.22)));

    // 9. To add an account with multiple messages and mixed.
    account_list["637-725-1753"].push_back(new Message<Media>("647-264-7249", Media(423.84)));
    account_list["637-725-1753"].push_back(new Message<Media>("142-849-2678", Media(34.63)));
    account_list["637-725-1753"].push_back(new Message<Media>("103-735-5849", Media(712.28)));
    account_list["637-725-1753"].push_back(new Message<Media>("164-856-3960", Media(39.91)));
    account_list["637-725-1753"].push_back(new Message<Media>("754-920-4658", Media(0.98)));
    account_list["637-725-1753"].push_back(new Message<Media>("635-284-6239", Media(1272.25)));


    // 10. To add an account with multiple messages which are all small size.
    account_list["578-342-1002"].push_back(new Message<Media>("437-468-1253", Media(23.84)));
    account_list["578-342-1002"].push_back(new Message<Media>("763-583-4557", Media(34.63)));
    account_list["578-342-1002"].push_back(new Message<Media>("038-284-2477", Media(3.91)));
    account_list["578-342-1002"].push_back(new Message<Media>("094-248-3535", Media(0.98)));
    account_list["578-342-1002"].push_back(new Message<Media>("136-146-2445", Media(72.25)));

    init = true;
}

void SmartCarrier::StartService() {
    if (!init) {
        cout << "System not initialized. Exiting..." << endl;
        return;
    }

    int choice = 0;
    do {
        Menu();
        choice = GetChoice();

        try {
            switch (choice) {
                case 1:
                    ListAccounts();
                    break;
                case 2:
                    InsertMessage();
                    break;
                case 3:
                    PurgeLargeMessages();
                    break;
                case 4:
                    DisconnectAccount();
                    break;
                case 5:
                    cout << "Thanks for using, Bye!" << endl;
                    break;
            }
        } catch (AccountNotFoundException &anfe) {
            cout << "Error: " << anfe.what() << endl;
        } catch (exception &e) {
            cout << "Error: " << e.what() << endl;
        }

    } while (choice != 5);
}

void SmartCarrier::Menu() const {
    cout << "======================================================" << endl;
    cout << "======================================================" << endl;
    cout << "                 " << carrier_name << endl;
    cout << "                  ACCOUNT ADMIN" << endl;
    cout << "1. List all accounts and their messages' usages\n"
         << "2. Add a message to an account\n"
         << "3. Purge large messages from an account\n"
         << "4. Disconnect an account\n"
         << "5. Quit\n";
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
}

int SmartCarrier::GetChoice() const {
    cout << "Enter your choice (1-5): " << endl;
    int choice = 0;
    cin >> choice;
    return choice;
}

void SmartCarrier::ListAccounts() const {
    cout << "Account\t\tMessages\tSize(MB)\tCharge\n";
    for (map<string, vector<Message<Media> *>>::const_iterator ite = account_list.begin();
         ite != account_list.end(); ++ite) {
        double total_size = 0.0;
        double total_charge = 0.0;
        cout << ite->first << "\t"; // phone number
        for (vector<Message<Media> *>::const_iterator message_ite = ite->second.begin();
             message_ite != ite->second.end(); ++message_ite) {
            total_size += (*message_ite)->get_data().get_size();
            total_charge += (*message_ite)->get_data().GetCharge();
        }
        cout << setw(4) << ite->second.size() << "\t\t" << setw(8) << fixed << setprecision(2) << total_size << setw(14)
             << fixed << setprecision(2) << total_charge << "\n";
    }
}

void SmartCarrier::InsertMessage() {
    string phone_number = "";
    cout << "Enter phone number: " << endl;
    cin.ignore();
    getline(std::cin, phone_number);

    map<string, vector<Message<Media> *>>::iterator ite = account_list.find(phone_number);
    if (ite == account_list.end()) {
        throw AccountNotFoundException(phone_number);
    }

    double media_size = 0.0;
    cout << "Enter media size (MB): " << endl;
    cin >> media_size;

    string to_number;
    cout << "Enter receiver's phone number: " << endl;
    cin.ignore();
    getline(std::cin, to_number);

    Message<Media> *media_message = new Message<Media>(to_number, Media(media_size));
    ite->second.push_back(media_message);
}

void SmartCarrier::PurgeLargeMessages() {
    string phone_number = "";
    cout << "Enter phone number: " << endl;
    cin.ignore();
    getline(std::cin, phone_number);

    map<string, vector<Message<Media> *>>::iterator it = account_list.find(phone_number);
    if (it == account_list.end()) {
        throw AccountNotFoundException(phone_number);
    }

    vector<Message<Media> *> &messages = it->second;
    vector<Message<Media> *>::iterator message_ite = messages.begin();
    while (message_ite != messages.end()) {
        if ((*message_ite)->get_data().get_size() >= Media::SIZE_THRESHOLD) {
            delete *message_ite;
            message_ite = messages.erase(message_ite);
        } else {
            ++message_ite;
        }
    }

    cout << "Large messages from account " << phone_number << " has been purged!" << endl;
}

void SmartCarrier::DisconnectAccount() {
    string phone_number = "";
    cout << "Enter phone number: " << endl;
    cin.ignore();
    getline(std::cin, phone_number);

    map<string, vector<Message<Media> *>>::iterator ite = account_list.find(phone_number);
    if (ite == account_list.end()) {
        throw AccountNotFoundException(phone_number);
    }

    vector<Message<Media> *> &messages = ite->second;
    for (vector<Message<Media> *>::iterator message_ite = messages.begin();
         message_ite != messages.end(); ++message_ite) {
        delete *message_ite;
    }

    account_list.erase(ite);
    cout << "Account " << phone_number << " has been disconnected!" << endl;
}
