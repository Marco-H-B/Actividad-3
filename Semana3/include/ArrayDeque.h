#pragma once

#include <algorithm>
#include <cassert>
#include "array.h"

namespace ods {

template<class T>
class ArrayDeque {
protected:
    array<T> a;
    int j;
    int n;

    virtual void resize() {
        int cap = std::max(1, 2 * n);
        array<T> b(cap);
        for (int k = 0; k < n; ++k) {
            b[k] = a[(j + k) % a.length()];
        }
        a = b;
        j = 0;
    }

public:
    ArrayDeque() : a(1), j(0), n(0) {}
    virtual ~ArrayDeque() = default;

    int size() const {
        return n;
    }

    bool empty() const {
        return n == 0;
    }

    T get(int i) const {
        assert(0 <= i && i < n);
        return a[(j + i) % a.length()];
    }

    T set(int i, T x) {
        assert(0 <= i && i < n);
        int idx = (j + i) % a.length();
        T y = a[idx];
        a[idx] = x;
        return y;
    }

    virtual void add(int i, T x) {
        assert(0 <= i && i <= n);
        if (n + 1 > a.length()) {
            resize();
        }
        assert(n + 1 <= a.length());
        if (i < n / 2) {
            j = (j == 0) ? a.length() - 1 : j - 1;
            for (int k = 0; k < i; ++k) {
                a[(j + k) % a.length()] = a[(j + k + 1) % a.length()];
            }
        } else {
            for (int k = n; k > i; --k) {
                a[(j + k) % a.length()] = a[(j + k - 1) % a.length()];
            }
        }
        a[(j + i) % a.length()] = x;
        ++n;
    }

    bool add(T x) {
        add(n, x);
        return true;
    }

    T remove(int i) {
        assert(0 <= i && i < n);
        T x = a[(j + i) % a.length()];
        if (i < n / 2) {
            for (int k = i; k > 0; --k) {
                a[(j + k) % a.length()] = a[(j + k - 1) % a.length()];
            }
            j = (j + 1) % a.length();
        } else {
            for (int k = i; k < n - 1; ++k) {
                a[(j + k) % a.length()] = a[(j + k + 1) % a.length()];
            }
        }
        --n;
        if (a.length() >= 3 * std::max(1, n)) {
            resize();
        }
        return x;
    }

    void clear() {
        a = array<T>(1);
        j = 0;
        n = 0;
    }
};

} // namespace ods
