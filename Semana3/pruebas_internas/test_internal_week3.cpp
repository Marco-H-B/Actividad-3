#include <cassert>
#include "DLList.h"
#include "SEList.h"

int main() {
    ods::DLList<int> d;
    for (int i = 0; i < 50; ++i) d.add(i);
    for (int i = 0; i < 50; ++i) assert(d.get(i) == i);
    for (int i = 49; i >= 0; --i) assert(d.remove(i) == i);
    assert(d.size() == 0);

    ods::SEList<int> s(4);
    for (int i = 0; i < 100; ++i) s.add(i, i * 2);
    for (int i = 0; i < 100; ++i) assert(s.get(i) == i * 2);
    for (int i = 0; i < 20; ++i) assert(s.remove(0) == i * 2);
    assert(s.size() == 80);

    return 0;
}
