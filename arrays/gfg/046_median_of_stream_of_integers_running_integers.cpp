#include "../../template.hpp"

int avg(priority_queue<int>& left, priority_queue<int, vi, greater<int>>& right) {
    if (left.size() > right.size()) return left.top();
    if (left.size() < right.size()) return right.top();
    return (left.top() + right.top()) / 2;
}

int median(priority_queue<int>& left, priority_queue<int, vi, greater<int>>& right, int v) {
    if (left.empty() and right.empty()) {
        left.push(v);
    }
    else if (left.empty() and v < right.top()) {
        left.push(v);
    }
    else if (left.empty() and v > right.top()) {
        left.push(right.top()); right.pop(); right.push(v);
    }
    else if (right.empty() and v > left.top()) {
        right.push(v);
    }
    else if (right.empty() and v < left.top()) {
        right.push(left.top()); left.pop(); left.push(v);
    }
    else if (left.size() == right.size() and v < left.top()) {
        right.push(left.top()); left.pop(); left.push(v);
    }
    else if (left.size() == right.size() and v > right.top()) {
        left.push(right.top()); right.pop(); right.push(v);
    }
    else if (left.size() < right.size() and v > right.top()) {
        left.push(right.top()); right.pop(); right.push(v);
    }
    else if (left.size() < right.size() and v < right.top()) {
        left.push(v);
    }
    else if (left.size() > right.size() and v < left.top()) {
        right.push(left.top()); left.pop(); left.push(v);
    }
    else if (left.size() > right.size() and v > left.top()) {
        right.push(v);
    }
    return avg(left, right);
}

void MediansOfTheStream(vi arr) {
    priority_queue<int> left;
    priority_queue<int, vi, greater<int>> right;
    for (int v : arr) {
        cout << median(left, right, v) << ' ';
    }
}

int main() { TimeMeasure _;
    MediansOfTheStream({5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4}); // 5 10 5 4 3 4 5 6 7 6 7 6
}
