#include "../template.hpp"

template<class T, std::uint64_t SIZE = 4096>
class CircularQueue {
private:
    static constexpr std::uint64_t Log2(std::uint64_t n) noexcept {
        std::uint64_t p = 0;
        for (; n > 1; n /= 2, ++p){}
        return p;
    }
    static constexpr std::uint64_t mMask = (1ULL << (Log2(SIZE) + 1)) - 1;
    static constexpr std::uint64_t mSize = (1ULL << (Log2(SIZE) + 1));

    std::uint64_t mReadPos = 0;
    std::uint64_t mWritePos = 0;
    T mArr[mSize];

public:
    bool isEmpty() const noexcept {
        return size() == 0;
    }

    bool isFull() const noexcept {
        return size() == SIZE;
    }

    std::uint64_t size() const noexcept {
        return mWritePos >= mReadPos
            ? (mWritePos - mReadPos)
            : (mSize - (mReadPos - mWritePos) - 1);
    }

    const T& front() const {
        if (isEmpty()) {
            throw std::runtime_error("The Queue is empty!");
        }
        return mArr[mReadPos];
    }

    void pop() {
        if (isEmpty()) {
            throw std::runtime_error("The Queue is empty!");
        }
        mReadPos = ++mReadPos & mMask;
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
    for (int i = 0; i < 8; ++i) {
        q.push(i);
    }
    assert(q.size() == 8);
    assert(q.isFull());
    for (int i = 0; i < 8; ++i) {
        assert(q.front() == i);
        q.pop();
    }
    assert(q.size() == 0);
    assert(not q.isFull());
    assert(q.isEmpty());
    CircularQueue<std::string> q2;
    q2.push("asd");
    assert(q2.size() == 1);
}
