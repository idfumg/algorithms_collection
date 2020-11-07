//#include "../../template.hpp"

#include <bits/stdc++.h>

using namespace std;

int HowMuchRemains(int H, int W, int h, int w) {
    return (H - h) * (W - w);
}

void PrintHowMuchRemains(int H, int W, int h, int w) {
    cout << HowMuchRemains(H, W, h, w)<< '\n';
}

int main() {
    int H;
    int W;
    int h;
    int w;

    cin >> H;
    cin >> W;
    cin >> h;
    cin >> w;

    PrintHowMuchRemains(H, W, h, w);
}
