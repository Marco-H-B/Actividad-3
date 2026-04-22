#pragma once

#include <algorithm>
#include <cassert>
#include <functional>
#include <vector>
#include "MinStack.h"

namespace cc232 {

template<class T, class Compare = std::less<T>>
class MinDeque {
    MinStack<T, Compare> front_;
    MinStack<T, Compare> back_;
    Compare comp_;

    std::vector<T> snapshotOrder() {
        std::vector<T> order;
        order.reserve(size());

        MinStack<T, Compare> frontCopy = front_;
        while (!frontCopy.empty()) {
            order.push_back(frontCopy.pop());
        }

        std::vector<T> tail;
        MinStack<T, Compare> backCopy = back_;
        while (!backCopy.empty()) {
            tail.push_back(backCopy.pop());
        }
        std::reverse(tail.begin(), tail.end());
        order.insert(order.end(), tail.begin(), tail.end());
        return order;
    }

    void rebuildFromOrder(const std::vector<T>& order) {
        front_.clear();
        back_.clear();
        const int m = static_cast<int>(order.size());
        const int left = (m + 1) / 2;
        for (int i = left - 1; i >= 0; --i) {
            front_.push(order[static_cast<std::size_t>(i)]);
        }
        for (int i = left; i < m; ++i) {
            back_.push(order[static_cast<std::size_t>(i)]);
        }
    }

    void rebalance() {
        if (!front_.empty() && !back_.empty()) {
            return;
        }
        const auto order = snapshotOrder();
        rebuildFromOrder(order);
    }

public:
    MinDeque() = default;

    int size() const {
        return front_.size() + back_.size();
    }

    bool empty() const {
        return size() == 0;
    }

    void clear() {
        front_.clear();
        back_.clear();
    }

    void addFirst(const T& value) {
        front_.push(value);
    }

    void addLast(const T& value) {
        back_.push(value);
    }

    T front() {
        assert(!empty());
        rebalance();
        return front_.top();
    }

    T back() {
        assert(!empty());
        rebalance();
        return back_.top();
    }

    T removeFirst() {
        assert(!empty());
        rebalance();
        T value = front_.pop();
        if (!empty()) {
            rebalance();
        }
        return value;
    }

    T removeLast() {
        assert(!empty());
        rebalance();
        T value = back_.pop();
        if (!empty()) {
            rebalance();
        }
        return value;
    }

    T min() const {
        assert(!empty());
        if (front_.empty()) {
            return back_.min();
        }
        if (back_.empty()) {
            return front_.min();
        }
        T a = front_.min();
        T b = back_.min();
        return comp_(a, b) ? a : b;
    }
};

} // namespace cc232
