#include<bits/stdc++.h>
using namespace std;
#define int long long int

bool dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &inStack, stack<int> &st) {
    vis[node] = true;
    st.push(node);
    inStack[node] = true;

    for(auto i: adj[node]) {
        if(!vis[i]) {
            if(dfs(i, adj, vis, inStack, st)) {
                return true;
            }
        }
        else {
            if(inStack[i]) {
                st.push(i);
                return true;
            }
        }
    }

    st.pop();
    inStack[node] = false;
    return false;
}

int32_t main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    vector<bool> vis(n+1, false);
    vector<bool> inStack(n+1, false);
    stack<int> st;
    bool flag = false;

    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            if(dfs(i, adj, vis, inStack, st)) {
                flag = true;
                break;
            }
        }
    }

    if(!flag) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<int> ans;
    ans.push_back(st.top());
    int start = st.top();
    st.pop();

    while(st.top() != start) {
        ans.push_back(st.top());
        st.pop();
    }

    ans.push_back(ans[0]);
    reverse(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }

}