#include<bits/stdc++.h>
using namespace std;
#define int long long int

void buildTree(int si, int ss, int se, vector<int> &arr, vector<int> &tree) {
    if(ss == se) {
        tree[si] = arr[ss];   //if only one number then no xor, just keep the number intact
        return;
    }

    int mid = (ss + se)/2;
    buildTree(2*si, ss, mid, arr, tree);
    buildTree(2*si + 1, mid+1, se, arr, tree);

    tree[si] = tree[2*si] ^ tree[2*si + 1];
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

    return l^r;
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

    vector<int> tree(4*n, 0); //xor with 0 gives the no. back

    buildTree(1, 1, n, arr, tree);

    while(q--) {
        int a, b;
        cin >> a >> b;

        cout << solve(1, 1, n, a, b, tree) << endl;
    }
}