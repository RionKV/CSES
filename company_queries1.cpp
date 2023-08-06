#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int MAXN = 2e5 + 1;
const int MAXD = 18;   //ceil(log2(2e5 + 1))

// parent[i][j] means 2^jth parent of node i
int parent[MAXN][MAXD];

int jump(int a, int d) {

	for (int i = 0; i < MAXD; i++) {
		if (d & (1 << i)) {    //if the ith bit of d is 1, we have to jump 2^i steps
            if(parent[a][i] == -1) {
                return -1;
            }
            a = parent[a][i];
        }
    }

	return a;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;
    
    parent[1][0] = -1;

    for(int i=2; i<=n; i++) {
        cin >> parent[i][0];
    }

    for (int d = 1; d < MAXD; d++) {
		for (int i = 1; i <= n; i++) {
			if(parent[i][d - 1] != -1) {
                parent[i][d] = parent[parent[i][d - 1]][d - 1];
            }
            else {
                parent[i][d] = -1;
            }
		}
    }

    while(q--) {
        int x, k;
		cin >> x >> k;
		cout << jump(x, k) << endl;
    }
}