#include<bits/stdc++.h>
using namespace std;
#define int long long int

void buildTree(int si, int ss, int se, vector<int> &arr, vector<pair<int, int>> &tree) {
    if(ss == se) {
        tree[si].first = arr[ss];
        tree[si].second = arr[ss];
        return;
    }

    int mid = (ss + se)/2;
    buildTree(2*si, ss, mid, arr, tree);
    buildTree(2*si + 1, mid+1, se, arr, tree);

    tree[si].first = tree[2*si].first + tree[2*si + 1].first;
    tree[si].second = max(tree[2*si].second, tree[2*si].first + tree[2*si + 1].second);
}

void update(int si, int ss, int se, int q, vector<pair<int, int>> &tree, int up, int del) {
    if(si >= tree.size()) {
        return;
    }

    if(ss > q || se < q) {
        return;
    }

    if(ss == se && ss == q) {
        tree[si].first = up;
        tree[si].second = up;
        return;
    }

    int mid = (ss + se)/2;
    update(2*si, ss, mid, q, tree, up, del);
    update(2*si + 1, mid+1, se, q, tree, up, del);

    tree[si].first = tree[2*si].first + tree[2*si + 1].first;
    tree[si].second = max(tree[2*si].second, tree[2*si].first + tree[2*si + 1].second);
}

pair<int, int> solve(int si, int ss, int se, int qs, int qe, vector<pair<int, int>> &tree) {
    if(ss > qe || se < qs) {
        return {0, 0};
    }

    if(ss >= qs && se <= qe) {
        return tree[si];
    }

    int mid = (ss + se)/2;

    pair<int, int> l = solve(2*si, ss, mid, qs, qe, tree);
    pair<int, int> r = solve(2*si + 1, mid+1, se, qs, qe, tree);

    pair<int, int> ans;
    ans.first = l.first + r.first;
    ans.second = max(l.second, l.first + r.second);

    return ans;
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

    vector<pair<int, int>> tree(4*n, {0, 0});  //max sum, max prefix sum

    buildTree(1, 1, n, arr, tree);

    while(q--) {
        int f;
        cin >> f;

        if(f==1) {
            int k, u;
            cin >> k >> u;

            int up = u;
            int del = arr[k];
            arr[k] = up;

            update(1, 1, n, k, tree, up, del);
        }
        else {
            int a, b;
            cin >> a >> b;

            int res = solve(1, 1, n, a, b, tree).second;

            cout << max(res, (int)0) << endl;
        }
    }
}