#include<bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int m = a.length();
    int n = b.length();

    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for(int i=0; i<m+1; i++){
        dp[i][0] = i;
    }
    for(int i=0; i<n+1; i++) {
        dp[0][i] = i;
    }

    for(int i=1; i<m+1; i++) {
        for(int j=1; j<n+1; j++) {
            if(a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                int a = dp[i-1][j];
                int b = dp[i][j-1];
                int c = dp[i-1][j-1];

                dp[i][j] = min(a, min(b, c)) + 1;
            }
        }
    }
    
    cout << dp[m][n];
}