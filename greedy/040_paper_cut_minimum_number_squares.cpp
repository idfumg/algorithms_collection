#include "../template.hpp"

int CutPaperIntoSquares(int height, int width) {
    int ans = 0;
    while (height > 0 and width > 0) {
        if (height > width) {
            swap(height, width);
        }
        int count = width / height;
        if (count > 0) {
            width -= height * count;
            ans += count;
        }
    }
    return ans;
}

int main() { TimeMeasure _;
    cout << CutPaperIntoSquares(13, 29) << '\n'; // 9
    cout << CutPaperIntoSquares(4, 5) << '\n'; // 5
}
