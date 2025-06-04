#include <bits/stdc++.h>
using namespace std; 
using ll = long long; 
int DP(int x, vector<int> &dp, vector<int> &v) {
    if(x == 0) return 0;
    if(x < 0) return INT_MAX;
    if(dp[x] != -1) return dp[x];
    int steps = INT_MAX;
    for(int i = 0; i < (int) v.size(); i++ ) {
        int tmp = DP(x - v[i], dp, v);
        if(tmp != INT_MAX) {
            steps = min(steps, tmp + 1);
        }
    }
    return dp[x] = steps;
}
void solve() {
    int n, x; cin >> n >> x;
    vector<int> v(n);
    for(int i = 0; i < n; i++ ) cin >> v[i];

    vector<int> dp(x + 1, -1);
    if(DP(x, dp, v) == INT_MAX) cout << -1 << '\n';
    else cout << DP(x, dp, v) << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); 
    int test_case = 1;
    // cin >> test_case;
    
    while(test_case-- ) {
        solve();
    }

    return 0;
}
