#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int mod = 1e9 + 7;

void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st) {

    vis[node] = true;
    for(auto i : adj[node]) {
        if(!vis[i]) dfs(i, adj, vis, st);
    }

    st.push(node);
}

void topo(int n, vector<int> &vis, stack<int> &st, vector<vector<int>> &adj) {
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            dfs(i, adj, vis, st);
        }
    }
}

int32_t main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    vector<int> vis(n+1, false);
    stack<int> st;
    topo(n, vis, st, adj);

    vector<int> dp(n+1, 0);
    dp[1] = 1;
    
    while(!st.empty()) {
        int node = st.top();
        st.pop();

        for(auto i : adj[node]) {
            dp[i] = (dp[i] + dp[node])%mod;
        }
    }

    cout << dp[n]%mod;
}