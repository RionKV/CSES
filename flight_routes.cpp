#include<bits/stdc++.h>
using namespace std;
#define int long long int
typedef pair<int,int> pii;

const int INF = 1e17;

vector<int> dijkstra(int n, vector<vector<pii>> &adj, int k) {
    vector<vector<int>> dist(n+1, vector<int>(k, INF));  //best k paths for each node
    dist[1][0] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});

    while(!pq.empty()) {
        int node = pq.top().second;
        int cost = pq.top().first;

        pq.pop();

        if(cost > dist[node][k-1]) {   //k-1 has the worst cost for the node
            continue;
        }

        for(auto i : adj[node]) {
            int c = i.second;
            int v = i.first;

            if(c + cost < dist[v][k-1]) {
                dist[v][k-1] = c + cost;
                pq.push({dist[v][k-1], v});
                sort(dist[v].begin(), dist[v].end());
            }
        }
    }

    return dist[n];
}

int32_t main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pii>> adj(n+1);
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c});
    }

    vector<int> ans = dijkstra(n, adj, k);
    for(int i=0; i<k; i++) {
        cout << ans[i] << " ";
    }

}