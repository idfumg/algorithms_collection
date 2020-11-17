#include "../../template.hpp"

class Queue {
public:
    Queue(int n)
        : n(n),
          start(0),
          stop(0)
    {
        arr.resize(n);
    }

    int size() {
        if (start == -1) {
            return 0;
        }
        else if (start <= stop) {
            return stop - start;
        }
        return n  - (start - stop + 1);
    }

    bool isFull() {
        return stop + 1 == start;
    }

    bool isEmpty() {
        return stop == start;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        arr[stop++] = value;
        if (stop >= n) {
            stop -= n;
        }
        if (start == stop) {
            swap(start, stop);
            if (stop == 0) {
                stop = n - 1;
            }
            else {
                stop = stop - 1;
            }
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return INF;
        }
        int value = arr[start++];
        if (start >= n) {
            start -= n;
        }

        return value;
    }

    void displayQueue() {
        cout << "Elements in queue: ";
        if (start == stop) {
        }
        else if (start < stop) {
            for (int i = start; i < stop; ++i) {
                cout << arr[i] << ' ';
            }
        }
        else {
            for (int i = start; i < n; ++i) {
                cout << arr[i] << ' ';
            }
            for (int i = 0; i < stop; ++i) {
                cout << arr[i] << ' ';
            }
        }
        cout << endl;
    }

private:
    int n;
    int start;
    int stop;
    vi arr;
};

int main() { TimeMeasure _;
    Queue q(6);

    // Inserting elements in Circular Queue
    q.enqueue(14);
    q.enqueue(22);
    q.enqueue(13);
    q.enqueue(-6);

    cout << "Size: " << q.size() << endl; // 4

    // Display elements present in Circular Queue
    q.displayQueue();

    // Deleting elements from Circular Queue
    cout << "Deleted value = " << q.dequeue() << endl;
    cout << "Deleted value = " << q.dequeue() << endl;

    q.displayQueue();
    cout << "Size: " << q.size() << endl; // 2

    q.enqueue(9);
    q.displayQueue();
    q.enqueue(20);
    q.displayQueue();
    q.enqueue(5);
    q.displayQueue();

    cout << "Size: " << q.size() << endl; // 5

    q.enqueue(20);
}
