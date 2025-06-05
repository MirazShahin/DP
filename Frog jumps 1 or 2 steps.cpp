#include <bits/stdc++.h>
using namespace std; 
using ll = long long;
int const MOD = 1e9 + 7;
int ans(int i, vector<int> &dp, vector<int> &v) {
    int n = v.size();
    if(i >= n - 1) {
        return 0;
    }
    if(dp[i] != -1) {
        return dp[i];
    }
    return dp[i] = min(ans(i + 1, dp, v) + abs(v[i] - v[i + 1]),ans(i + 2, dp, v) + abs(v[i] - v[i + 2])); 
} 
void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++ ) cin >> v[i];
    vector<int> dp(n, -1);
    cout << ans(0, dp, v) << '\n';
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
