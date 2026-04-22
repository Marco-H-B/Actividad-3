#include <iostream>
#include "Capitulo3.h"

int main() {
    ods::SLList<int> sll;
    sll.add(1);
    sll.add(2);
    sll.push(0);

    ods::DLList<int> dll;
    dll.add(0, 10);
    dll.add(1, 30);
    dll.add(1, 20);

    ods::SEList<int> sel(3);
    sel.add(0, 8);
    sel.add(1, 6);
    sel.add(2, 7);

    ods::LinkedStack<int> st;
    st.push(100);
    st.push(200);

    ods::LinkedQueue<int> q;
    q.add(11);
    q.add(22);

    ods::LinkedDeque<int> dq;
    dq.addFirst(5);
    dq.addLast(9);

    ods::ArrayDeque<int> ad;
    ad.add(0, 4);
    ad.add(1, 5);
    ad.add(2, 6);

    std::cout << "Semana 3 cargada correctamente\n";
    std::cout << "SLList size = " << sll.size() << ", peek = " << sll.peek() << "\n";
    std::cout << "DLList: ";
    for (int i = 0; i < dll.size(); ++i) std::cout << dll.get(i) << ' ';
    std::cout << "\nSEList: ";
    for (int i = 0; i < sel.size(); ++i) std::cout << sel.get(i) << ' ';
    std::cout << "\nLinkedStack top = " << st.top();
    std::cout << "\nLinkedQueue front = " << q.front();
    std::cout << "\nLinkedDeque front/back = " << dq.front() << '/' << dq.back();
    std::cout << "\nArrayDeque first/last = " << ad.get(0) << '/' << ad.get(ad.size() - 1) << "\n";
    return 0;
}
