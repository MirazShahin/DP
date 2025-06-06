#include <bits/stdc++.h>
using namespace std; 
using ll = long long;
int const N = 2e5 + 5; 
int grid[N][3];
ll ans(int ind, int previ, int n, vector<vector<int>> &dp) {
	if(ind == n - 1) {
	   ll maxi = 0;
       for(int i = 0; i < 3; i++ ) {
       	 if(i != previ) {
       	 	maxi = max(maxi, 1LL * grid[n - 1][i]);
       	 }
       }
       return maxi;
	}
	if(dp[ind][previ] != -1) {
		return dp[ind][previ];
	}
	ll maxi = 0;
	for(int i = 0; i < 3; i++ ) {
        if(i != previ) {
         	ll xx = 1LL * (grid[ind][i] + ans(ind + 1, i, n, dp));
 
         	maxi = max(maxi, xx);
        }
	}
	return dp[ind][previ] = maxi;
}
void solve() {
    int n; cin >> n;
    for(int i = 0; i < n; i++ ) {
    	for(int j = 0; j < 3; j++ ) {
    		cin >> grid[i][j];
    	}
    }
    vector<vector<int>> dp(n, vector<int>(4, -1));
    cout << ans(0, 3, n, dp) << '\n';
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
