#pragma once

#include <cassert>
#include <cstdint>
#include <vector>

namespace cc232 {

template<class T>
class XorList {
    struct Node {
        T value;
        std::uintptr_t link;
        explicit Node(const T& v) : value(v), link(0) {}
    };

    Node* head_;
    Node* tail_;
    int n_;

    static Node* xorp(Node* a, Node* b) {
        return reinterpret_cast<Node*>(reinterpret_cast<std::uintptr_t>(a) ^ reinterpret_cast<std::uintptr_t>(b));
    }

    static Node* next(Node* prev, Node* curr) {
        return xorp(prev, reinterpret_cast<Node*>(curr->link));
    }

    Node* nodeAt(int i) const {
        assert(0 <= i && i < n_);
        if (i < n_ / 2) {
            Node* prev = nullptr;
            Node* curr = head_;
            for (int k = 0; k < i; ++k) {
                Node* nxt = next(prev, curr);
                prev = curr;
                curr = nxt;
            }
            return curr;
        }
        Node* nextNode = nullptr;
        Node* curr = tail_;
        for (int k = n_ - 1; k > i; --k) {
            Node* prv = xorp(nextNode, reinterpret_cast<Node*>(curr->link));
            nextNode = curr;
            curr = prv;
        }
        return curr;
    }

public:
    XorList() : head_(nullptr), tail_(nullptr), n_(0) {}

    ~XorList() {
        clear();
    }

    int size() const {
        return n_;
    }

    bool empty() const {
        return n_ == 0;
    }

    void clear() {
        Node* prev = nullptr;
        Node* curr = head_;
        while (curr != nullptr) {
            Node* nxt = next(prev, curr);
            delete curr;
            prev = curr;
            curr = nxt;
        }
        head_ = tail_ = nullptr;
        n_ = 0;
    }

    void push_front(const T& value) {
        Node* u = new Node(value);
        u->link = reinterpret_cast<std::uintptr_t>(head_);
        if (head_ != nullptr) {
            Node* headNext = next(nullptr, head_);
            head_->link = reinterpret_cast<std::uintptr_t>(xorp(u, headNext));
        } else {
            tail_ = u;
        }
        head_ = u;
        ++n_;
    }

    void push_back(const T& value) {
        Node* u = new Node(value);
        u->link = reinterpret_cast<std::uintptr_t>(tail_);
        if (tail_ != nullptr) {
            Node* tailPrev = xorp(nullptr, reinterpret_cast<Node*>(tail_->link));
            tail_->link = reinterpret_cast<std::uintptr_t>(xorp(tailPrev, u));
        } else {
            head_ = u;
        }
        tail_ = u;
        ++n_;
    }

    T front() const {
        assert(!empty());
        return head_->value;
    }

    T back() const {
        assert(!empty());
        return tail_->value;
    }

    T pop_front() {
        assert(!empty());
        Node* old = head_;
        T value = old->value;
        Node* nxt = next(nullptr, old);
        if (nxt != nullptr) {
            Node* nxtNext = next(old, nxt);
            nxt->link = reinterpret_cast<std::uintptr_t>(xorp(nullptr, nxtNext));
            head_ = nxt;
        } else {
            head_ = tail_ = nullptr;
        }
        delete old;
        --n_;
        return value;
    }

    T pop_back() {
        assert(!empty());
        Node* old = tail_;
        T value = old->value;
        Node* prv = xorp(nullptr, reinterpret_cast<Node*>(old->link));
        if (prv != nullptr) {
            Node* prvPrev = xorp(old, reinterpret_cast<Node*>(prv->link));
            prv->link = reinterpret_cast<std::uintptr_t>(xorp(prvPrev, nullptr));
            tail_ = prv;
        } else {
            head_ = tail_ = nullptr;
        }
        delete old;
        --n_;
        return value;
    }

    T get(int i) const {
        return nodeAt(i)->value;
    }

    void reverse() {
        std::swap(head_, tail_);
    }

    std::vector<T> to_vector() const {
        std::vector<T> out;
        out.reserve(n_);
        Node* prev = nullptr;
        Node* curr = head_;
        while (curr != nullptr) {
            out.push_back(curr->value);
            Node* nxt = next(prev, curr);
            prev = curr;
            curr = nxt;
        }
        return out;
    }
};

} // namespace cc232
