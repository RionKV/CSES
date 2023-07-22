#include <bits/stdc++.h>
using namespace std;

int s, e;

bool detectCycle(int node, vector<vector<int>>& adj, vector<int>& parent, vector<bool>& vis, int p) {
    vis[node] = true;
    parent[node] = p;

    for (auto i : adj[node]) {
        if(vis[i]) {
            if(parent[node] != i) {
                s = i;
                e = node;
                return true;
            }
        } 
        else {
            bool ans = detectCycle(i, adj, parent, vis, node);
            if(ans) return true;
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> parent(n + 1);
    vector<bool> vis(n + 1, false);

    bool ans = false;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (detectCycle(i, adj, parent, vis, -1)) {
                ans = true;
                break;
            }
        }
    }

    if (!ans) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    vector<int> res;
    int node = e;
    res.push_back(e);
    while (node != s) {
        res.push_back(parent[node]);
        node = parent[node];
    }
    res.push_back(e);

    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}
