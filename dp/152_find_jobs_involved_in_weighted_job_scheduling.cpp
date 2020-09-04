#include "../template.hpp"

struct Job {
    int start, finish, profit;
};

deque<int> tab(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), [](auto a, auto b){return a.finish<b.finish;});
    int n = jobs.size(), maxi = 0, maxipos = 0;
    vi dp(n), prev(n, -1);
    dp[0] = jobs[0].profit;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (jobs[i].start >= jobs[j].finish) {
                if (dp[i] < dp[j] + jobs[i].profit) {
                    dp[i] = dp[j] + jobs[i].profit;
                    prev[i] = j;
                }
            }
        }
        if (maxi < dp[i]) {
            maxi = dp[i];
            maxipos = i;
        }
    }
    deque<int> res;
    for (int at = maxipos; at != -1; at = prev[at]) {
        res.push_front(jobs[at].profit);
    }
    return res;
}

int main() { TimeMeasure _; __x();
    vector<Job> jobs = {
        {1, 2, 50},
        {3, 5, 20},
        {6, 19, 100},
        {2, 100, 200},
    };
    cout << tab(jobs) << endl;
}
