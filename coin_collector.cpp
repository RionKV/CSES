#include<bits/stdc++.h>
using namespace std;
#define int long long int

void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, stack<int> &st) {
    vis[node] = true;
    for(auto i: adj[node]) {
        if(!vis[i]) {
            dfs(i, adj, vis, st);
        }
    }

    st.push(node);
}
void topo(vector<vector<int>> &adj, vector<bool> &vis, stack<int> &st, int n) {
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            dfs(i, adj, vis, st);
        }
    }
}

void dfs2(int node, vector<vector<int>> &inv, vector<bool> &vis, vector<int> &scc, int cnt) {
    vis[node] = true;
    scc[node] = cnt;

    for(auto i : inv[node]) {
        if(!vis[i]) {
            dfs2(i, inv, vis, scc, cnt);
        }
    }
}

int dfsg(int node, vector<vector<int>> &graph, vector<bool> &vis, vector<int> &dp) {
    int ans = 0;

    vis[node] = true;
    for(auto i : graph[node]) {
        if(vis[i]) {
            ans = max(ans, dp[i]);
        }
        else {
            ans = max(ans, dfsg(i, graph, vis, dp));
        }
    }

    return dp[node] += ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> coins(n+1);
    for(int i=1; i<=n; i++) {
        cin >> coins[i];
    }

    vector<vector<int>> adj(n+1);
    vector<vector<int>> inv(n+1);
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        inv[v].push_back(u);
    }

    //kosaraju

    vector<bool> vis(n+1, false);
    stack<int> st;

    topo(adj, vis, st, n);

    for(int i=1; i<=n; i++) vis[i] = false;
    vector<int> scc(n+1);
    int cnt = 0;

    while(!st.empty()) {
        int node = st.top();
        st.pop();

        if(!vis[node]) {
            cnt++;
            dfs2(node, inv, vis, scc, cnt);
        }
    }

    //making a graph of SCCs, considering each scc as a node
    vector<vector<int>> graph(cnt+1);
    vector<vector<bool>> visg(cnt+1, vector<bool>(cnt+1, false));
    vector<int> dp(n+1, 0);

    for(int i=1; i<=n; i++) {
        dp[scc[i]] += coins[i];

        for(auto j : adj[i]) {
            if(scc[i] != scc[j] && !visg[scc[i]][scc[j]]) {
                visg[scc[i]][scc[j]] = true;
                graph[scc[i]].push_back(scc[j]);
            }
        }
    }

    vis.resize(cnt+1);
    for(int i=1; i<=cnt; i++) vis[i] = false;

    int ans = 0;
    for(int i=1; i<=cnt; i++) {
        if(!vis[i]) {
            ans = max(ans, dfsg(i, graph, vis, dp));
        }
    }

    cout << ans << endl;
    return 0;
}