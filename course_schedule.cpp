#include<bits/stdc++.h>
using namespace std;
#define int long long int

bool flag = true;
void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &inQueue, queue<int> &q) {
    vis[node] = true;
    if(inQueue[node]) return;

    for(auto i : adj[node]) {
        if(!vis[i]) {
            dfs(i, adj, vis, inQueue, q);
        }
        else {
            //means cycle is present
            if(!inQueue[i]) {
                flag = false;
                return;
            }        
        }
    }

    if(!inQueue[node]) {
        q.push(node);
        inQueue[node] = true;
    }
}

int32_t main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;

        adj[b].push_back(a);
    }

    vector<bool> vis(n+1, false); 
    vector<bool> inQueue(n+1, false);
    queue<int> q;

    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            dfs(i, adj, vis, inQueue, q);
        }
    }

    if(!flag) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
}