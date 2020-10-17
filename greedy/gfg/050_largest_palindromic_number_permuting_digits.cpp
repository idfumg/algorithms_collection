#include "../../template.hpp"

void GenPalindrome(int n) {
    vi freq(10);
    while (n > 0) {
        ++freq[n % 10];
        n /= 10;
    }

    int odd = 0, oddNumber = -1;
    for (int i = 0; i <= 9; ++i) {
        if (freq[i] % 2 != 0) {
            ++odd;
            oddNumber = i;
        }
    }

    if (odd > 1) {
        cout << "Palindrome cannot be formed" << '\n';
        return;
    }

    string ans;
    for (int i = 9; i >= 0; --i) {
        if (freq[i] > 0) {
            int count = freq[i] / 2;
            ans += string(count, i + '0');
        }
    }

    if (oddNumber != -1) {
        cout << ans << oddNumber;
    }
    else {
        cout << ans;
    }
    reverse(ans);
    cout << ans << '\n';
}

void GenPalindrome2(int n) {
    vi freq(10);
    while (n > 0) {
        ++freq[n % 10];
        n /= 10;
    }

    int ans = 0, odd = 0, oddNumber = -1;
    for (int i = 9; i >= 0; --i) {
        if (freq[i] == 0) {
            continue;
        }
        else if (freq[i] & 1) {
            ++odd;
            oddNumber = i;
        }
        else {
            int count = freq[i] / 2;
            while (count-- > 0) {
                ans = ans == 0 ? i : ans * 10 + i;
            }
        }
    }

    if (odd > 1) {
        cout << "Palindrome cannot be formed" << '\n';
        return;
    }

    int rev = 0, temp = ans;
    while (temp > 0) {
        rev = rev == 0 ? temp % 10 : rev * 10 + temp % 10;
        temp /= 10;
    }

    if (oddNumber != -1) {
        cout << ans << oddNumber << rev << '\n';
    }
    else {
        cout << ans << rev << '\n';
    }
}

int main() { TimeMeasure _; __x();
    GenPalindrome(35135515); // 55311355
    GenPalindrome(313551); // 531135
    GenPalindrome(331); // 313
    GenPalindrome(3444); // Palindrome cannot be formed
    GenPalindrome2(35135515); // 55311355
    GenPalindrome2(313551); // 531135
    GenPalindrome2(331); // 313
    GenPalindrome2(3444); // Palindrome cannot be formed
}
