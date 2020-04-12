#include "cLinkedList.h"
#include <cassert>
#include <string>
#include <iostream>

int main() {
    utec::cLinkedList<size_t> oLL;

    for (size_t i = 0; i < 10; ++i) {
        oLL.push_front(i);
        oLL.push_back(i);
    }
    assert(oLL.size() == 20);

    std::string result{};
    for (size_t i = 0; i < 20; ++i)
        result += std::to_string(oLL.item(i)) + ' ';
    assert(result == "9 8 7 6 5 4 3 2 1 0 0 1 2 3 4 5 6 7 8 9 ");

    oLL.pop_back();
    oLL.pop_front();
    oLL.erase(8);
    oLL.insert(8, 1);
    oLL.insert(10, 1);
    oLL.insert(1, 8);
    result = "";
    for (size_t i = 0; i < oLL.size(); ++i)
        result += std::to_string(oLL.item(i)) + ' ';
    assert(result == "8 8 7 6 5 4 3 2 1 1 0 1 1 2 3 4 5 6 7 8 ");

    std::cout << "Success\n";
    return 0;
}
