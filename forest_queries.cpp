#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, q;
    cin >> n >> q;

    vector<vector<char>> forest(n, vector<char>(n));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> forest[i][j];
        }
    }

    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<n+1; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];

            if(forest[i-1][j-1] == '*') {
                dp[i][j]++;
            }
        }
    }

    while(q--) {
        int y1, x1, y2, x2;
        cin >> x1 >> y1 >> x2 >> y2;

        int ans = 0;
        ans = dp[x2][y2] + dp[x1 - 1][y1 - 1] - dp[x2][y1 - 1] - dp[x1 - 1][y2];
        cout << ans << endl;
    }

}