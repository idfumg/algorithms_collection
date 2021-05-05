#include "../../template.hpp"

void GenPalindrome(int num) {
    vi arr(10);
    for (int n = num; n > 0; n /= 10) {
        ++arr[n % 10];
    }
    int odd = -1;
    for (int i = 0; i < 10; ++i) {
        if (arr[i] & 1) {
            if (odd != -1) {
                cout << -1 << endl;
                return;
            }
            else {
                odd = arr[i];
                --arr[i];
            }
        }
    }
    int ans = 0;
    for (int i = 9; i >= 0; --i) {
        for (int count = arr[i] / 2; count > 0; --count) {
            ans = ans * 10 + i;
            --arr[i];
        }
    }
    if (odd != -1) {
        ans = ans * 10 + odd;
    }
    for (int i = 0; i < 10; ++i) {
        for (int count = arr[i]; count > 0; --count) {
            ans = ans * 10 + i;
        }
    }
    cout << ans << endl;
}

int main() { TimeMeasure _; __x();
    GenPalindrome(35135515); // 55311355
    GenPalindrome(313551); // 531135
    GenPalindrome(331); // 313
    GenPalindrome(3444); // Palindrome cannot be formed
}
