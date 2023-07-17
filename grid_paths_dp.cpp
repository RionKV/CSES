#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int mod = 1e9 + 7;

ll dp[1001][1001];

int dfs(int n, vector<vector<char>> &grid, int &ans, int i, int j) {
    if(i>=n || j>=n) {
        return 0;
    }
    if(grid[i][j] == '*') {
        return 0;
    }
    if(i==n-1 && j==n-1) {
        return 1;
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    int down = dfs(n, grid, ans, i+1, j)%mod;
    int right = dfs(n, grid, ans, i, j+1)%mod;
    dp[i][j] = down + right;
    return dp[i][j]%mod;

}

int main() {
    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    int ans = dfs(n, grid, ans, 0, 0);
    cout << ans%mod;
}