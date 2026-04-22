#pragma once

#include <cassert>
#include "SLList.h"

namespace ods {

template<class T>
class LinkedQueue {
private:
    SLList<T> list;

public:
    LinkedQueue() = default;
    ~LinkedQueue() = default;

    int size() const {
        return list.size();
    }

    bool empty() const {
        return list.empty();
    }

    void clear() {
        list.clear();
    }

    bool add(const T& x) {
        return list.add(x);
    }

    T remove() {
        assert(!empty());
        return list.remove();
    }

    T front() const {
        assert(!empty());
        return list.peek();
    }
};

} // namespace ods
