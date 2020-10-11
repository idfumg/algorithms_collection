#include "../template.hpp"

void GenPalindrome(int n) {
    unordered_map<char, int> freq;
    while (n > 0) {
        freq[n % 10 + '0'] += 1;
        n /= 10;
    }
    int odd = 0;
    char oddnum = -1;
    for (auto& [key, value] : freq) {
        if (value & 1) {
            ++odd;
            oddnum = key;
        }
    }
    if (odd > 1) {
        cout << "Not possible" << '\n';
    }
    else {
        string ans;
        for (auto& [key, value] : freq) {
            if (not (value & 1)) {
                ans += key;
            }
        }
        if (oddnum != -1) {
            cout << ans << oddnum;
        }
        else {
            cout << ans;
        }
        reverse(ans);
        cout << ans << '\n';
    }
}

void GenPalindrome2(int n) {
    vi freqs(10);
    while (n > 0) {
        ++freqs[n % 10];
        n /= 10;
    }
    int oddNum = -1;
    for (int i = 0; i < 10; ++i) {
        if (freqs[i] & 1) {
            if (oddNum != -1) {
                cout << "Not possible" << '\n';
                return;
            }
            else {
                oddNum = i;
            }
        }
    }
    string ans;
    for (int i = 0; i < 10; ++i) {
        if ((freqs[i] & 1) or freqs[i] == 0) continue;
        ans += i + '0';
    }
    if (oddNum != -1) {
        cout << ans << oddNum;
    }
    else {
        cout << ans;
    }
    reverse(ans);
    cout << ans << '\n';
}

int main() { TimeMeasure _; __x();
    GenPalindrome(313551);
    GenPalindrome(331);
    GenPalindrome(3444);
    GenPalindrome2(313551);
    GenPalindrome2(331);
    GenPalindrome2(3444);
}
