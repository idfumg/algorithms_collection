//#include "../../template.hpp"

#include <bits/stdc++.h>

using namespace std;

int GetMaxDiff(int N, int K) {
    if (N == K) {
        return 0;
    }

    if (N < K) {
        return 1;
    }

    int rem = N % K;

    if (rem == 0) {
        return 0;
    }

    return 1;
}

int main() {
    int N;
    int K;
    cin >> N;
    cin >> K;

    cout << GetMaxDiff(N, K) << '\n';
}
