#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    vector<set<int>> adj(n+1);
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].insert(v);
        adj[v].insert(u);
    }

    //euler circuits

    for(int i=1; i<=n; i++) {
        if(adj[i].size()%2 != 0) {   //every node should have even degree
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    vector<int> ans;
    stack<int> st;
    st.push(1);

    while(!st.empty()) {
        int u = st.top();

        if(adj[u].size() == 0) {
            ans.push_back(u);
            st.pop();
        }
        else {
            int v = *adj[u].begin();
            st.push(v);

            adj[u].erase(v);
            adj[v].erase(u);
        }
    }


    if(ans.size() != m+1) {   // m edges are there so m+1 vertices must be there as each edges is to be visited once
        cout << "IMPOSSIBLE";
        return 0;
    }

    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
    
    return 0;

}