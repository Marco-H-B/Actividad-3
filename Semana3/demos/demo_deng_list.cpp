#include <iostream>
#include "DengList.h"

int main() {
    cc232::DengList<int> lista;
    lista.push_back(30);
    lista.push_back(10);
    lista.push_back(20);
    lista.push_front(5);

    std::cout << "size = " << lista.size() << "\n";
    std::cout << "front = " << lista.front() << "\n";
    std::cout << "back = " << lista.back() << "\n";

    lista.sort();

    std::cout << "ordenada: ";
    for (int x : lista.to_vector()) {
        std::cout << x << ' ';
    }
    std::cout << "\n";
}
