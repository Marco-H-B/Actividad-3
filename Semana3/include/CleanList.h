#pragma once

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <functional>
#include <initializer_list>
#include <utility>
#include <vector>

namespace cc232 {

template <class T>
class CleanList {
public:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node() : data(), prev(nullptr), next(nullptr) {}
        Node(const T& value, Node* p = nullptr, Node* n = nullptr)
            : data(value), prev(p), next(n) {}
    };

    using node_type = Node;
    using position = Node*;
    using const_position = const Node*;

private:
    std::size_t size_;
    Node header_;
    Node trailer_;

    void init_empty() {
        header_.prev = nullptr;
        header_.next = &trailer_;
        trailer_.prev = &header_;
        trailer_.next = nullptr;
        size_ = 0;
    }

    position insert_between(const T& value, position left, position right) {
        position node = new Node(value, left, right);
        left->next = node;
        right->prev = node;
        ++size_;
        return node;
    }

    position node_at(int index) const {
        assert(0 <= index && index < static_cast<int>(size_));
        if (index < static_cast<int>(size_ / 2)) {
            position p = header_.next;
            for (int i = 0; i < index; ++i) {
                p = p->next;
            }
            return p;
        }
        position p = trailer_.prev;
        for (int i = static_cast<int>(size_) - 1; i > index; --i) {
            p = p->prev;
        }
        return p;
    }

public:
    CleanList() {
        init_empty();
    }

    CleanList(std::initializer_list<T> init) : CleanList() {
        for (const auto& value : init) {
            push_back(value);
        }
    }

    CleanList(const CleanList& other) : CleanList() {
        for (const auto& value : other.to_vector()) {
            push_back(value);
        }
    }

    CleanList& operator=(const CleanList& other) {
        if (this != &other) {
            clear();
            for (const auto& value : other.to_vector()) {
                push_back(value);
            }
        }
        return *this;
    }

    CleanList(CleanList&& other) noexcept : CleanList() {
        if (!other.empty()) {
            header_.next = other.header_.next;
            trailer_.prev = other.trailer_.prev;
            header_.next->prev = &header_;
            trailer_.prev->next = &trailer_;
            size_ = other.size_;
            other.init_empty();
        }
    }

    CleanList& operator=(CleanList&& other) noexcept {
        if (this != &other) {
            clear();
            if (!other.empty()) {
                header_.next = other.header_.next;
                trailer_.prev = other.trailer_.prev;
                header_.next->prev = &header_;
                trailer_.prev->next = &trailer_;
                size_ = other.size_;
                other.init_empty();
            }
        }
        return *this;
    }

    ~CleanList() {
        clear();
    }

    int size() const {
        return static_cast<int>(size_);
    }

    bool empty() const {
        return size_ == 0;
    }

    position first() {
        return header_.next;
    }

    const_position first() const {
        return header_.next;
    }

    position last() {
        return trailer_.prev;
    }

    const_position last() const {
        return trailer_.prev;
    }

    bool valid(const_position p) const {
        return p != nullptr && p != &header_ && p != &trailer_;
    }

    void clear() {
        position p = header_.next;
        while (p != &trailer_) {
            position next = p->next;
            delete p;
            p = next;
        }
        init_empty();
    }

    position insertFirst(const T& value) {
        return insert_between(value, &header_, header_.next);
    }

    position insertLast(const T& value) {
        return insert_between(value, trailer_.prev, &trailer_);
    }

    position insert(const T& value, position p) {
        assert(p == &trailer_ || valid(p));
        return insert_between(value, p->prev, p);
    }

    position insert_before(position p, const T& value) {
        return insert(value, p);
    }

    position insert_after(position p, const T& value) {
        assert(valid(p));
        return insert_between(value, p, p->next);
    }

    void push_front(const T& value) {
        insertFirst(value);
    }

    void push_back(const T& value) {
        insertLast(value);
    }

    bool add(const T& value) {
        push_back(value);
        return true;
    }

    void add(int index, const T& value) {
        assert(0 <= index && index <= static_cast<int>(size_));
        if (index == static_cast<int>(size_)) {
            insertLast(value);
        } else {
            insert(value, node_at(index));
        }
    }

    T front() const {
        assert(!empty());
        return header_.next->data;
    }

    T back() const {
        assert(!empty());
        return trailer_.prev->data;
    }

    position operator[](int index) {
        return node_at(index);
    }

    const_position operator[](int index) const {
        return node_at(index);
    }

    T get(int index) const {
        return node_at(index)->data;
    }

    T set(int index, const T& value) {
        position p = node_at(index);
        T old = p->data;
        p->data = value;
        return old;
    }

    T remove(position p) {
        assert(valid(p));
        T value = p->data;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        --size_;
        return value;
    }

    T remove(int index) {
        return remove(node_at(index));
    }

    position find(const T& value) {
        for (position p = trailer_.prev; p != &header_; p = p->prev) {
            if (p->data == value) {
                return p;
            }
        }
        return nullptr;
    }

    const_position find(const T& value) const {
        for (const_position p = trailer_.prev; p != &header_; p = p->prev) {
            if (p->data == value) {
                return p;
            }
        }
        return nullptr;
    }

    position search(const T& value) {
        position best = &header_;
        for (position p = header_.next; p != &trailer_; p = p->next) {
            if (!(value < p->data)) {
                best = p;
            } else {
                break;
            }
        }
        return best;
    }

    const_position search(const T& value) const {
        const_position best = &header_;
        for (const_position p = header_.next; p != &trailer_; p = p->next) {
            if (!(value < p->data)) {
                best = p;
            } else {
                break;
            }
        }
        return best;
    }

    bool contains(const T& value) const {
        return valid(find(value));
    }

    int find_index(const T& value) const {
        int index = 0;
        for (const_position p = header_.next; p != &trailer_; p = p->next, ++index) {
            if (p->data == value) {
                return index;
            }
        }
        return -1;
    }

    void sort() {
        std::vector<T> values = to_vector();
        std::stable_sort(values.begin(), values.end());
        position p = header_.next;
        for (const auto& value : values) {
            p->data = value;
            p = p->next;
        }
    }

    int dedup() {
        int removed = 0;
        for (position p = header_.next; p != &trailer_; p = p->next) {
            position q = p->next;
            while (q != &trailer_) {
                position next = q->next;
                if (q->data == p->data) {
                    remove(q);
                    ++removed;
                }
                q = next;
            }
        }
        return removed;
    }

    int deduplicate() {
        return dedup();
    }

    int uniquify() {
        if (size_ < 2) {
            return 0;
        }
        int removed = 0;
        position p = header_.next;
        while (p != &trailer_ && p->next != &trailer_) {
            if (p->data == p->next->data) {
                remove(p->next);
                ++removed;
            } else {
                p = p->next;
            }
        }
        return removed;
    }

    void reverse() {
        std::vector<T> values = to_vector();
        std::reverse(values.begin(), values.end());
        position p = header_.next;
        for (const auto& value : values) {
            p->data = value;
            p = p->next;
        }
    }

    template <class Visitor>
    void traverse(Visitor visitor) {
        for (position p = header_.next; p != &trailer_; p = p->next) {
            visitor(p->data);
        }
    }

    template <class Visitor>
    void traverse(Visitor visitor) const {
        for (const_position p = header_.next; p != &trailer_; p = p->next) {
            visitor(p->data);
        }
    }

    std::vector<T> to_vector() const {
        std::vector<T> values;
        values.reserve(size_);
        for (const_position p = header_.next; p != &trailer_; p = p->next) {
            values.push_back(p->data);
        }
        return values;
    }
};

} // namespace cc232
