#include<bits/stdc++.h>
using namespace std;
#define int long long int

void dfs2(int node, vector<vector<int>> &adj2, vector<bool> &vis, vector<int> &kingdom, int cnt) {
    vis[node] = true;
    kingdom[node] = cnt;

    for(auto i: adj2[node]) {
        if(!vis[i]) dfs2(i, adj2, vis, kingdom, cnt);
    }
}   

void dfs(int node, vector<vector<int>> &adj1, vector<bool> &vis, stack<int> &st) {
    vis[node] = true;
    for(auto i: adj1[node]) {
        if(!vis[i]) {
            dfs(i, adj1, vis, st);
        }
    }

    st.push(node);
}
void topo(vector<vector<int>> &adj1, stack<int> &st, vector<bool> &vis, int n) {
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            dfs(i, adj1, vis, st);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj1(n+1);
    vector<vector<int>> adj2(n+1);

    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;

        adj1[u].push_back(v);
        adj2[v].push_back(u);
    }

    stack<int> st;
    vector<bool> vis(n+1, false);
    topo(adj1, st, vis, n);

    for(int i=1; i<=n; i++) vis[i] = false;

    int cnt = 0;
    vector<int> kingdom(n+1, 0);

    while(!st.empty()) {
        int node = st.top();
        st.pop();

        if(!vis[node]) {
            cnt++;
            dfs2(node, adj2, vis, kingdom, cnt);
        }
    }

    cout << cnt << endl;
    for(int i=1; i<=n; i++) cout << kingdom[i] << " ";
}