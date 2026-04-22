#include <cassert>
#include "LinkedStack.h"
#include "LinkedQueue.h"
#include "LinkedDeque.h"

int main() {
    {
        ods::LinkedStack<int> st;
        assert(st.empty());
        st.push(10);
        st.push(20);
        st.push(30);
        assert(st.size() == 3);
        assert(st.top() == 30);
        assert(st.pop() == 30);
        assert(st.pop() == 20);
        assert(st.pop() == 10);
        assert(st.empty());
    }

    {
        ods::LinkedQueue<int> q;
        assert(q.empty());
        q.add(1);
        q.add(2);
        q.add(3);
        assert(q.size() == 3);
        assert(q.front() == 1);
        assert(q.remove() == 1);
        assert(q.front() == 2);
        assert(q.remove() == 2);
        assert(q.remove() == 3);
        assert(q.empty());
    }

    {
        ods::LinkedDeque<int> dq;
        assert(dq.empty());
        dq.addFirst(20);
        dq.addFirst(10);
        dq.addLast(30);
        dq.addLast(40);
        assert(dq.size() == 4);
        assert(dq.front() == 10);
        assert(dq.back() == 40);
        assert(dq.removeFirst() == 10);
        assert(dq.removeLast() == 40);
        assert(dq.front() == 20);
        assert(dq.back() == 30);
        assert(dq.removeFirst() == 20);
        assert(dq.removeLast() == 30);
        assert(dq.empty());
    }

    return 0;
}
