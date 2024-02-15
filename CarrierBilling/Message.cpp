//
// Created by shiwe on 11/28/2023.
//

#include <string>
#include "Message.h"
#include "Media.h"

using namespace std;

template<typename T>
const string Message<T>::DEFAULT_TO = "000-000-0000";

template<typename T>
Message<T>::Message(): to(Message<T>::DEFAULT_TO) {}

template<typename T>
Message<T>::Message(const string &to, const T &data) : to(to), m_data(data) {}

template<typename T>
Message<T>::~Message() {}

template<typename T>
const string &Message<T>::get_to() const {
    return to;
}

template<typename T>
void Message<T>::set_to(const string &to) {
    this->to = to;
}

template<typename T>
const T &Message<T>::get_data() const {
    return m_data;
}

template<typename T>
void Message<T>::set_data(const T &data) {
    m_data = data;
}

// Need this explicit declaration to make compiler compile
// the specific class.
template
class Message<Media>;