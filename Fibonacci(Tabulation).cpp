#include <bits/stdc++.h>
using namespace std; 
using ll = long long;  
void solve() {
    int n; cin >> n; 

    // TC = O(n), SC = O(1)
    int prev1 = 1, prev2 = 0;
    int fibo = 0;
    for(int i = 2; i <= n; i++ ) {
        fibo = prev1 + prev2;
        prev2 = prev1;
        prev1 = fibo;
    }
    cout << fibo << '\n';
    
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); 
    int test_case = 1;
    cin >> test_case;
    
    while(test_case-- ) {
        solve();
    }

    return 0;
}
