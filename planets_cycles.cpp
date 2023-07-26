#include<bits/stdc++.h>
using namespace std;
#define int long long int

void dfs(int node, vector<int> &edges, vector<bool> &vis, int &len, vector<int> &pathLen, queue<int> &q) {
    q.push(node);

    if(vis[node]) {
        len += pathLen[node];
        return;
    }
    else {
        len++;
        vis[node] = true;

        int nextNode = edges[node];
        dfs(nextNode, edges, vis, len, pathLen, q);
    }
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int n;
    cin >> n;
 
    vector<int> edges(n+1);
    for(int i=1; i<=n; i++) {
        int v;
        cin >> v;
 
        edges[i] = v;
    }
    
    vector<bool> vis(n+1, false);
    queue<int> q;
    int len = 0;
    vector<int> pathLen(n+1, 0);
    for(int i=1; i<=n; i++) {
        
        if(!vis[i]) {
            len = 0;
            dfs(i, edges, vis, len, pathLen, q);
            int val = 1;

            while(!q.empty()) {

                if(q.front() == q.back()) { //means we are in a cycle, so all nodes will have same len to be visited again
                    val = 0;
                }

                int node = q.front();
                q.pop();

                pathLen[node] = len;
                len -= val;
            }
        }
    }

    for(int i=1; i<=n; i++) {
        cout << pathLen[i] << " ";
    }
}