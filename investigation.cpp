#include<bits/stdc++.h>
using namespace std;
#define int long long int
typedef pair<int, int> pii;

const int mod = 1e9 + 7;

int dijkstra(int n, vector<vector<pii>> &adj, vector<int> &ways, vector<int> &minFlights, vector<int> &maxFlights) {
    vector<int> dist(n+1, 1e17);
    dist[1] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});

    while(!pq.empty()) {
        int node = pq.top().second;
        int d = pq.top().first;

        pq.pop();

        if(dist[node] < d) continue;

        for(auto i : adj[node]) {
            int c = i.second;
            int v = i.first;

            if(d+c > dist[v]) continue;

            if(d+c == dist[v]) {
                ways[v] = (ways[node] + ways[v])%mod;
                minFlights[v] = min(1+minFlights[node], minFlights[v]);
                maxFlights[v] = max(1+maxFlights[node], maxFlights[v]);
            }

            if(d+c < dist[v]) {
                dist[v] = c + d;
                ways[v] = ways[node];
                minFlights[v] = minFlights[node] + 1;
                maxFlights[v] = maxFlights[node] + 1;
                pq.push({dist[v], v});
            }
        }
    }

    return dist[n];
}

int32_t main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pii>> adj(n+1);
    for(int i=0; i<m; i++) {
        int u, v, d;
        cin >> u >> v >> d;

        adj[u].push_back({v, d});
    }

    vector<int> ways(n+1, 0);   //ways of travelling with min costs, not all the ways
    ways[1] = 1;

    vector<int> minFlights(n+1, INT_MAX);
    minFlights[1] = 0;

    vector<int> maxFlights(n+1, 0);

    int min_dist = dijkstra(n, adj, ways, minFlights, maxFlights);

    cout << min_dist << " ";
    cout << ways[n] << " ";
    cout << minFlights[n] << " ";
    cout << maxFlights[n] << " ";
}