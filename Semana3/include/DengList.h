#pragma once

#include "CleanList.h"

namespace cc232 {

template <class T>
class DengList {
public:
    using legacy_type = CleanList<T>;
    using node_type = typename legacy_type::node_type;
    using position = typename legacy_type::position;

private:
    legacy_type impl_;

public:
    DengList() = default;
    DengList(const DengList&) = default;
    DengList& operator=(const DengList&) = default;
    DengList(DengList&&) noexcept = default;
    DengList& operator=(DengList&&) noexcept = default;
    ~DengList() = default;

    int size() const { return impl_.size(); }
    bool empty() const { return impl_.empty(); }
    void clear() { impl_.clear(); }

    void push_front(const T& value) { impl_.push_front(value); }
    void push_back(const T& value) { impl_.push_back(value); }
    bool add(const T& value) { return impl_.add(value); }
    void add(int index, const T& value) { impl_.add(index, value); }

    T front() const { return impl_.front(); }
    T back() const { return impl_.back(); }
    T get(int index) const { return impl_.get(index); }
    T set(int index, const T& value) { return impl_.set(index, value); }
    T remove(int index) { return impl_.remove(index); }

    bool contains(const T& value) const { return impl_.contains(value); }
    int find_index(const T& value) const { return impl_.find_index(value); }

    void sort() { impl_.sort(); }
    int dedup() { return impl_.dedup(); }
    int uniquify() { return impl_.uniquify(); }
    void reverse() { impl_.reverse(); }

    std::vector<T> to_vector() const { return impl_.to_vector(); }

    const legacy_type& raw() const { return impl_; }
    legacy_type& raw() { return impl_; }
};

} // namespace cc232
