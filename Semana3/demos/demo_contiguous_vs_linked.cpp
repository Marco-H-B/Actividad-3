#include <iostream>
#include <string>
#include "ArrayDeque.h"
#include "DLList.h"
#include "LinkedQueue.h"
#include "LinkedDeque.h"

namespace {

template<class T>
class ArrayQueueOnDeque {
private:
    ods::ArrayDeque<T> dq;

public:
    bool add(const T& x) {
        return dq.add(x);
    }

    T remove() {
        return dq.remove(0);
    }

    T front() const {
        return dq.get(0);
    }

    int size() const {
        return dq.size();
    }

    bool empty() const {
        return dq.empty();
    }
};

} // namespace

int main() {
    std::cout << "Comparacion contiguo vs enlazado (standalone Semana3)\n\n";

    std::cout << "[1] Cola FIFO\n";
    ArrayQueueOnDeque<int> aq;
    ods::LinkedQueue<int> lq;
    for (int i = 1; i <= 5; ++i) {
        aq.add(i);
        lq.add(i);
    }
    std::cout << "  Cola contigua (sobre ArrayDeque)  front/remove: "
              << aq.front() << " / " << aq.remove() << "\n";
    std::cout << "  Cola enlazada (LinkedQueue)       front/remove: "
              << lq.front() << " / " << lq.remove() << "\n\n";

    std::cout << "[2] Deque\n";
    ods::ArrayDeque<std::string> adq;
    ods::LinkedDeque<std::string> ldq;

    adq.add(0, "b");
    adq.add(0, "a");
    adq.add(adq.size(), "c");
    adq.add(adq.size(), "d");

    ldq.addFirst("b");
    ldq.addFirst("a");
    ldq.addLast("c");
    ldq.addLast("d");

    std::cout << "  ArrayDeque   first/last: "
              << adq.get(0) << " / " << adq.get(adq.size() - 1) << "\n";
    std::cout << "  LinkedDeque  first/last: "
              << ldq.front() << " / " << ldq.back() << "\n\n";

    std::cout << "[3] Acceso por indice\n";
    ods::ArrayDeque<int> contiguous;
    ods::DLList<int> linked;
    for (int i = 0; i < 8; ++i) {
        contiguous.add(i, i * 10);
        linked.add(i, i * 10);
    }
    std::cout << "  ArrayDeque get(4) = " << contiguous.get(4) << "\n";
    std::cout << "  DLList    get(4) = " << linked.get(4) << "\n\n";

    std::cout << "Observaciones:\n";
    std::cout << "- La representacion contigua ofrece mejor localidad de memoria.\n";
    std::cout << "- La representacion enlazada facilita inserciones/borrados locales.\n";
    std::cout << "- ArrayDeque cubre la comparacion contigua;\n";
    std::cout << "  En el repositorio se puede complementar con ArrayQueue y DualArrayDeque.\n";

    return 0;
}
