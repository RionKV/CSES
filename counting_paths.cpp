#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int MAXN = 2e5 + 1;
const int MAXD = 19;
int n, m;
vector<int> adj[MAXN];
int parents[MAXN][MAXD];
int heights[MAXN];

int prefix[MAXN];
int ans[MAXN];

void dfs(int node, int parent, int h) {
    heights[node] = h;

    if(parent!=0) {
        parents[node][0] = parent;
    }

    for(auto i : adj[node]) {
        if(i != parent) {
            dfs(i, node, h+1);
        }
    }
}

int jump(int a, int d) {
    for(int i=0; i<MAXD; i++) {
        if(d & (1 << i)) {
            if(parents[a][i] == 1) {
                return 1;
            }
            else a = parents[a][i];
        }
    }

    return a;
}

int lca(int a, int b) {
    if(heights[a] < heights[b]) {
        b = jump(b, heights[b]-heights[a]);
    }
    else if(heights[a] > heights[b]) {
        a = jump(a, heights[a]-heights[b]);
    }

    if(a == b) {
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

void dfs2(int node, int parent) {
    ans[node] += prefix[node];

    for(auto i : adj[node]) {
        if(i != parent) {
            dfs2(i, node);
            ans[node] += ans[i];
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for(int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, 0);

    for(int d=1; d<MAXD; d++) {
        for(int i=1; i<=n; i++) {
            if(parents[i][d-1] == 1) {
                parents[i][d] = 1;
            }
            else parents[i][d] = parents[parents[i][d-1]][d-1];
        }
    }

    while(m--) {
        int a, b;
        cin >> a >> b;

        int c = lca(a, b);
        prefix[a]++;
        prefix[b]++;
        prefix[c]--; //this gets added twice

        if(c != 1) {
            prefix[parents[c][0]]--;
        }
    }

    dfs2(1, 0);

    for(int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
}