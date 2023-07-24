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

int32_t main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    vector<bool> vis(n+1, false);
    stack<int> st;
    
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            dfs(i, adj, vis, st);
        }
    }

    if(st.size() != n) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    vector<int> dist(n+1, -1e9);
    vector<int> parent(n+1, -1);
    dist[1] = 0;

    while(!st.empty()) {
        int node = st.top();
        st.pop();

        for(auto i : adj[node]) {
            if(dist[node]!=-1e9 && dist[node] + 1 > dist[i]) {
                dist[i] = dist[node] + 1;
                parent[i] = node;
            }
        }
    }

    if(dist[n] == -1e9) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    vector<int> ans;
    int start = n;

    while(start != 1) {
        ans.push_back(start);
        start = parent[start];
    }

    ans.push_back(1);
    reverse(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for(auto node : ans) {
        cout << node << " ";
    }
}