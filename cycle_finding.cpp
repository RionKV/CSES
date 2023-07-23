#include<bits/stdc++.h>
using namespace std;
#define int long long int
typedef pair<int, int> pii;

class triple {
public:
    int first;
    int second;
    int third;
};

vector<int> bellmanFord(int n, vector<triple> &edges) {
    vector<int> dist(n+1, 1e17);
    vector<int> parent(n+1, -1);
    dist[1] = 0;
    int flag = -1;

    // usual n-1 iterations, 1 extra for detecting negative cycle
    for(int i=0; i<n; i++) {
        flag = -1;
        for(auto e : edges) {
            int u = e.first;
            int v = e.second;
            int c = e.third;

            //disconnected components can also be there so no conditions

            if(dist[u] + c < dist[v]) {
                dist[v] = dist[u] + c;
                parent[v] = u;
                flag = v;
            }
        }
    }

    // flag does'nt change on nth iteration means negative cycle is not present
    if(flag == -1) {
        return {};
    }

    int node = flag;
    for(int i=0; i<n; i++) { //this will ensure that we land on a node which is part of negative cycle
        node = parent[node];
    }

    vector<int> cycle;
    cycle.push_back(node);

    int start = node;
    start = parent[node];

    while(start != node) {
        cycle.push_back(start);
        start = parent[start];
    }

    cycle.push_back(start);
    reverse(begin(cycle), end(cycle));
    return cycle;
}

int32_t main() {
    int n, m;
    cin >> n >> m;

    vector<triple> edges(m);
    for(int i=0; i<m; i++) {
        triple data;
        cin >> data.first >> data.second >> data.third;

        edges[i] = data;
    }

    vector<int> ans = bellmanFord(n, edges);
    if(ans.size()==0) {
        cout << "NO" << endl;
        return 0;
    }
    else {
        cout << "YES" << endl;
        for(int i=0; i<ans.size(); i++) {
            cout << ans[i] << " ";
        }
        return 0;
    }
}