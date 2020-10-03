#include "../template.hpp"

template<class T, std::uint64_t SIZE = 4096>
class StaticStack {
private:
    static constexpr std::uint64_t Log2(std::uint64_t n) noexcept {
        std::uint64_t p = 0;
        for (; n > 1; n /= 2, ++p){}
        return p;
    }
    static constexpr std::uint64_t mSize = 1ULL << (Log2(SIZE - 1) + 1);

    std::uint64_t mPos = 0;
    T mArr[mSize];

public:
    bool isEmpty() const noexcept {
        return size() == 0;
    }

    bool isFull() const noexcept {
        return size() == SIZE;
    }

    std::uint64_t size() const noexcept {
        return mPos;
    }

    const T& top() const {
        if (isEmpty()) {
            throw std::runtime_error("The Stack is empty!");
        }
        return mArr[mPos - 1];
    }

    void pop() {
        if (isEmpty()) {
            throw std::runtime_error("The Stack is empty!");
        }
        --mPos;
    }

    void push(const T& elem) {
        if (isFull()) {
            throw std::runtime_error("The Stack is full!");
        }
        mArr[mPos++] = elem;
    }
};

int main() { TimeMeasure _;
    StaticStack<int, 8> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    assert(s.isFull());
    assert(s.size() == 8);
    assert(s.top() == 8);
    s.pop();
    assert(not s.isFull());
    assert(s.top() == 7);
    while (not s.isEmpty()) {
        s.pop();
    }
    assert(not s.isFull());
    assert(s.isEmpty());
    assert(s.size() == 0);
}
