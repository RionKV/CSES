#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int MAXN = 2e5 + 1;
const int MAXD = 19;

int parents[MAXN][MAXD];
int heights[MAXN];
vector<int> adj[MAXN];

int jump(int a, int d) {
    for(int i=0; i<MAXD; i++) {
        if(d & (1 << i)) {
            if(parents[a][i] == 1) {
                return 1;
            }

            a = parents[a][i];
        }
    }

    return a;
}

void dfs(int node, int parent, int h) {
    heights[node] = h;

    for(auto i : adj[node]) {
        if(i != parent) {
            dfs(i, node, h+1);
        }
    }
}

int lca(int a, int b) {
    if(heights[a] > heights[b]) {
        a = jump(a, heights[a]-heights[b]);
    }
    else if(heights[b] > heights[a]) {
        b = jump(b, heights[b]-heights[a]);
    }

    if(a==b) {
        return a;
    }

    for(int i=MAXD-1; i>=0; i--) {
        if(parents[a][i] != parents[b][i]) {
            a = parents[a][i];
            b = parents[b][i];
        }
    }

    return jump(a, 1);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;

    parents[1][0] = 1;

    for(int i=2; i<=n; i++) {
        cin >> parents[i][0];

        adj[i].push_back(parents[i][0]);
        adj[parents[i][0]].push_back(i);
    }

    for(int d=1; d<MAXD; d++) {
        for(int i=1; i<=n; i++) {
            if(parents[i][d-1] == 1) {
                parents[i][d] = 1;
            }
            else parents[i][d] = parents[parents[i][d-1]][d-1];
        }
    }

    dfs(1, 1, 0);

    while(q--) {
        int a, b;
        cin >> a >> b;

        cout << lca(a, b) << endl;
    }


}