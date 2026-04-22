#include <cassert>
#include "ArrayDeque.h"
#include "LinkedQueue.h"
#include "LinkedDeque.h"

int main() {
    {
        ods::LinkedQueue<int> lq;
        for (int i = 0; i < 20; ++i) {
            lq.add(i);
        }
        for (int i = 0; i < 20; ++i) {
            assert(lq.front() == i);
            assert(lq.remove() == i);
        }
        assert(lq.empty());
    }

    {
        ods::ArrayDeque<int> adq;
        ods::LinkedDeque<int> ldq;

        for (int i = 0; i < 5; ++i) {
            adq.add(i, i + 1);
            ldq.addLast(i + 1);
        }

        assert(adq.get(0) == ldq.front());
        assert(adq.get(adq.size() - 1) == ldq.back());

        adq.add(0, 100);
        ldq.addFirst(100);
        adq.add(adq.size(), 200);
        ldq.addLast(200);

        assert(adq.get(0) == ldq.front());
        assert(adq.get(adq.size() - 1) == ldq.back());

        assert(adq.remove(0) == ldq.removeFirst());
        assert(adq.remove(adq.size() - 1) == ldq.removeLast());
        assert(adq.size() == ldq.size());
    }

    return 0;
}
