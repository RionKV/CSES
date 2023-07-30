#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    vector<int> indegree(n+1, 0);
    vector<int> outdegree(n+1, 0);

    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        indegree[v]++;
        outdegree[u]++;
    }

    //eulers (Just like Mail Delivery)

    //first node and last node will only have odd degree
    if(outdegree[1]-indegree[1] != 1 || indegree[n]-outdegree[n] != 1) {
        cout <<  "IMPOSSIBLE";
        return 0;
    }

    //intermediate nodes must have equal in and out as we dont have to stop there
    for(int i=2; i<n; i++) {
        if(indegree[i] != outdegree[i]) {
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
            int v = adj[u].back();

            adj[u].pop_back();
            st.push(v);
        }
    }

    if(ans.size() != m+1) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    reverse(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}