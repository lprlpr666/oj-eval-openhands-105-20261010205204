#include <bits/stdc++.h>
using namespace std;

// Expected number of days to eat at least `need` apples when `remain` apples are left.
// DP with memoization for small constraints (n,m <= 20).

int n, m;
vector<vector<double>> dp; // dp[remain][need]
vector<vector<char>> vis;

double solve(int remain, int need) {
    if (need <= 0) return 0.0; // already reached target
    if (remain <= 0) return 0.0; // shouldn't happen as need>0 implies remain>0
    if (vis[remain][need]) return dp[remain][need];
    vis[remain][need] = 1;
    double sum = 0.0;
    for (int eat = 1; eat <= remain; ++eat) {
        int new_need = need - eat;
        if (new_need <= 0) {
            // finished this day, no extra days
            continue;
        }
        sum += solve(remain - eat, new_need);
    }
    double expected = 1.0 + sum / remain; // one day plus expected of continuation
    dp[remain][need] = expected;
    return expected;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!(cin >> n >> m)) return 0;
    dp.assign(n + 1, vector<double>(m + 1, 0.0));
    vis.assign(n + 1, vector<char>(m + 1, 0));
    double ans = solve(n, m);
    cout.setf(ios::fixed); cout << setprecision(2) << ans << "\n";
    return 0;
}
