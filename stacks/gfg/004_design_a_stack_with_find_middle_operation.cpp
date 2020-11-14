#include "../../template.hpp"

class Stack {
public:
    void push(int value) {
        L.push_back(value);
        if (middle == L.end()) {
            middle = L.begin();
        }
    }

    int pop() {
        if (L.empty()) {
            throw runtime_error("Stack is empty");
        }
        int value = L.back();
        L.pop_back();
        ++middle;
        return value;
    }

    int findMiddle() {
        if (L.empty()) {
            throw runtime_error("Stack is empty");
        }
        return *middle;
    }

private:
    list<int> L;
    list<int>::iterator middle = L.end();
};

int main() { TimeMeasure _;
    Stack s;

    s.push(11);
    s.push(22);
    s.push(33);
    s.push(44);
    s.push(55);
    s.push(66);
    s.push(77);

    cout << "Item popped is " << s.pop() << '\n';
    cout << "Item popped is " << s.pop() << '\n';
    cout << "Middle Element is " << s.findMiddle() << '\n';
}
