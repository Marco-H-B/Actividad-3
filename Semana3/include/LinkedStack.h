#pragma once

#include <cassert>
#include "SLList.h"

namespace ods {

template<class T>
class LinkedStack {
private:
    SLList<T> list;

public:
    LinkedStack() = default;
    ~LinkedStack() = default;

    int size() const {
        return list.size();
    }

    bool empty() const {
        return list.empty();
    }

    void clear() {
        list.clear();
    }

    T push(const T& x) {
        return list.push(x);
    }

    T pop() {
        assert(!empty());
        return list.pop();
    }

    T top() const {
        assert(!empty());
        return list.peek();
    }
};

} // namespace ods
