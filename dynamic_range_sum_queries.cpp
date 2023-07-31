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

int solve(int si, int ss, int se, int qs, int qe, vector<int> &tree) {
    if(ss > qe || se < qs) {
        return 0;
    }

    if(ss >= qs && se <= qe) {
        return tree[si];
    }

    int mid = (ss + se)/2;
    int l = solve(2*si, ss, mid, qs, qe, tree);
    int r = solve(2*si + 1, mid+1, se, qs, qe, tree);

    return l + r;
}

void update(int si, int ss, int se, vector<int> &tree, int up, int del, int idx) {
    if(idx < ss || idx > se) {
        return;
    }

    if(si >= tree.size()) {
        return;
    }

    if(idx >= ss && idx <= se) {
        tree[si] = tree[si] - del + up;
    }

    int mid = (ss + se)/2;
    update(2*si, ss, mid, tree, up, del, idx);
    update(2*si + 1, mid+1, se, tree, up, del, idx);
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

    buildTree(1, 1, n, arr, tree);

    while(q--) {
        int a, b, c;
        cin >> a >> b >> c;

        if(a==2) {
            cout << solve(1, 1, n, b, c, tree) << endl;
        }
        else {
            int del = arr[b];
            int up = c;
            arr[b] = up;
            int idx = b;
            update(1, 1, n, tree, up, del, idx);
        }
    }
}