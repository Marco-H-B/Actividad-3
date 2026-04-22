#include <cassert>
#include "SLList.h"
#include "DLList.h"
#include "SEList.h"

int main() {
    {
        ods::SLList<int> s;
        s.add(10);
        s.add(20);
        s.push(5);
        assert(s.size() == 3);
        assert(s.peek() == 5);
        assert(s.pop() == 5);
        assert(s.remove() == 10);
        assert(s.size() == 1);
    }

    {
        ods::DLList<int> d;
        d.add(0, 10);
        d.add(1, 30);
        d.add(1, 20);
        assert(d.size() == 3);
        assert(d.get(0) == 10);
        assert(d.get(1) == 20);
        assert(d.get(2) == 30);
        assert(d.remove(1) == 20);
        assert(d.size() == 2);
    }

    {
        ods::SEList<int> s(3);
        for (int i = 0; i < 10; ++i) s.add(i, i);
        assert(s.size() == 10);
        assert(s.get(5) == 5);
        assert(s.set(5, 50) == 5);
        assert(s.get(5) == 50);
        assert(s.remove(5) == 50);
        assert(s.size() == 9);
    }

    return 0;
}
