#pragma once

#include <cassert>
#include "DLList.h"

namespace ods {

template<class T>
class LinkedDeque {
private:
    DLList<T> list;

public:
    LinkedDeque() = default;
    ~LinkedDeque() = default;

    int size() const {
        return list.size();
    }

    bool empty() const {
        return list.empty();
    }

    void clear() {
        list.clear();
    }

    void addFirst(const T& x) {
        list.add(0, x);
    }

    void addLast(const T& x) {
        list.add(list.size(), x);
    }

    T removeFirst() {
        assert(!empty());
        return list.remove(0);
    }

    T removeLast() {
        assert(!empty());
        return list.remove(list.size() - 1);
    }

    T front() const {
        assert(!empty());
        return list.front();
    }

    T back() const {
        assert(!empty());
        return list.back();
    }

    T get(int i) const {
        return list.get(i);
    }

    T set(int i, const T& x) {
        return list.set(i, x);
    }
};

} // namespace ods
