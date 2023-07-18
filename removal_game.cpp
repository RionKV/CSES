#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ll n;
    cin >> n;

    ll tsum = 0;
    vector<ll> arr(n);
    vector<vector<ll>> dp(n, vector<ll>(n, 0));  //dp[i][j] means max difference between s1 and s2 for subarray i -> j, s1 and s2 are scores respectively
    for(ll i=0; i<n; i++) {
        cin >> arr[i];
        tsum += arr[i];
        dp[i][i] = arr[i];  //for subarray of size 1, s1 will be arr[i] and s2 will be 0, so max(s1 - s2) = arr[i]
    }

    for(int i=n-1; i>=0; i--) {
        for(int j=i+1; j<=n-1; j++) {
            ll choice1 = arr[i] - dp[i+1][j];
            ll choice2 = arr[j] - dp[i][j-1];

            dp[i][j] = max(choice1, choice2);
        }
    }

    ll ans = (tsum + dp[0][n-1])/2;   //s1+s2=tsum and s1-s2=dp[0][n-1], ans is s1 basically
    cout << ans;
}