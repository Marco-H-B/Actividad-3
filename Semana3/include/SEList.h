#pragma once

#include <cassert>
#include <vector>
#include "ArrayDeque.h"
#include "array.h"

namespace ods {

template<class T>
class SEList {
protected:
    int n;
    int b;

    class BDeque : public ArrayDeque<T> {
        using ArrayDeque<T>::a;
        using ArrayDeque<T>::j;
        using ArrayDeque<T>::n;
    public:
        explicit BDeque(int block_size) {
            n = 0;
            j = 0;
            array<T> z(block_size + 1);
            a = z;
        }

        void add(int i, T x) override {
            ArrayDeque<T>::add(i, x);
        }

        bool add(T x) {
            ArrayDeque<T>::add(this->size(), x);
            return true;
        }

        void resize() override {}
    };

    struct Node {
        BDeque d;
        Node* prev;
        Node* next;
        explicit Node(int block_size) : d(block_size), prev(nullptr), next(nullptr) {}
    };

    Node dummy;

    struct Location {
        Node* u;
        int j;
    };

    Node* addBefore(Node* w) {
        Node* u = new Node(b);
        u->prev = w->prev;
        u->next = w;
        u->prev->next = u;
        u->next->prev = u;
        return u;
    }

    void removeNode(Node* w) {
        w->prev->next = w->next;
        w->next->prev = w->prev;
        delete w;
    }

    void getLocation(int i, Location& ell) {
        assert(0 <= i && i < n);
        if (i < n / 2) {
            Node* u = dummy.next;
            int idx = i;
            while (idx >= u->d.size()) {
                idx -= u->d.size();
                u = u->next;
            }
            ell.u = u;
            ell.j = idx;
        } else {
            Node* u = &dummy;
            int idx = n;
            while (i < idx) {
                u = u->prev;
                idx -= u->d.size();
            }
            ell.u = u;
            ell.j = i - idx;
        }
    }

    void spread(Node* u) {
        Node* w = u;
        for (int j = 0; j < b; ++j) w = w->next;
        w = addBefore(w);
        while (w != u) {
            while (w->d.size() < b) {
                w->d.add(0, w->prev->d.remove(w->prev->d.size() - 1));
            }
            w = w->prev;
        }
    }

    void gather(Node* u) {
        Node* w = u;
        for (int j = 0; j < b - 1; ++j) {
            while (w->d.size() < b) {
                w->d.add(w->next->d.remove(0));
            }
            w = w->next;
        }
        removeNode(w);
    }

    void addLast(const T& x) {
        Node* last = dummy.prev;
        if (last == &dummy || last->d.size() == b + 1) {
            last = addBefore(&dummy);
        }
        last->d.add(x);
        ++n;
    }

public:
    explicit SEList(int block_size = 3) : n(0), b(block_size), dummy(block_size) {
        assert(block_size >= 2);
        dummy.next = &dummy;
        dummy.prev = &dummy;
    }

    ~SEList() {
        clear();
    }

    int size() const {
        return n;
    }

    bool empty() const {
        return n == 0;
    }

    void clear() {
        Node* u = dummy.next;
        while (u != &dummy) {
            Node* w = u->next;
            delete u;
            u = w;
        }
        dummy.next = &dummy;
        dummy.prev = &dummy;
        n = 0;
    }

    T get(int i) {
        Location l;
        getLocation(i, l);
        return l.u->d.get(l.j);
    }

    T set(int i, T x) {
        Location l;
        getLocation(i, l);
        return l.u->d.set(l.j, x);
    }

    void add(int i, T x) {
        assert(0 <= i && i <= n);
        if (i == n) {
            addLast(x);
            return;
        }

        Location l;
        getLocation(i, l);
        Node* u = l.u;
        int r = 0;

        while (r < b && u != &dummy && u->d.size() == b + 1) {
            u = u->next;
            ++r;
        }

        if (r == b) {
            spread(l.u);
            u = l.u;
        }

        if (u == &dummy) {
            u = addBefore(u);
        }

        while (u != l.u) {
            u->d.add(0, u->prev->d.remove(u->prev->d.size() - 1));
            u = u->prev;
        }

        u->d.add(l.j, x);
        ++n;
    }

    T remove(int i) {
        assert(0 <= i && i < n);
        Location l;
        getLocation(i, l);
        T y = l.u->d.get(l.j);

        Node* u = l.u;
        int r = 0;
        while (r < b && u != &dummy && u->d.size() == b - 1) {
            u = u->next;
            ++r;
        }

        if (r == b) {
            gather(l.u);
        }

        u = l.u;
        u->d.remove(l.j);

        while (u->d.size() < b - 1 && u->next != &dummy) {
            u->d.add(u->next->d.remove(0));
            u = u->next;
        }

        if (u->d.size() == 0) {
            removeNode(u);
        }

        --n;
        return y;
    }

    std::vector<T> to_vector() {
        std::vector<T> out;
        out.reserve(n);
        for (int i = 0; i < n; ++i) {
            out.push_back(get(i));
        }
        return out;
    }
};

} // namespace ods
