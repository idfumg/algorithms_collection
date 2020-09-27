#include "../template.hpp"

template<class T, std::uint64_t SIZE = 4096>
class CircularQueue {
private:
    static constexpr std::uint64_t Log2(std::uint64_t n) noexcept {
        std::uint64_t p = 0;
        for (; n > 1; n /= 2, ++p){}
        return p;
    }
    static constexpr std::uint64_t mMask = (1ULL << (Log2(SIZE - 1) + 1)) - 1;
    static constexpr std::uint64_t mSize = 1ULL << (Log2(SIZE - 1) + 1);

    std::uint64_t mReadPos = 0;
    std::uint64_t mWritePos = 0;
    T mArr[mSize];

public:
    bool isEmpty() const noexcept {
        return size() == 0;
    }

    bool isFull() const noexcept {
        return mSize - size() == 1;
    }

    const T& front() const noexcept {
        return mArr[mReadPos];
    }

    void pop()  {
        if (isEmpty()) {
            throw std::runtime_error("The Queue is empty!");
        }
        mReadPos = ++mReadPos & mMask;
    }

    std::uint64_t size() const noexcept {
        return mWritePos >= mReadPos
            ? (mWritePos - mReadPos)
            : (mSize - (mReadPos - mWritePos));
    }

    void push(const T& elem) {
        if (isFull()) {
            throw std::runtime_error("The Queue is full!");
        }
        mArr[mWritePos & mMask] = elem;
        mWritePos = ++mWritePos & mMask;
    }
};

int main() { TimeMeasure _;
    CircularQueue<int, 8> q;
    assert(q.isEmpty());
    q.push(1);
    assert(q.front() == 1);
    assert(q.size() == 1);
    q.push(2);
    assert(q.size() == 2);
    q.push(3);
    assert(q.size() == 3);
    q.push(4);
    assert(q.front() == 1);
    assert(q.size() == 4);
    q.pop();
    assert(q.front() == 2);
    assert(q.size() == 3);
    q.push(1);
    assert(q.size() == 4);
    q.push(5);
    assert(q.size() == 5);
    q.push(6);
    assert(q.size() == 6);
    q.push(7);
    assert(q.size() == 7);
    assert(q.isFull());
    q.pop();
    assert(q.size() == 6);
    assert(not q.isFull());
    q.push(111);
    assert(q.size() == 7);
    assert(q.isFull());
    q.pop();
    q.pop();
    assert(q.size() == 5);
    q.pop();
    q.pop();
    q.pop();
    assert(q.size() == 2);
    assert(q.front() == 7);
    q.pop();
    assert(q.front() == 111);
    q.pop();
    assert(q.size() == 0);
    assert(not q.isFull());
    assert(q.isEmpty());
    CircularQueue<std::string> q2;
    q2.push("asd");
    assert(q2.size() == 1);
}
