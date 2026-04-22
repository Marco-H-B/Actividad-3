#pragma once

#include <cassert>
#include <functional>
#include "MinStack.h"

namespace cc232 {

template<class T, class Compare = std::less<T>>
class MinQueue {
    MinStack<T, Compare> in_;
    MinStack<T, Compare> out_;
    Compare comp_;

    void moveIfNeeded() {
        if (!out_.empty()) {
            return;
        }
        while (!in_.empty()) {
            out_.push(in_.pop());
        }
    }

public:
    MinQueue() = default;

    int size() const {
        return in_.size() + out_.size();
    }

    bool empty() const {
        return size() == 0;
    }

    void clear() {
        in_.clear();
        out_.clear();
    }

    void add(const T& value) {
        in_.push(value);
    }

    T front() {
        assert(!empty());
        moveIfNeeded();
        return out_.top();
    }

    T remove() {
        assert(!empty());
        moveIfNeeded();
        return out_.pop();
    }

    T min() const {
        assert(!empty());
        if (in_.empty()) {
            return out_.min();
        }
        if (out_.empty()) {
            return in_.min();
        }
        T a = in_.min();
        T b = out_.min();
        return comp_(a, b) ? a : b;
    }
};

} // namespace cc232
