#include "../template.hpp"

string LargestCube(int num) {
    vector<string> cubes;
    for (int i = 1; i * i * i <= num; ++i) {
        cubes.push_back(to_string(i * i * i));
    }
    string number = to_string(num);
    int k = cubes.size(), m = number.size();
    for (int i = k - 1; i >= 0; --i) {
        const string& cube = cubes[i];
        int n = cube.size(), idx = 0;
        for (int j = 0; j < m and idx < n; ++j) {
            if (cube[idx] == number[j]) {
                ++idx;
            }
        }
        if (idx == n) return cube;
    }
    return "Not possible";
}

int main() { TimeMeasure _; __x();
    cout << LargestCube(4125) << '\n';
    cout << LargestCube(876) << '\n';
}
