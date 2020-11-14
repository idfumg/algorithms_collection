#include "../../template.hpp"

class Queue {
public:
    Queue() = default;
    ~Queue() = default;
    Queue(const Queue& queue) = default;
    Queue& operator=(const Queue& queue) = default;

public:
    void enqueue(int value) {
        stack1.push(value);
    }

    int dequeue() {
        if (not stack2.empty()) {
            int value = stack2.top(); stack2.pop();
            return value;
        }

        while (not stack1.empty()) {
            int value = stack1.top(); stack1.pop();
            stack2.push(value);
        }
        int value = stack2.top(); stack2.pop();
        return value;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main() { TimeMeasure _;
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << q.dequeue() << '\n'; // 1
    cout << q.dequeue() << '\n'; // 2
    cout << q.dequeue() << '\n'; // 3
}
