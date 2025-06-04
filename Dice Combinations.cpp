#include <bits/stdc++.h>
using namespace std; 
using ll = long long; 
int const MOD = 1e9 + 7;
ll ans(int n, vector<ll> &dp) {
    if(n == 0) return 1;
    if(n < 0) return 0;
    if(dp[n] != -1) return dp[n];
    return dp[n] = (ans(n - 1, dp) + ans(n - 2, dp) + ans(n - 3, dp) + ans(n - 4, dp) + ans(n - 5, dp) + ans(n - 6, dp)) % MOD;
}
void solve() {
    int n; cin >> n;
    vector<ll> dp(n + 1, -1);
    cout << ans(n, dp) % MOD << '\n';
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
