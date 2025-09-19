#include <bits/stdc++.h>
#define FastIO                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
 
#define gcd(a,b)   __gcd(a,b)
#define lcm(a,b)   (a*b) / gcd(a,b)
#define all(x)     (x).begin(), (x).end()
 
 
using namespace std;
using ll = long long int;
 
vector<vector<bool>> dp;
void go(int idx, int sum, set<int> &st, vector<int> &v) {
   if(idx >= v.size()) {
      if(sum > 0) {
         st.insert(sum);
      }
      return;
   }
   if(dp[idx][sum] == 1) return;
   dp[idx][sum] = 1;
   go(idx + 1, sum + v[idx], st, v);
   go(idx + 1, sum, st, v);
} 
void solve() {
   int n; cin >> n;
   vector<int> v(n);
   ll sum = 0;
   for(int i = 0; i < n; i++ ) {
      cin >> v[i];
      sum += v[i];
   }
   set<int> st;
   dp.assign(n + 1, vector<bool>(sum + 1, false));
   go(0, 0, st, v);
   cout << st.size() << '\n';
   for(auto &it : st) {
      cout << it << ' ';
   }
   cout << '\n';
}
int32_t main()
{
   FastIO;
 
   int test_case = 1;
   // cin >> test_case;
   int Case = 1;
   while(test_case--) {
//    cout << "Case " << Case << ": ";
      solve();
      Case++;
   }
 
   return 0;
}
