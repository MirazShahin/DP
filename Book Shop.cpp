#include <bits/stdc++.h>
using namespace std; 
using ll = long long; 
 
void solve() {
    ll n, x;
    cin >> n >> x;
    int arr1[n], arr2[n];
    for(int i = 0; i < n; i++ ) {
        cin >> arr1[i];
    } 
    for(int i = 0; i < n; i++ ) {
        cin >> arr2[i];
    }
    ll dp[x + 1] = {0}; 
    for(int i = 0; i < n; i++ ) {
        for(int j = x; j >= arr1[i]; j--){ 
            dp[j] = max(dp[j], dp[j - arr1[i]] + arr2[i]);
        }
    }
   cout << dp[x] << '\n';
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
