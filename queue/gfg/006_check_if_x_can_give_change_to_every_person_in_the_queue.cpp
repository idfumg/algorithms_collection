#include "../../template.hpp"

bool CanHeGiveTheChange(vi arr) {
    int current = 0;
    int fives = 0;
    int tens = 0;
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        if (arr[i] == 5) {
            fives += 1;
        }
        else {
            if (arr[i] == 10) {
                if (fives != 0) {
                    fives -= 1;
                    tens += 1;
                }
                else {
                    return false;
                }
            }
            else if (arr[i] == 20) {
                if (tens != 0 and fives != 0) {
                    tens -= 1;
                    fives -= 1;
                }
                else if (tens == 0 and fives >= 3) {
                    fives -= 3;
                }
                else {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() { TimeMeasure _;
    cout << CanHeGiveTheChange({5, 5, 5, 10, 20}) << endl; // yes
    cout << CanHeGiveTheChange({5, 10, 10, 20}) << endl; // no
}
