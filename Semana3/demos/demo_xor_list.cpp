#include <iostream>
#include "XorList.h"

int main() {
    cc232::XorList<int> xs;
    xs.push_back(10);
    xs.push_back(20);
    xs.push_front(5);

    std::cout << "XorList: ";
    for (int x : xs.to_vector()) {
        std::cout << x << ' ';
    }
    std::cout << std::endl
              << "front=" << xs.front() << " back=" << xs.back() << std::endl;
    return 0;
}
