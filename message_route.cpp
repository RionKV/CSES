#include<bits/stdc++.h>
using namespace std;

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

    queue<int> q;
    q.push(1);
    vector<int> parent(n+1, -1);
    parent[1] = 1;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(auto i : adj[node]) {
            if(parent[i]==-1) {
                parent[i] = node;
                q.push(i);
            }
        }
    }

    if(parent[n]==-1) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    vector<int> ans;

    int i = n;  
    while(parent[i] != i) {
        ans.push_back(i);
        i = parent[i];
    }

    cout << ans.size()+1 << endl;
    cout << 1 << " ";
    for(int i=ans.size()-1; i>=0; i--) {
        cout << ans[i] << " ";
    }
}