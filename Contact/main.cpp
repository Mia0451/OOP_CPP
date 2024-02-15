#include <string>
#include "AddressBook.h"

using namespace std;

int main() {
    AddressBook* p_address_book = nullptr;
    p_address_book = new AddressBook();
    p_address_book->Init();
    p_address_book->Run();
    delete p_address_book;
    return 0;
}
