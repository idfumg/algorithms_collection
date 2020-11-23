#include "../../template.hpp"

int RowGcd(vi arr) {
    int ans = arr[0];
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        ans = gcd(ans, arr[i]);
    }
    return ans;
}

int ColumnGcd(vvi arr, int col) {
    int ans = arr[0][col];
    int m = arr.size();
    for (int i = 1; i < m; ++i) {
        ans = gcd(ans, arr[i][col]);
    }
    return ans;
}

vvi ReplaceElementsWithMaxGCDOfRowAndColumn(vvi arr) {
    int m = arr.size();
    int n = arr[0].size();
    vi row(m);
    vi column(n);
    for (int i = 0; i < m; ++i) {
        row[i] = RowGcd(arr[i]);
    }
    for (int i = 0; i < n; ++i) {
        column[i] = ColumnGcd(arr, i);
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            arr[i][j] = max(row[i], column[j]);
        }
    }
    return arr;
}

int main() { TimeMeasure _;
    vvi arr = {
        {1, 2, 3, 3},
        {4, 5, 6, 6},
        {7, 8, 9, 9},
    };

    cout << ReplaceElementsWithMaxGCDOfRowAndColumn(arr) << endl;

/*
1 1 3 3
1 1 3 3
1 1 3 3
*/
}
