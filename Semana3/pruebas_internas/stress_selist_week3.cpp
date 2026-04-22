#include <cassert>
#include "SEList.h"

int main() {
    ods::SEList<int> s(8);

    for (int i = 0; i < 500; ++i) {
        s.add(i, i);
    }
    for (int i = 0; i < 250; ++i) {
        assert(s.remove(0) == i);
    }
    for (int i = 0; i < 100; ++i) {
        s.add(i, -i);
    }
    assert(s.size() == 350);

    return 0;
}
