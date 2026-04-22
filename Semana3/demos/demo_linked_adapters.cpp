#include <iostream>
#include "LinkedStack.h"
#include "LinkedQueue.h"
#include "LinkedDeque.h"

int main() {
    std::cout << "Adaptadores enlazados de Semana 3\n\n";

    ods::LinkedStack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    std::cout << "LinkedStack\n";
    std::cout << "  top() = " << st.top() << "\n";
    std::cout << "  pop() = " << st.pop() << "\n";
    std::cout << "  top() = " << st.top() << "\n";
    std::cout << "  size() = " << st.size() << "\n\n";

    ods::LinkedQueue<int> q;
    q.add(1);
    q.add(2);
    q.add(3);
    std::cout << "LinkedQueue\n";
    std::cout << "  front() = " << q.front() << "\n";
    std::cout << "  remove() = " << q.remove() << "\n";
    std::cout << "  front() = " << q.front() << "\n";
    std::cout << "  size() = " << q.size() << "\n\n";

    ods::LinkedDeque<int> dq;
    dq.addFirst(20);
    dq.addFirst(10);
    dq.addLast(30);
    dq.addLast(40);
    std::cout << "LinkedDeque\n";
    std::cout << "  front() = " << dq.front() << ", back() = " << dq.back() << "\n";
    std::cout << "  removeFirst() = " << dq.removeFirst() << "\n";
    std::cout << "  removeLast() = " << dq.removeLast() << "\n";
    std::cout << "  front() = " << dq.front() << ", back() = " << dq.back() << "\n";
    std::cout << "  size() = " << dq.size() << "\n";

    return 0;
}
