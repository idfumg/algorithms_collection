#include "../template.hpp"

template<class T>
class Heap {
public:
    size_t size() const noexcept { return arr.size(); }
    bool empty() const noexcept { return arr.empty(); }
    T& top() noexcept { return arr[0]; }

    void push(const T& key) {
        arr.push_back(key);
        for (int i = arr.size() - 1; i >= 0 and arr[i] < arr[(i - 1) / 2]; i = (i - 1) / 2) {
            swap(arr[(i - 1) / 2], arr[i]);
        }
    }

    void minHeapify() { // move big value down
        size_t i = 0;
        for (size_t l = 2 * i + 1, r = 2 * i + 2; ; l = 2 * i + 1, r = 2 * i + 2) {
            size_t smallest = i;
            if (l < arr.size() and arr[smallest] > arr[l]) smallest = l;
            if (r < arr.size() and arr[smallest] > arr[r]) smallest = r;
            if (i == smallest) break;
            swap(arr[smallest], arr[i]);
            i = smallest;
        }
    }

    void pop() {
        if (empty()) throw std::runtime_error("The heap is empty");
        swap(arr.front(), arr.back());
        arr.pop_back();
        minHeapify();
    }

    template<class U>
    static void sort(U& arr) {
        Heap heap;
        for (const auto& elem : arr) heap.push(elem);
        for (size_t i = 0; i < arr.size() and not heap.empty(); ++i) {
            arr[i] = heap.top(); heap.pop();
        }
    }

private:
    std::vector<T> arr;
};

int main() { TimeMeasure _;
    Heap<int> heap;
    heap.push(3);
    heap.push(2);
    heap.push(15);
    heap.push(9);
    heap.push(4);
    heap.push(45);
    heap.push(6);

    cout << "heap size = " << heap.size() << endl;
    cout << "heap top = " << heap.top() << endl;
    heap.pop();
    cout << "heap top = " << heap.top() << endl;
    heap.pop();
    cout << "heap top = " << heap.top() << endl;
    heap.pop();
    cout << "heap top = " << heap.top() << endl;

    std::vector<int> arr = {5, 3, 1, 2, 4, -2, -40, 100};
    Heap<int>::sort(arr);
    debugn(arr);
}
