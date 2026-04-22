#include <cassert>
#include <vector>
#include "DengList.h"
#include "MorinDengBridge.h"

int main() {
    cc232::DengList<int> l;
    for (int x : {5, 1, 5, 3, 3, 2, 4}) {
        l.push_back(x);
    }
    l.sort();
    assert((l.to_vector() == std::vector<int>{1, 2, 3, 3, 4, 5, 5}));
    assert(l.uniquify() == 2);
    assert((l.to_vector() == std::vector<int>{1, 2, 3, 4, 5}));
    l.reverse();
    assert((l.to_vector() == std::vector<int>{5, 4, 3, 2, 1}));

    ods::DLList<int> d;
    for (int x : {4, 4, 1, 3, 2, 2}) d.add(x);
    int removed = cc232::dedup_with_deng(d);
    assert(removed == 2);
    auto v = cc232::to_vector(d);
    assert((v == std::vector<int>{4, 1, 3, 2}));
    cc232::reverse_with_deng(d);
    v = cc232::to_vector(d);
    assert((v == std::vector<int>{2, 3, 1, 4}));

    return 0;
}
