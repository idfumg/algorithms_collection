#include "../../template.hpp"

class SpecialStack {
public:
    SpecialStack() = default;
    ~SpecialStack() = default;
    SpecialStack(const SpecialStack& specialStack) = default;
    SpecialStack& operator=(const SpecialStack& specialStack) = default;

public:
    void push(int value) {
        stack1.push(value);
        if (stack2.empty() or value <= stack2.top()) {
            stack2.push(value);
        }
    }

    int pop() {
        int value = stack1.top(); stack1.pop();
        if (not stack2.empty() and stack2.top() == value) {
            stack2.pop();
        }
        return value;
    }

    int getMin() {
        return stack2.top();
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main() { TimeMeasure _;
    {
        SpecialStack s;

        s.push(10);
        s.push(20);
        s.push(30);

        cout << s.getMin() << '\n'; // 10

        s.push(5);

        cout << s.getMin() << '\n'; // 5
    }
    cout << '\n';
    {
        SpecialStack s;

        s.push(18);
        s.push(19);
        s.push(29);
        s.push(15);
        s.push(16);

        cout << s.getMin() << '\n'; // 15

        s.pop();
        s.pop();

        cout << s.getMin() << '\n'; // 18
    }
}
