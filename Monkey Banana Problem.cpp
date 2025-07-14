#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()

int MAXN = 105;
int dp[2 * 105][105], grid[2 * 105][105];
int n;

int DP(int x, int y) {
    if(x >= 2 * n or y <= 0 or y >= MAXN) {
        return 0;
    }
    if(dp[x][y] != -1) return dp[x][y];
    if(x < n) {
        dp[x][y] = grid[x][y] + max(DP(x + 1, y), DP(x + 1, y + 1));
    }
    else {
        dp[x][y] = grid[x][y] + max(DP(x + 1, y), DP(x + 1, y - 1));
    }
    return dp[x][y];
}

void solve() {
    cin >> n; 
    memset(dp, -1, sizeof(dp));
    memset(grid, 0, sizeof(grid));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> grid[i][j];
        }
    } 
    for (int i = n + 1, len = n - 1; i <= (2 * n) - 1; i++, len--) {
        for (int j = 1; j <= len; j++) {
            cin >> grid[i][j];
        }
    } 
    int ans = DP(1, 1);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test_case = 1;
    cin >> test_case;
    int Case = 1;
    while (test_case--) {
        cout << "Case " << Case << ": ";
        solve();
        Case++;
    }

    return 0;
}
