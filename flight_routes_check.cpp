#include<bits/stdc++.h>
using namespace std;
#define int long long int

void dfs1(int node, vector<vector<int>> &adj1, vector<bool> &vis1) {
    vis1[node] = true;
    for(auto i : adj1[node]) {
        if(!vis1[i]) dfs1(i, adj1, vis1);
    }
}
void dfs2(int node, vector<vector<int>> &adj2, vector<bool> &vis2) {
    vis2[node] = true;
    for(auto i : adj2[node]) {
        if(!vis2[i]) dfs1(i, adj2, vis2);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj1(n+1);
    vector<vector<int>> adj2(n+1);

    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;

        adj1[u].push_back(v);
        adj2[v].push_back(u);
    }

    vector<bool> vis1(n+1, false);
    vector<bool> vis2(n+1, false);

    dfs1(1, adj1, vis1);  //checks whether we can reach from 1 to all other nodes
    dfs2(1, adj2, vis2);  //checks whether we can reach from all other nodes to 1 (adj2 has reversed edges)

    for(int i=1; i<=n; i++) {
        if(!vis1[i]) {
            cout << "NO" << endl;
            cout << 1 << " " << i;
            return 0;
        }
        else if(!vis2[i]) {
            cout << "NO" << endl;
            cout << i << " " << 1;
            return 0;
        }
    }

    cout << "YES";
    //if we can reach from one node to all other nodes AND all other nodes can reach this node, we return yes
}