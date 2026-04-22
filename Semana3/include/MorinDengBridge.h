#pragma once

#include <vector>

#include "DLList.h"
#include "SEList.h"
#include "DengList.h"

namespace cc232 {

template <class T>
std::vector<T> to_vector(ods::DLList<T>& src) {
    std::vector<T> out;
    out.reserve(src.size());
    for (int i = 0; i < src.size(); ++i) {
        out.push_back(src.get(i));
    }
    return out;
}

template <class T>
std::vector<T> to_vector(ods::SEList<T>& src) {
    std::vector<T> out;
    out.reserve(src.size());
    for (int i = 0; i < src.size(); ++i) {
        out.push_back(src.get(i));
    }
    return out;
}

template <class T>
DengList<T> to_deng(ods::DLList<T>& src) {
    DengList<T> out;
    for (int i = 0; i < src.size(); ++i) {
        out.push_back(src.get(i));
    }
    return out;
}

template <class T>
DengList<T> to_deng(ods::SEList<T>& src) {
    DengList<T> out;
    for (int i = 0; i < src.size(); ++i) {
        out.push_back(src.get(i));
    }
    return out;
}

template <class T>
void assign_from_deng(ods::DLList<T>& dst, const DengList<T>& src) {
    dst.clear();
    for (const auto& value : src.to_vector()) {
        dst.add(value);
    }
}

template <class T>
void assign_from_deng(ods::SEList<T>& dst, const DengList<T>& src) {
    dst.clear();
    int index = 0;
    for (const auto& value : src.to_vector()) {
        dst.add(index++, value);
    }
}

template <class T>
void stable_sort_with_deng(ods::DLList<T>& src) {
    auto tmp = to_deng(src);
    tmp.sort();
    assign_from_deng(src, tmp);
}

template <class T>
void stable_sort_with_deng(ods::SEList<T>& src) {
    auto tmp = to_deng(src);
    tmp.sort();
    assign_from_deng(src, tmp);
}

template <class T>
int dedup_with_deng(ods::DLList<T>& src) {
    auto tmp = to_deng(src);
    int removed = tmp.dedup();
    assign_from_deng(src, tmp);
    return removed;
}

template <class T>
int dedup_with_deng(ods::SEList<T>& src) {
    auto tmp = to_deng(src);
    int removed = tmp.dedup();
    assign_from_deng(src, tmp);
    return removed;
}

template <class T>
void reverse_with_deng(ods::DLList<T>& src) {
    auto tmp = to_deng(src);
    tmp.reverse();
    assign_from_deng(src, tmp);
}

template <class T>
void reverse_with_deng(ods::SEList<T>& src) {
    auto tmp = to_deng(src);
    tmp.reverse();
    assign_from_deng(src, tmp);
}

} // namespace cc232
