#include <bits/stdc++.h>
using namespace std; 
using ll = long long;
const int MOD = 1e9 + 7;

int ans(int i, vector<int> &dp, vector<int> &v, int k) {
    int n = v.size();
    if (i == n - 1) return 0;
    if (dp[i] != -1) return dp[i];

    int mini = INT_MAX;
    for (int j = 1; j <= k; j++) {
        if (i + j < n) {
            int jumpCost = abs(v[i] - v[i + j]) + ans(i + j, dp, v, k);
            mini = min(mini, jumpCost);
        }
    }
    return dp[i] = mini;
} 

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    
    vector<int> dp(n, -1);
    cout << ans(0, dp, v, k) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); 
    int test_case = 1;
    //cin >> test_case;
    
    while (test_case--) {
        solve();
    }

    return 0;
}
