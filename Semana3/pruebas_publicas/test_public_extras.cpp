#include <cassert>
#include <vector>
#include "SLList.h"
#include "DLList.h"
#include "MinStack.h"
#include "MinQueue.h"
#include "MinDeque.h"
#include "XorList.h"

int main() {
    {
        ods::SLList<int> s;
        s.add(10);
        s.add(30);
        s.add(1, 20);
        assert((s.to_vector() == std::vector<int>{10, 20, 30}));
        assert(s.secondLast() == 20);
        s.reverse();
        assert((s.to_vector() == std::vector<int>{30, 20, 10}));
        assert(s.checkSize());
    }

    {
        ods::DLList<int> d;
        d.add(1); d.add(2); d.add(3); d.add(4);
        d.rotate(1);
        assert((d.to_vector() == std::vector<int>{4, 1, 2, 3}));
        assert(d.checkSize());
        ods::DLList<int> p;
        p.add(1); p.add(2); p.add(2); p.add(1);
        assert(p.isPalindrome());
    }

    {
        cc232::MinStack<int> ms;
        ms.push(5); ms.push(2); ms.push(7);
        assert(ms.min() == 2);
        assert(ms.pop() == 7);
        assert(ms.min() == 2);
    }

    {
        cc232::MinQueue<int> mq;
        mq.add(4); mq.add(1); mq.add(3);
        assert(mq.min() == 1);
        assert(mq.remove() == 4);
        assert(mq.front() == 1);
        assert(mq.min() == 1);
    }

    {
        cc232::MinDeque<int> md;
        md.addFirst(3);
        md.addLast(1);
        md.addFirst(5);
        assert(md.min() == 1);
        assert(md.front() == 5);
        assert(md.back() == 1);
        assert(md.removeLast() == 1);
        assert(md.min() == 3);
    }

    {
        cc232::XorList<int> xs;
        xs.push_back(10);
        xs.push_back(20);
        xs.push_front(5);
        assert((xs.to_vector() == std::vector<int>{5, 10, 20}));
        xs.reverse();
        assert((xs.to_vector() == std::vector<int>{20, 10, 5}));
    }

    return 0;
}
