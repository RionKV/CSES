#include<bits/stdc++.h>
using namespace std;
#define int long long int

void buildTree(int si, int ss, int se, vector<int> &present, vector<int> &tree) {
    if(ss == se) {
        tree[si] = present[ss];
        return;
    }

    int mid = (ss + se)/2;
    buildTree(2*si, ss, mid, present, tree);
    buildTree(2*si + 1, mid+1, se, present, tree);

    tree[si] = tree[2*si] + tree[2*si + 1];
}

void update(int si, int ss, int se, int q, vector<int> &tree, int val) {
    if(ss > q || se < q) {
        return;
    }

    if(ss==se && ss == q) {
        tree[si] = val;
        return;
    }

    int mid = (ss + se)/2;
    update(2*si, ss, mid, q, tree, val);
    update(2*si + 1, mid+1, se, q, tree, val);

    tree[si] = tree[2*si] + tree[2*si + 1];
}

int solve(int si, int ss, int se, int qs, int qe, vector<int> &tree) {
    if(si >= tree.size()) {
        return 0;
    }

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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n+1);
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }

    vector<int> present(n+1, 1);  //check whether the element is present(1) or has been deleted(0)
    vector<int> tree(4*n, 0);

    buildTree(1, 1, n, present, tree);

    for(int i=1; i<=n; i++) {
        int p;
        cin >> p;

        int l = 1;
        int r = n;

        while(l != r) {
            int mid = (l + r)/2;

            int till_mid = solve(1, 1, n, 1, mid, tree);  //checks how many elements are present till index mid

            if(till_mid > p) {
                r = mid - 1;
            }
            else if(till_mid < p) {
                l = mid + 1;
            }
            else {
                if(present[mid]) {
                    l = mid;
                    break;
                }
                else {
                    r = mid - 1;
                }
            }
        }

        present[l] = 0;
        update(1, 1, n, l, tree, 0);
        cout << arr[l] << " ";
    }
}