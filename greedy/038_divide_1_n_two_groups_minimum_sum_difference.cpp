#include "../template.hpp"

void DivideIntoTwoGroups(int n) {
    int total = n * (n + 1) / 2;
    int left = total / 2;
    int right = total - left;
    vb used(n + 1);

    vi group1, group2;
    for (int i = n; i >= 1; --i) {
        if (i <= left) {
            left -= i;
            group1.push_back(i);
        }
        else {
            right -= i;
            group2.push_back(i);
        }
    }

    cout << group1.size() << '\n' << group1 << '\n';
    cout << group2.size() << '\n' << group2 << '\n';
    cout << '\n';
}

int main() { TimeMeasure _;
    DivideIntoTwoGroups(5);
    DivideIntoTwoGroups(6);
}
