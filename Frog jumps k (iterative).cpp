#include <bits/stdc++.h>
using namespace std; 
using ll = long long;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for(int i = 1; i < n; i++ ) {
        for(int j = 1; j <= k; j++ ) {
            if(i - j >= 0) {
                dp[i] = min(dp[i], dp[i - j] + abs(v[i] - v[i - j]));
            }
        }
    }
    cout << dp[n - 1] << '\n';
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
