#include<bits/stdc++.h>
using namespace std;

bool flag = true;

void dfs(int node, vector<vector<int>> &adj, vector<int> &ans, int val) {

    ans[node] = val;

    for(auto i : adj[node]) {
        if(ans[i] == ans[node]) {
            flag = false;
            return;
        }
        else if(ans[i]==0) {
            if(ans[node]==1) {
                dfs(i, adj, ans, 2);
            }
            else {
                dfs(i, adj, ans, 1);
            }
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

    vector<int> ans(n+1, 0);

    for(int i=1; i<=n; i++) {
        if(!flag) break;
        if(!ans[i]) dfs(i, adj, ans, 1);
    }

    if(!flag) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    for(int i=1; i<=n; i++) cout << ans[i] << " ";
}