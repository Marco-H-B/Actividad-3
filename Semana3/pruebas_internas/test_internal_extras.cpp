#include <cassert>
#include <vector>
#include "SLList.h"
#include "DLList.h"
#include "SEList.h"
#include "MinDeque.h"
#include "XorList.h"

int main() {
    {
        ods::SLList<int> s;
        for (int i = 0; i < 8; ++i) s.add(i);
        assert(s.get(3) == 3);
        assert(s.set(3, 30) == 3);
        assert(s.get(3) == 30);
        assert(s.removeAt(3) == 30);
        assert(s.checkSize());
    }

    {
        ods::DLList<int> d;
        for (int i = 1; i <= 6; ++i) d.add(i);
        auto tail = d.truncate(4);
        assert((d.to_vector() == std::vector<int>{1,2,3,4}));
        assert((tail.to_vector() == std::vector<int>{5,6}));
        d.rotate(2);
        assert((d.to_vector() == std::vector<int>{3,4,1,2}));
    }

    {
        ods::SEList<int> s(3);
        for (int i = 0; i < 15; ++i) s.add(i, i);
        auto v = s.to_vector();
        assert(v.size() == 15);
        assert(v[0] == 0 && v[14] == 14);
    }

    {
        cc232::MinDeque<int> md;
        for (int x : {7, 2, 9, 1, 8}) md.addLast(x);
        assert(md.min() == 1);
        assert(md.removeFirst() == 7);
        assert(md.removeFirst() == 2);
        assert(md.min() == 1);
        assert(md.removeLast() == 8);
    }

    {
        cc232::XorList<int> xs;
        for (int i = 0; i < 20; ++i) xs.push_back(i);
        assert(xs.get(0) == 0);
        assert(xs.get(19) == 19);
        assert(xs.pop_front() == 0);
        assert(xs.pop_back() == 19);
        assert(xs.size() == 18);
    }

    return 0;
}
