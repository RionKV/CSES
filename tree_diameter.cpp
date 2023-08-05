#include<bits/stdc++.h>
using namespace std;
#define int long long int

bool isLeaf(int node, vector<vector<int>> &adj) {
    if(node != 1 && adj[node].size() == 1) {
        return true;
    }

    return false;
}

void dfs(int node, int parent, vector<vector<int>> &adj, int &ans, vector<vector<int>> &dp) {
    vector<int> dist;

    if(isLeaf(node, adj)) {
        dp[node][0] = 0;
        dp[node][1] = 0;
        return;
    }

    for(auto i : adj[node]) {
        if(i != parent) {
            dfs(i, node, adj, ans, dp);
            dist.push_back(dp[i][0]);
        }
    }

    sort(dist.rbegin(), dist.rend());

    if(dist.size()==1) {
        dp[node][0] = 1 + dist[0];
        dp[node][1] = 0;
    }
    else {
        dp[node][0] = 1 + dist[0];
        dp[node][1] = (1 + dist[0]) + (1 + dist[1]);
    }

    ans = max(ans, max(dp[node][0], dp[node][1]));
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    if(n == 1) {
        cout << 0;
        return 0;
    }

    vector<vector<int>> adj(n+1);
    for(int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    vector<vector<int>> dp(n+1, vector<int>(2, 0)); 
    //dp[u][0] means longest path where u is starting node
    //dp[u][1] means longest path where u is in between

    dfs(1, -1, adj, ans, dp);

    cout << ans;
    return 0;
}