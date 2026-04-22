#pragma once

#include <cassert>
#include <vector>

namespace ods {

template<class T>
class SLList {
protected:
    struct Node {
        T x;
        Node* next;
        explicit Node(const T& x0) : x(x0), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int n;

    Node* nodeAt(int i) const {
        assert(0 <= i && i < n);
        Node* u = head;
        for (int k = 0; k < i; ++k) {
            u = u->next;
        }
        return u;
    }

public:
    SLList() : head(nullptr), tail(nullptr), n(0) {}

    SLList(const SLList& other) : SLList() {
        for (Node* u = other.head; u != nullptr; u = u->next) {
            add(u->x);
        }
    }

    SLList& operator=(const SLList& other) {
        if (this != &other) {
            clear();
            for (Node* u = other.head; u != nullptr; u = u->next) {
                add(u->x);
            }
        }
        return *this;
    }

    SLList(SLList&& other) noexcept : head(other.head), tail(other.tail), n(other.n) {
        other.head = other.tail = nullptr;
        other.n = 0;
    }

    SLList& operator=(SLList&& other) noexcept {
        if (this != &other) {
            clear();
            head = other.head;
            tail = other.tail;
            n = other.n;
            other.head = other.tail = nullptr;
            other.n = 0;
        }
        return *this;
    }

    ~SLList() {
        clear();
    }

    int size() const {
        return n;
    }

    bool empty() const {
        return n == 0;
    }

    void clear() {
        Node* u = head;
        while (u != nullptr) {
            Node* w = u;
            u = u->next;
            delete w;
        }
        head = tail = nullptr;
        n = 0;
    }

    T peek() const {
        assert(n > 0);
        return head->x;
    }

    T get(int i) const {
        return nodeAt(i)->x;
    }

    T set(int i, const T& x) {
        Node* u = nodeAt(i);
        T y = u->x;
        u->x = x;
        return y;
    }

    bool add(const T& x) {
        Node* u = new Node(x);
        if (n == 0) {
            head = tail = u;
        } else {
            tail->next = u;
            tail = u;
        }
        ++n;
        return true;
    }

    void add(int i, const T& x) {
        assert(0 <= i && i <= n);
        if (i == 0) {
            push(x);
            return;
        }
        if (i == n) {
            add(x);
            return;
        }
        Node* prev = nodeAt(i - 1);
        Node* u = new Node(x);
        u->next = prev->next;
        prev->next = u;
        ++n;
    }

    T push(const T& x) {
        Node* u = new Node(x);
        u->next = head;
        head = u;
        if (n == 0) {
            tail = u;
        }
        ++n;
        return x;
    }

    T remove() {
        assert(n > 0);
        Node* u = head;
        T x = u->x;
        head = head->next;
        delete u;
        --n;
        if (n == 0) {
            tail = nullptr;
        }
        return x;
    }

    T removeAt(int i) {
        assert(0 <= i && i < n);
        if (i == 0) {
            return remove();
        }
        Node* prev = nodeAt(i - 1);
        Node* u = prev->next;
        prev->next = u->next;
        if (u == tail) {
            tail = prev;
        }
        T x = u->x;
        delete u;
        --n;
        return x;
    }

    T pop() {
        return remove();
    }

    T secondLast() const {
        assert(n >= 2);
        Node* u = head;
        while (u->next != tail) {
            u = u->next;
        }
        return u->x;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        tail = head;
        while (curr != nullptr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    bool checkSize() const {
        int count = 0;
        Node* u = head;
        Node* last = nullptr;
        while (u != nullptr) {
            last = u;
            u = u->next;
            ++count;
        }
        if (count != n) {
            return false;
        }
        if (n == 0) {
            return head == nullptr && tail == nullptr;
        }
        return head != nullptr && tail == last;
    }

    std::vector<T> to_vector() const {
        std::vector<T> out;
        out.reserve(n);
        for (Node* u = head; u != nullptr; u = u->next) {
            out.push_back(u->x);
        }
        return out;
    }
};

} // namespace ods
