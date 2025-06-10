#include <bits/stdc++.h>
using namespace std; 
using ll = long long;
int const MOD = 1e9 + 7;
int const N = 1005;
char grid[N][N];
int dp[N][N], n;

int ways(int i, int j) {
    if(i >= n or j >= n or grid[i][j] == '*') {
        return 0;
    }
    if(i == n - 1 and j == n - 1) {
        return 1;
    }
    if(dp[i][j] != -1) return dp[i][j];

    return dp[i][j] = (ways(i + 1, j) + ways(i, j - 1)) % MOD;
} 
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++ ) {
        for(int j = 0; j < n; j++ ) {
            cin >> grid[i][j];
        }
    }
    for(int i = 0; i < n; i++ ) {
        for(int j = 0; j < n; j++ ) {
            dp[i][j] = -1;
        }
    }
    cout << ways(0, 0) << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); 
    int test_case = 1;
    //cin >> test_case;
    int i = 1;
    while(test_case-- ) {
    	//cout << "Case " << i << ": ";
        solve();
        i++;
    }

    return 0;
}
