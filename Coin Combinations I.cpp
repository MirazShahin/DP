#include <bits/stdc++.h>
using namespace std; 
using ll = long long;
int const MOD = 1e9 + 7;
int ans(int x, vector<int> &dp, vector<int> &v) {
    if(x == 0) return 1;
    if(x < 0) return 0;
    if(dp[x] != -1) return dp[x];
    int ways = 0;
    for(int i = 0; i < (int) v.size(); i++ ) {
        int possible = ans(x - v[i], dp, v);
        if(possible > 0) {
           ways = (ways + possible) % MOD;
        }
    }
    return dp[x] = ways;
} 
void solve() {
    int n, x; cin >> n >> x;
    vector<int> v(n);
    for(int i = 0; i < n; i++ ) cin >> v[i];
    vector<int> dp(x + 1, -1);
    cout << ans(x, dp, v) % MOD << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); 
    int test_case = 1;
    //cin >> test_case;
    
    while(test_case-- ) {
        solve();
    }

    return 0;
}
