#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    int m = sqrt(n);
    for (int i = 3; i <= m; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    return 0;
}
