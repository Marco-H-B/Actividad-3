#include <iostream>
#include "MinStack.h"
#include "MinQueue.h"
#include "MinDeque.h"

int main() {
    cc232::MinStack<int> ms;
    ms.push(5); ms.push(3); ms.push(7);
    std::cout << "MinStack min=" << ms.min() << " top=" << ms.top() << std::endl;

    cc232::MinQueue<int> mq;
    mq.add(4); mq.add(2); mq.add(6);
    std::cout << "MinQueue min=" << mq.min() << " front=" << mq.front() << std::endl;

    cc232::MinDeque<int> md;
    md.addFirst(5); md.addLast(1); md.addFirst(3);
    std::cout << "MinDeque min=" << md.min()
              << " front=" << md.front()
              << " back=" << md.back() << std::endl;
    return 0;
}
