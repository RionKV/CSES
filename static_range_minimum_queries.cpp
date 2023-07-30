#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int INF = 1e17;

void buildTree(int si, int ss, int se, vector<int> &tree, vector<int> &arr) { //segment index, start, end
    if(ss == se) {
        tree[si] = arr[ss];
        return;
    }

    int mid = (ss + se)/2;

    buildTree(2*si, ss, mid, tree, arr);   //build left subtree
    buildTree(2*si + 1, mid+1, se, tree, arr);  //build right subtree

    tree[si] = min(tree[2*si], tree[2*si + 1]);  //take min of left and right node
}

int solve(int si, int ss, int se, int qs, int qe, vector<int> &tree) {
    if(ss > qe || se < qs) {   //out of range
        return INF;
    }

    if(ss >= qs && se <= qe) { //completely inside range
        return tree[si];
    }

    int mid = ss + (se - ss)/2;

    int l = solve(2*si, ss, mid, qs, qe, tree);
    int r = solve(2*si + 1, mid+1, se, qs, qe, tree);

    return min(l, r);
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

    //build segment tree where each index represents segment tree node index i.e 1,2,3.....4n
    //si 1 represents whole array where ss=1 and se=n
    //si 2 represents from index 1 to mid  (left node of si 1)
    //si 3 fron mid+1 to se  (right node of si 2)
    //all indexes of tree won't be filled
    vector<int> tree(4*n, INF);

    buildTree(1, 1, n, tree, arr);


    while(q--) {
        int i, j;
        cin >> i >> j;

        cout << solve(1, 1, n, i, j, tree) << endl;
    }
}