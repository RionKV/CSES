#include<bits/stdc++.h>
using namespace std;
#define int long long int

void buildTree(int si, int ss, int se, vector<int> &arr, vector<int> &tree) {
    if(ss == se) {
        tree[si] = arr[ss];
        return;
    }

    int mid = (ss + se)/2;
    buildTree(2*si, ss, mid, arr, tree);
    buildTree(2*si + 1, mid+1, se, arr, tree);

    tree[si] = tree[2*si] + tree[2*si + 1];
}

void update(int si, int ss, int se, int qs, int qe, vector<int> &tree, int val, vector<int> &lazy) {
    if(lazy[si] != 0) {
        tree[si] += (se - ss + 1)*lazy[si];    //(ss - se + 1) = no. of leaf nodes for si-th node

        if(ss != se) {  //not a leaf node
            lazy[2*si] += lazy[si];
            lazy[2*si + 1] += lazy[si];
        }

        lazy[si] = 0;
    }

    if(ss > qe || se < qs) {
        return;
    }

    if(ss >= qs && se <= qe) {
        tree[si] += (se - ss + 1)*val;

        if(ss != se) {
            lazy[2*si] += val;
            lazy[2*si + 1] += val;
        }

        return;
    }

    int mid = (ss + se)/2;
    update(2*si, ss, mid, qs, qe, tree, val, lazy);
    update(2*si + 1, mid+1, se, qs, qe, tree, val, lazy);

    tree[si] = tree[2*si] + tree[2*si + 1];
}

int solve(int si, int ss, int se, int q, vector<int> &tree, vector<int> &lazy) {
    if(si >= tree.size()) {
        return 0;
    }

    if(lazy[si] != 0) {
        tree[si] += (se - ss + 1)*lazy[si];

        if(ss != se) {
            lazy[2*si] += lazy[si];
            lazy[2*si + 1] += lazy[si];
        }

        lazy[si] = 0;
    }

    if(ss > q || se < q) {
        return 0;
    }

    if(ss == se && ss == q) {
        if(lazy[si] != 0) {
            tree[si] += lazy[si];
        }

        lazy[si] = 0;
        return tree[si];
    }

    int mid = (ss + se)/2;
    int l = solve(2*si, ss, mid, q, tree, lazy);
    int r = solve(2*si + 1, mid+1, se, q, tree, lazy);

    return l + r;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, q;
    cin >> n >> q;

    vector<int> arr(n+1);
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }

    vector<int> tree(4*n, 0);
    vector<int> lazy(4*n, 0);

    buildTree(1, 1, n, arr, tree);

    while(q--) {
        int flag;
        cin >> flag;

        if(flag == 2) {
            int k;
            cin >> k;

            cout << solve(1, 1, n, k, tree, lazy) << endl;
        }
        else {
            int a, b, u;
            cin >> a >> b >> u;

            update(1, 1, n, a, b, tree, u, lazy);
        }
    }
}