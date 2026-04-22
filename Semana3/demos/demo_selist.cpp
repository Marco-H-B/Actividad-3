#include <iostream>
#include "SEList.h"

int main() {
    ods::SEList<int> s(3);
    for (int i = 0; i < 10; ++i) {
        s.add(i, i * 10);
    }

    std::cout << "SEList: ";
    for (int i = 0; i < s.size(); ++i) {
        std::cout << s.get(i) << ' ';
    }
    std::cout << "\n";
}
