#include <bits/stdc++.h>
using namespace std; 
using ll = long long; 
int DP(int n, vector<int> &dp) {
    if(n == 0) return 0;
    if(n % 10 == n) return 1;
    if(dp[n] != -1) return dp[n];
    int steps = INT_MAX;
    int tmp = n;
    while(tmp > 0) {
        int digit = tmp % 10;
        tmp /= 10;
        if(digit > 0) {
            steps = min(steps, DP(n - digit, dp) + 1);
        }
    }
    return dp[n] = steps;
}
void solve() {
    int n; cin >> n;
    vector<int> dp(n + 1, -1);
    cout << DP(n, dp) << '\n';
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
