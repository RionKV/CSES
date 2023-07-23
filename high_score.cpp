#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int INF = 1e17;
const int NINF = (-1)*INF;


class triplet {
public:
    int first;
    int second;
    int third;
};


int32_t main() {
    int n, m;
    cin >> n >> m;

    vector<int> dist(n+1);
    for(int i=2; i<=n; i++) {
        dist[i] = INF;
    }

    vector<triplet> edges(m);
    for(int i=0; i<m; i++) {
        triplet data;
        cin >> data.first >> data.second >> data.third;

        data.third *= -1; //converting into shortest distance path

        edges[i] = data;
    }


    //then bellamn ford

    //first n-1 cycles to find the answer
    for(int i=1; i<n; i++) {
        for(auto e: edges) {
            int u = e.first;
            int v = e.second;
            int d = e.third;

            if(dist[u]==INF) continue;

            if(dist[u]+d < dist[v]) {
                dist[v] = dist[u] + d;
            }

            dist[v] = max(dist[v], NINF); //if it becomes less than ninf, we'll set it back to ninf
        }
    }

    //then n cycles to check for negative cycles, if present then
    //answer calculated till now is not valid and its will keep decreasing

    for(int i=1; i<=n; i++) {
        for(auto e: edges) {
            int u = e.first;
            int v = e.second;
            int d = e.third;

            if(dist[u]==INF) continue;
            dist[v] = max(dist[v], NINF);

            if(dist[u]+d < dist[v]) {
                dist[v] = NINF;  //change here means negative cyce is present
            }
        }
    }

    int ans = dist[n];
    if(ans == NINF) {
        cout << -1;
    }
    else {
        cout << -1*ans;   //as we multiplied it with -1 while taking input
    }
    
}