#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7; 

int main() {
    int n;
    cin >> n;

    int tsum = n*(n+1)/2;

    if(tsum%2 != 0) {
        cout << 0;
        return 0;
    }

    int w = tsum/2;

    vector<vector<int>> dp(n+1, vector<int>(w+1, 0));
    for(int i=0; i<n+1; i++) dp[i][0] = 1;

    for(int i=1; i<w+1; i++) {
        for(int j=1; j<n+1; j++) {
            if(i >= j-1) {
                dp[j][i] = (dp[j-1][i] + dp[j-1][i-(j-1)])%mod;
            }
            else {
                dp[j][i] = dp[j-1][i]%mod;
            }
        }
    }

    cout << dp[n][w]%mod;
    
}