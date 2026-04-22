#pragma once

#include <vector>
#include <cassert>

namespace ods {

template<class T>
class array {
    std::vector<T> data_;
public:
    explicit array(int n = 0) : data_(n) {}

    int length() const {
        return static_cast<int>(data_.size());
    }

    T& operator[](int i) {
        assert(0 <= i && i < length());
        return data_[static_cast<std::size_t>(i)];
    }

    const T& operator[](int i) const {
        assert(0 <= i && i < length());
        return data_[static_cast<std::size_t>(i)];
    }
};

} // namespace ods
