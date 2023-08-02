#include<bits/stdc++.h>
using namespace std;
#define int long long int

void buildTree(int si, int ss, int se, vector<int> &hotels, vector<pair<int, int>> &tree) {
    if(ss == se) {
        tree[si] = {hotels[ss], ss};
        return;
    }

    int mid = (ss + se)/2;
    buildTree(2*si, ss, mid, hotels, tree);
    buildTree(2*si + 1, mid+1, se, hotels, tree);

    if(tree[2*si].first >= tree[2*si + 1].first) {
        tree[si] = tree[2*si];
    }
    else {
        tree[si] = tree[2*si + 1];
    }
}

int solve(int si, int ss, int se, vector<pair<int, int>> &tree, int val) {
    if(tree[si].first < val) {
        return 0;
    }
    
    if(ss == se) {
        tree[si].first -= val;
        return tree[si].second;
    }

    int mid = (ss + se)/2;

    if(tree[2*si].first >= val) {
        int idx = solve(2*si, ss, mid, tree, val);
        
        if(tree[2*si].first >= tree[2*si + 1].first) {
            tree[si] = tree[2*si];
        }
        else {
            tree[si] = tree[2*si + 1];
        }

        return idx;
    }
    else {
        int idx = solve(2*si + 1, mid+1, se, tree, val);

        if(tree[2*si].first >= tree[2*si + 1].first) {
            tree[si] = tree[2*si];
        }
        else {
            tree[si] = tree[2*si + 1];
        }
        
        return idx;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> hotels(n+1);
    for(int i=1; i<=n; i++) {
        cin >> hotels[i];
    }

    vector<int> groups(m+1);
    for(int i=1; i<=m; i++) {
        cin >> groups[i];
    }

    vector<pair<int,int>> tree(4*n, {INT_MIN, 0});
    buildTree(1, 1, n, hotels, tree);

    for(int i=1; i<=m; i++) {
        cout << solve(1, 1, n, tree, groups[i]) << " ";
    }

    return 0;
}