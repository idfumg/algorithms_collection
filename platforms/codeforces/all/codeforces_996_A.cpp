#define IS_TEST 0
#include <bits/stdc++.h>

// https://codeforces.com/contest/996/problem/A

using namespace std;

using ll = int64_t;

ll go1(ll n, ll i, const vector<int>& v, ll minbills, ll bills) {
    if (n < 0 or i < 0) return minbills;
    if (n == v[i]) {
        minbills = min({minbills, bills + 1});
        return minbills;
    }
    if (bills >= minbills) return minbills;
    if (n < v[i]) return go1(n, i - 1, v, minbills, bills);

    minbills = go1(n - v[i], i, v, minbills, bills + 1);
    minbills = go1(n, i - 1, v, minbills, bills);
    return minbills;
}

int go2(ll n, const vector<int>& v) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    int res = INT_MAX;

    for (int j = 0; j < v.size(); ++j) {
        for (int sum = 1; sum <= n; ++sum) {
            int newsum = sum - v[j];
            if (newsum >= 0 and dp[newsum] != INT_MAX) {
                dp[sum] = min({dp[sum], dp[newsum] + 1});
            }
        }
    }

    return dp[n];
}

int go3(ll n, vector<int> v) {
    sort(v.rbegin(), v.rend());
    int current = 0;
    int res = 0;
    for (int i = 0; i < v.size(); ++i) {
        while (current + v[i] <= n) {
            current += v[i];
            ++res;
        }
    }
    return res;
}

int go(ll n, const vector<int>& v) {
    //return go1(n, v.size() - 1, v, INT_MAX, 0);
    return go3(n, v);
}

void solve(istream& ss) {
    int64_t n;
    ss >> n;
    vector<int> v = {100,20,10,5,1};
    //vector<int> v = {1,5,10,20,100};
    cout << go(n, v) << '\n';
}

void test() {
    {
        istringstream ss("125");
        solve(ss);
    }
    {
        istringstream ss("43");
        solve(ss);
    }
    {
        istringstream ss("10000");
        solve(ss);
    }
    {
        istringstream ss("1000000000");
        solve(ss);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#if IS_TEST == 1
    test();
#else
    solve(cin);
#endif

    return 0;
}
