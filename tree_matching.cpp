#include<bits/stdc++.h>
using namespace std;
#define int long long int

int solve(int node, bool isIncluded, vector<vector<int>> &adj, vector<vector<int>> &dp, int parent) {
    if(dp[node][isIncluded] !=  -1) {
        return dp[node][isIncluded];
    }

    if(!isIncluded) {
        int ans = 0;

        for(auto i : adj[node]) {
            if(i != parent) {
                int op1 = solve(i, 0, adj, dp, node);
                int op2 = solve(i, 1, adj, dp, node);
                ans += max(op1, op2);
            }
        }

        dp[node][isIncluded] = ans;
        return ans;
    }
    else {
        int ans = 0;

        for(auto i : adj[node]) {
            if(i != parent) {
                ans += solve(i, 1, adj, dp, node);
            }
        }

        int res = 0;
        for(auto i : adj[node]) {
            if(i != parent) {
                res = max(res, 1 + ans - dp[i][1] + solve(i, 0, adj, dp, node));
            }
        }

        dp[node][isIncluded] = res;
        return res;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> adj(n+1);
    for(int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> dp(n+1, vector<int>(2, -1));

    int ans1 = solve(1, 0, adj, dp, -1);
    int ans2 = solve(1, 1, adj, dp, -1);

    cout << max(ans1, ans2);
    return 0;
}