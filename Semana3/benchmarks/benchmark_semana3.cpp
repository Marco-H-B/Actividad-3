#include <chrono>
#include <iostream>
#include "ArrayDeque.h"
#include "LinkedQueue.h"
#include "LinkedDeque.h"
#include "DLList.h"

using Clock = std::chrono::steady_clock;

namespace {

template<class F>
long long measure_us(F&& f) {
    const auto start = Clock::now();
    f();
    const auto end = Clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

template<class T>
class ArrayQueueOnDeque {
private:
    ods::ArrayDeque<T> dq;

public:
    bool add(const T& x) {
        return dq.add(x);
    }

    T remove() {
        return dq.remove(0);
    }
};

} // namespace

int main() {
    constexpr int n = 50000;

    const auto t_array_queue = measure_us([&]() {
        ArrayQueueOnDeque<int> q;
        for (int i = 0; i < n; ++i) q.add(i);
        for (int i = 0; i < n; ++i) q.remove();
    });

    const auto t_linked_queue = measure_us([&]() {
        ods::LinkedQueue<int> q;
        for (int i = 0; i < n; ++i) q.add(i);
        for (int i = 0; i < n; ++i) q.remove();
    });

    const auto t_array_deque_ends = measure_us([&]() {
        ods::ArrayDeque<int> dq;
        for (int i = 0; i < n; ++i) dq.add(dq.size(), i);
        for (int i = 0; i < n / 2; ++i) dq.remove(0);
        for (int i = 0; i < n / 2; ++i) dq.remove(dq.size() - 1);
    });

    const auto t_linked_deque_ends = measure_us([&]() {
        ods::LinkedDeque<int> dq;
        for (int i = 0; i < n; ++i) dq.addLast(i);
        for (int i = 0; i < n / 2; ++i) dq.removeFirst();
        for (int i = 0; i < n / 2; ++i) dq.removeLast();
    });

    const auto t_array_random_get = measure_us([&]() {
        ods::ArrayDeque<int> arr;
        for (int i = 0; i < n; ++i) arr.add(i, i);
        long long sink = 0;
        for (int i = 0; i < n; i += 17) sink += arr.get(i);
        std::cout << "checksum_array=" << sink << "\n";
    });

    const auto t_linked_random_get = measure_us([&]() {
        ods::DLList<int> lst;
        for (int i = 0; i < n; ++i) lst.add(i, i);
        long long sink = 0;
        for (int i = 0; i < n; i += 17) sink += lst.get(i);
        std::cout << "checksum_linked=" << sink << "\n";
    });

    std::cout << "benchmark_semana3 (microsegundos)\n";
    std::cout << "queue_contigua_sobre_arraydeque : " << t_array_queue << "\n";
    std::cout << "queue_enlazada_linkedqueue      : " << t_linked_queue << "\n";
    std::cout << "deque_contiguo_arraydeque       : " << t_array_deque_ends << "\n";
    std::cout << "deque_enlazado_linkeddeque      : " << t_linked_deque_ends << "\n";
    std::cout << "random_get_arraydeque           : " << t_array_random_get << "\n";
    std::cout << "random_get_dllist               : " << t_linked_random_get << "\n";

    return 0;
}
