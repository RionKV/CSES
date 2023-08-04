#include<bits/stdc++.h>
using namespace std;
#define int long long int

void buildTree1(int si, int ss, int se, vector<int> &arr, vector<int> &tree) {
    if(ss == se) {
        tree[si] = arr[ss] + ss;
        return;
    }

    int mid = (ss + se)/2;
    buildTree1(2*si, ss, mid, arr, tree);
    buildTree1(2*si + 1, mid+1, se, arr, tree);

    tree[si] = min(tree[2*si], tree[2*si + 1]);
}

void buildTree2(int si, int ss, int se, vector<int> &arr, vector<int> &tree) {
    if(ss == se) {
        tree[si] = arr[ss] - ss;
        return;
    }

    int mid = (ss + se)/2;
    buildTree2(2*si, ss, mid, arr, tree);
    buildTree2(2*si + 1, mid+1, se, arr, tree);

    tree[si] = min(tree[2*si], tree[2*si + 1]);
}

int solve(int si, int ss, int se, int qs, int qe, vector<int> &tree) {
    if(ss > qe || se < qs) {
        return INT_MAX;
    }

    if(ss >= qs && se <= qe) {
        return tree[si];
    }

    int mid = (ss + se)/2;
    int l = solve(2*si, ss, mid, qs, qe, tree);
    int r = solve(2*si + 1, mid+1, se, qs, qe, tree);

    return min(l, r);
}

void update1(int si, int ss, int se, int q, vector<int> &tree, int up) {
    if(ss > q || se < q) {
        return;
    }

    if(ss == se && ss == q) {
        tree[si] = up + ss;
        return;
    }

    int mid = (ss + se)/2;
    update1(2*si, ss, mid, q, tree, up);
    update1(2*si + 1, mid+1, se, q, tree, up);

    tree[si] = min(tree[2*si], tree[2*si + 1]);
}

void update2(int si, int ss, int se, int q, vector<int> &tree, int up) {
    if(ss > q || se < q) {
        return;
    }

    if(ss == se && ss == q) {
        tree[si] = up - ss;
        return;
    }

    int mid = (ss + se)/2;
    update2(2*si, ss, mid, q, tree, up);
    update2(2*si + 1, mid+1, se, q, tree, up);

    tree[si] = min(tree[2*si], tree[2*si + 1]);
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int n, q;
    cin >> n >> q;
 
    vector<int> arr(n+1);
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }
   
    vector<int> tree1(4*n, INT_MAX);   // minval + its index (for right side)
    vector<int> tree2(4*n, INT_MAX);   // minval - its index (for left side)

    buildTree1(1, 1, n, arr, tree1);
    buildTree2(1, 1, n, arr, tree2);

    while(q--) {
        int f;
        cin >> f;

        if(f == 2) {
            int k;
            cin >> k;

            int r = solve(1, 1, n, k, n, tree1);
            int l = solve(1, 1, n, 1, k, tree2);

            cout << min(l + k, r - k) << endl;
        }
        else {
            int k, x;
            cin >> k >> x;

            int up = x;
            int del = arr[k];
            arr[k] = up;

            update1(1, 1, n, k, tree1, up);
            update2(1, 1, n, k, tree2, up);
        }
    }
}