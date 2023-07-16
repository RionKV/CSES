#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> dp(n+1, 1e9);
    dp[0] = 0;

    for(int i=1; i<n+1; i++) {
        int val = i;

        while(val > 0) {
            dp[i] = min(dp[i], 1 + dp[i - val%10]);
            val = val/10;
        }
    }

    cout << dp[n];
}