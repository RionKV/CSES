#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    vector<ll> dp(n+1, 0);
    dp[0] = 1;

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<=6; j++){
            if(i-j >= 0) {
                dp[i] = (dp[i]%mod + dp[i-j]%mod)%mod;
            }
        }
    }

    cout << dp[n]%mod;
}