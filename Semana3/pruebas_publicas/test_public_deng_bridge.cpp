#include <cassert>
#include <vector>
#include "DengList.h"
#include "MorinDengBridge.h"

int main() {
    {
        cc232::DengList<int> l;
        l.push_back(3);
        l.push_front(1);
        l.add(1, 2);
        assert(l.size() == 3);
        assert(l.front() == 1);
        assert(l.back() == 3);
        assert(l.get(1) == 2);
        assert(l.contains(3));
        assert(l.find_index(3) == 2);
    }

    {
        ods::DLList<int> d;
        d.add(4);
        d.add(1);
        d.add(3);
        d.add(1);
        d.add(2);
        cc232::stable_sort_with_deng(d);
        auto v = cc232::to_vector(d);
        assert((v == std::vector<int>{1, 1, 2, 3, 4}));
        int removed = cc232::dedup_with_deng(d);
        assert(removed == 1);
        v = cc232::to_vector(d);
        assert((v == std::vector<int>{1, 2, 3, 4}));
    }

    {
        ods::SEList<int> s(3);
        s.add(0, 9);
        s.add(1, 7);
        s.add(2, 8);
        cc232::stable_sort_with_deng(s);
        auto v = cc232::to_vector(s);
        assert((v == std::vector<int>{7, 8, 9}));
        cc232::reverse_with_deng(s);
        v = cc232::to_vector(s);
        assert((v == std::vector<int>{9, 8, 7}));
    }

    return 0;
}
