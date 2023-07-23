#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll INF = LLONG_MAX;

int main() {
    ll n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, INF));

    for (ll i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    for (ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }

    // Floyd-Warshall algorithm
    for (ll k = 1; k <= n; k++) {
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    while (q--) {
        ll a, b;
        cin >> a >> b;

        if (dist[a][b] == INF)
            cout << -1 << endl;
        else
            cout << dist[a][b] << endl;
    }

    return 0;
}
