#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> dp(n, vector<int>(m+1, 0));

    if(arr[0] != 0) {
        dp[0][arr[0]] = 1;
    }
    else {
        for(int i=1; i<m+1; i++) {
            dp[0][i] = 1;
        }
    }

    for(int i=1; i<n; i++) {
        if(arr[i] != 0) {
            if(arr[i]-1 >= 1) dp[i][arr[i]] = (dp[i][arr[i]] + dp[i-1][arr[i]-1])%mod;
            dp[i][arr[i]] = (dp[i][arr[i]] + dp[i-1][arr[i]])%mod;
            if(arr[i]+1 <= m) dp[i][arr[i]] = (dp[i][arr[i]] + dp[i-1][arr[i]+1])%mod;
        }
        else {
            for(int j=1; j<m+1; j++) {
                if(j-1 >= 1) dp[i][j] = (dp[i][j] + dp[i-1][j-1])%mod;
                dp[i][j] = (dp[i][j] + dp[i-1][j])%mod;
                if(j+1 <= m) dp[i][j] = (dp[i][j] + dp[i-1][j+1])%mod;
            }
        }
    }

    int ans = 0;
    for(int i=1; i<m+1; i++){
        ans = (ans + dp[n-1][i])%mod;
    }

    cout << ans%mod;
}