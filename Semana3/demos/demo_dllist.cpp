#include <iostream>
#include "DLList.h"

int main() {
    ods::DLList<int> d;
    d.add(0, 10);
    d.add(1, 30);
    d.add(1, 20);

    std::cout << "DLList: ";
    for (int i = 0; i < d.size(); ++i) {
        std::cout << d.get(i) << ' ';
    }
    std::cout << "\n";
}
