#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pii;

vector<ll> solve(ll m, ll n, vector<vector<pii>> &adj) {
    vector<ll> dist(n+1, LONG_MAX);
    vector<bool> vis(n+1, false);

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    dist[1] = 0;

    while(!pq.empty()) {
        ll node = pq.top().second;
        pq.pop();

        if(vis[node]) continue;

        vis[node] = true;

        for(auto i : adj[node]) {
            if(!vis[i.first]) {
                if(dist[node] + i.second < dist[i.first]) {
                    dist[i.first] = dist[node] + i.second;
                    pq.push({dist[i.first], i.first});
                }
            }
        }
    }

    return dist;
}

int main() {
    ll n, m;
    cin >> n >> m;

    vector<vector<pii>> adj(n+1);
    for(ll i=0; i<m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c});
    }

    vector<ll> ans = solve(m, n, adj);

    for(ll i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}