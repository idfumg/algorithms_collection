#include "../../template.hpp"

void ClosestWithoutTheSameAdjacent(string s) {
    int n = s.size();
    for (int i = 1; i < n - 1; ++i) {
        if (s[i] == s[i - 1] or s[i] == s[i + 1]) {
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                if (ch != s[i - 1] and ch != s[i + 1]) {
                    s[i] = ch;
                    break;
                }
            }
        }
    }
    cout << s << '\n';
}

int main() { TimeMeasure _; __x();
    ClosestWithoutTheSameAdjacent("aab");
    ClosestWithoutTheSameAdjacent("geeksforgeeks");
}
