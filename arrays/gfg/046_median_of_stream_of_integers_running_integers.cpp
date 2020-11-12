#include "../../template.hpp"

template<class T, class U>
int Avg(T& left, U& right) {
    return (left.top() + right.top()) / 2;
}

template<class T, class U>
int PrintMedian(T& left, U& right, int elem) {
    if (left.empty() and right.empty()) {
        left.push(elem);
        return left.top();
    }

    if (left.size() == right.size()) {
        if (elem > Avg(left, right)) {
            right.push(elem);
            return right.top();
        }
        else {
            left.push(elem);
            return left.top();
        }
    }

    if (left.size() < right.size()) {
        if (elem < right.top()) {
            left.push(elem);
        }
        else {
            left.push(right.top());
            right.pop();
            right.push(elem);
        }
        return Avg(left, right);
    }

    if (elem > left.top()) {
        right.push(elem);
    }
    else {
        right.push(left.top());
        left.pop();
        left.push(elem);
    }
    return Avg(left, right);
}

void MediansOfTheStream(vi arr) {
    priority_queue<int, vector<int>, less<int>> left;
    priority_queue<int, vector<int>, greater<int>> right;
    for (int i = 0; i < arr.size(); ++i) {
        cout << PrintMedian(left, right, arr[i]) << ' ';
    }
}

int main() { TimeMeasure _;
    MediansOfTheStream({5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4}); // 5 10 5 4 3 4 5 6 7 6 7 6
}
