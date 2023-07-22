#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &vis, vector<vector<int>> &adj) {
    vis[node] = true;

    for(auto i : adj[node]){
        if(!vis[i]) {
            dfs(i, vis, adj);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n+1, false);
    vector<int> connections;

    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            connections.push_back(i);
            dfs(i, vis, adj);
        }
    }

    cout << connections.size()-1 << endl;
    for(int i=0; i<connections.size()-1; i++) {
        cout << connections[i] << " " << connections[i+1] << endl;
    }

}