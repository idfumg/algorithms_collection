#include "../../template.hpp"

class Stack {
public:
    Stack() = default;
    ~Stack() = default;
    Stack(const Stack& specialStack) = default;
    Stack& operator=(const Stack& specialStack) = default;

public:
    int size() {
        return q1.size() + q2.size();
    }

   void push(int value) {
        q1.push(value);
    }

    int top() {
        while (q1.size() > 1) {
            int value = q1.front(); q1.pop();
            q2.push(value);
        }
        return q1.front();
    }

    void pop() {
        while (q1.size() > 1) {
            int value = q1.front(); q1.pop();
            q2.push(value);
        }
        q1 = move(q2);
        q2 = queue<int>();
    }

private:
    queue<int> q1;
    queue<int> q2;
};

int main() { TimeMeasure _;
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);

    cout << "current size: " << s.size() << '\n';
    cout << s.top() << '\n';

    s.pop();
    cout << s.top() << '\n';

    s.pop();
    cout << s.top() << '\n';

    cout << "current size: " << s.size() << '\n';
}
