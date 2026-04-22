#pragma once

#include <cassert>
#include <functional>
#include <utility>
#include "SLList.h"

namespace cc232 {

template<class T, class Compare = std::less<T>>
class MinStack {
    struct Entry {
        T value;
        T current_min;
    };

    ods::SLList<Entry> data_;
    Compare comp_;

public:
    MinStack() = default;

    int size() const {
        return data_.size();
    }

    bool empty() const {
        return data_.empty();
    }

    void clear() {
        data_.clear();
    }

    void push(const T& value) {
        if (data_.empty()) {
            data_.push({value, value});
            return;
        }
        Entry top = data_.peek();
        T best = comp_(value, top.current_min) ? value : top.current_min;
        data_.push({value, best});
    }

    T pop() {
        assert(!empty());
        return data_.pop().value;
    }

    T top() const {
        assert(!empty());
        return data_.peek().value;
    }

    T min() const {
        assert(!empty());
        return data_.peek().current_min;
    }
};

} // namespace cc232
