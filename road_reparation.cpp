#include<bits/stdc++.h>
using namespace std;
#define int long long int
typedef pair<int, int> pii;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<pii>> adj(n+1);
    for(int i=0; i<m; i++) {
        int u, v, d;
        cin >> u >> v >> d;

        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }

    //prims algo
    int sum = 0;
    vector<int> vis(n+1, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});  //dist, node

    while(!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        if(vis[node]) continue;

        vis[node] = true;
        sum += dist;

        for(auto i : adj[node]) {
            pq.push({i.second, i.first});
        }
    }

    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    cout << sum;
}