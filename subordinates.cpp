#include<bits/stdc++.h>
using namespace std;
#define int long long int

void dfs(int node, vector<vector<int>> &adj, vector<int> &ans) {
    if(adj[node].size() == 0) {
        ans[node] = 0;
        return;
    }

    for(auto i : adj[node]) {
        dfs(i, adj, ans);
        ans[node] += 1 + ans[i];
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;

    vector<vector<int>> adj(n+1);
    for(int i=2; i<=n; i++) {
        int val;
        cin >> val;

        adj[val].push_back(i);
    }

    vector<int> ans(n+1, 0);

    dfs(1, adj, ans);

    for(int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
}