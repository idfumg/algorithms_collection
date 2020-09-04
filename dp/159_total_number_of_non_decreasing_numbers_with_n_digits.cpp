#include "../template.hpp"

int countUtil(int n, int d) {
    if (n == 0) {
        return 1;
    }

    int count = 0;
    for (int i = 0; i <= d; i++) {
        count += countUtil(n - 1, i);
    }
    return count;

}

int count(int n) {
    int c = 0;
    for (int i = 0; i <= 9; i++){
        c += countUtil(n - 1, i);
    }
    return c;
}

int main() { TimeMeasure _; __x();
    cout << count(1) << endl;
    cout << count(2) << endl;
    cout << count(3) << endl;
}
