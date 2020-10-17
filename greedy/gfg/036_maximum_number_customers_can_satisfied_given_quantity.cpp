#include "../../template.hpp"

void MaxNumOfCustomersWhichCanBuyRice(const string& s) {
    istringstream is(s);
    int n; is >> n;
    int d; is >> d;
    int a; is >> a;
    int b; is >> b;
    vi cost(n);
    for (int i = 0; i < n; ++i) {
        int x; is >> x;
        int y; is >> y;
        cost[i] = x * a + y * b;
    }

    vi idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int x, int y){return cost[x] < cost[y];});

    vi customers;
    for (int i = 0; i < n; ++i) {
        if (cost[idx[i]] > d) break;
        d -= cost[idx[i]];
        customers.push_back(idx[i] + 1);
    }

    cout << customers.size() << '\n' << customers << '\n' << '\n';
}

int main() { TimeMeasure _;
    static const string in1 = R"(5 5
        1 1
        2 0
        3 2
        4 4
        10 0
        0 1)";
    static const string in2 = R"(6 1000000000
       9999 10000
       10000 9998
       10000 10000
       10000 10000
       70000 70000
       10000 10000
       10000 10000)";

    MaxNumOfCustomersWhichCanBuyRice(in1);
    MaxNumOfCustomersWhichCanBuyRice(in2);
}
