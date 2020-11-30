#include "../template.hpp"

template<class T>
bool compare(const T& a, const T& b) { return a > b; }

template<class T>
void heap_heapify(vector<T>& heap, int i, int n) {
    int l = i * 2 + 1, r = i * 2 + 2;
    while (true) {
        int smallest = i;
        if (l < n and compare(heap[smallest], heap[l])) smallest = l;
        if (r < n and compare(heap[smallest], heap[r])) smallest = r;
        if (i == smallest) break;
        swap(heap[smallest], heap[i]);
        i = smallest;
        l = i * 2 + 1;
        r = i * 2 + 2;
    }
}

template<class T>
void heap_rise(vector<T>& heap, int i) {
    for (; i >= 0 and compare(heap[i / 2], heap[i]); i = i / 2) {
        swap(heap[i / 2], heap[i]);
    }
}

template<class T>
void heap_push(vector<T>& heap, int key) {
    heap.push_back(key);
    heap_rise(heap, heap.size() - 1);
}

template<class T>
void heap_update(vector<T>& heap, int i, int key) {
    heap[i] = key;
    heap_rise(heap, i);
    heap_heapify(heap, i, heap.size());
}

template<class T>
void heap_pop(vector<T>& heap) {
    heap[0] = heap.back();
    heap.pop_back();
    heap_heapify(heap, 0, heap.size());
}

template<class T>
void heap_make(vector<T>& heap) {
    for (int i = heap.size() / 2; i >= 0; --i) {
        heap_heapify(heap, i, heap.size());
    }
}

template<class T>
void heap_sort(vector<T>& heap) {
    heap_make(heap);
    for (int i = heap.size() - 1; i >= 1; --i) {
        swap(heap[0], heap[i]);
        heap_heapify(heap, 0, i);
    }
}

void HeapInit(vector<int> values) {
    heap_make(values);

    auto it = find(values.begin(), values.end(), 9);
    int i = it - values.begin();
    heap_update(values, i, -100); // update down

    auto it2 = find(values.begin(), values.end(), 2);
    int j = it2 - values.begin();
    heap_update(values, j, 100); // update up

    while (not values.empty()) {
        cout << values[0] << ' ';
        heap_pop(values);
    }
    cout << endl;
}

void HeapSort(vector<int> values) {
    heap_sort(values);
    cout << values << endl;
}

int main() { TimeMeasure _;
    HeapInit({3, 2, 15, 9, 4, 45, 6});
    HeapSort({5, 3, 1, 2, 4, -2, -40, 100});
}
