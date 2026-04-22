#include <iostream>
#include "SLList.h"

int main() {
    ods::SLList<int> q;
    q.add(10);
    q.add(20);
    q.push(5);

    std::cout << "size = " << q.size() << "\n";
    std::cout << "peek = " << q.peek() << "\n";
    std::cout << "pop = " << q.pop() << "\n";
    std::cout << "remove = " << q.remove() << "\n";
}
