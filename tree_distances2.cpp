#include<bits/stdc++.h>
using namespace std;
#define int long long int

vector<int> tree[200001];
int subtreeAns[200001];
int subtreeCnt[200001];
int ans[200001];

void preprocessing(int node, int parent) {
    int nodeCnt = 1;
    int nodeAns = 0;

    for(auto i : tree[node]) {
        if(i != parent) {
            preprocessing(i, node);
            nodeCnt += subtreeCnt[i];
            nodeAns += subtreeAns[i] + subtreeCnt[i];
        }
    }

    subtreeAns[node] = nodeAns;
    subtreeCnt[node] = nodeCnt;
}

void solve(int node, int parent, int par_ans, int &totalNodes) {
    ans[node] = subtreeAns[node] + (par_ans + (totalNodes - subtreeCnt[node]));

    for(auto i : tree[node]) {
        if(i != parent) {
            solve(i, node, ans[node] - (subtreeAns[i] + subtreeCnt[i]), totalNodes);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for(int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    preprocessing(1, 0);
    solve(1, 0, 0, n);

    for(int i=1; i<n+1; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}