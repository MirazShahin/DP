#include <bits/stdc++.h>
using namespace std; 
using ll = long long;

int ans(int ind, vector<int> &dp, vector<int> &v) {
    if(ind == 0) return v[ind];
    if(ind < 0) return 0;
    if(dp[ind] != -1) return dp[ind];

    int take = v[ind] + ans(ind - 2, dp, v);
    int notTake = 0 + ans(ind - 1, dp, v);

    return dp[ind] = max(take, notTake);
}
void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++ ) cin >> v[i];
    vector<int> dp(n, -1);
    cout << ans(n - 1, dp, v) << '\n';
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
