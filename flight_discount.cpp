#include<bits/stdc++.h>
using namespace std;
#define int long long int
typedef pair<int,int> pii;

const int INF = 1e17;


int dijkstra(int n, vector<vector<pii>> &adj) {
    vector<int> dist(n+1, INF);   //without coupon
    vector<int> disc(n+1, INF);   //with coupon

    dist[1] = 0;
    disc[1] = 0;

    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;  //cost, node, coupon used or not
    pq.push({0, {1, 0}});

    while(!pq.empty()) {
        int cost = pq.top().first;
        int node = pq.top().second.first;
        int flag = pq.top().second.second;

        pq.pop();

        if(flag==0) {
            if(cost > dist[node]) {
                continue;
            }
        }
        if(flag==1) {
            if(cost > disc[node]) {
                continue;
            }
        }

        for(auto i : adj[node]) {
            int v = i.first;
            int c = i.second;
            if(flag == 1) {
                if(cost + c < disc[v]) {
                    disc[v] = cost + c;
                    pq.push({disc[v], {v, 1}});
                }
            }

            if(flag == 0) {
                if(cost + c < dist[v]) {
                    dist[v] = cost + c;
                    pq.push({dist[v], {v, 0}});
                }

                if(cost + c/2 < disc[v]) {
                    disc[v] = cost + c/2;
                    pq.push({disc[v], {v, 1}});
                }
            }
        }
    }

    return disc[n];
}

int32_t main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pii>> adj(n+1);
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c});
    }

    int ans = dijkstra(n, adj);
    cout << ans;
}