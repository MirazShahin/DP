#include <bits/stdc++.h>
using namespace std; 
using ll = long long;
ll const MOD = 1e9 + 7;
ll const N = 105;
ll arr1[N], arr2[N];
ll dp[N][100005];
 
ll ans(ll n, ll i, ll remain) {
    if(i == n) return 0;
    if(remain < 0) return 0;
    if(dp[i][remain] != -1) return dp[i][remain];
    ll not_take = 0 + ans(n, i + 1, remain);
    ll take = 0;
    if(arr1[i] <= remain) {
        take = arr2[i] + ans(n, i + 1, remain - arr1[i]);
    }
    return dp[i][remain] = max(not_take, take);
} 
void solve() {
    ll n, x;
    cin >> n >> x;
    for(int i = 0; i < n; i++ ) {
        int a, b; cin >> a >> b;
        arr1[i] = a;
        arr2[i] = b;
    } 
    memset(dp, -1, sizeof(dp));
    cout << ans(n, 0, x) << '\n';
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
