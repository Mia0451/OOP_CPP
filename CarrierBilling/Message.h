//
// Created by shiwe on 11/28/2023.
//

#ifndef CS2B_ASSIGNMENT4_MESSAGE_H
#define CS2B_ASSIGNMENT4_MESSAGE_H

#include <string>

using namespace std;

template<typename T>
class Message {
private:
    string to;
    T m_data;

public:
    static const string DEFAULT_TO;

    Message();

    Message(const string &to, const T &data);

    ~Message();

    const string &get_to() const;

    void set_to(const string &to);

    const T &get_data() const;

    void set_data(const T &data);
};


#endif //CS2B_ASSIGNMENT4_MESSAGE_H
