#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int mod = 1e9 + 7;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }


    vector<ll> dp(x+1, 0);
    dp[0] = 1;

    for(int i=0; i<n; i++) {
        for(int j=1; j<x+1; j++) {
            if(j - arr[i] >= 0) {
                dp[j] = (dp[j] + dp[j-arr[i]])%mod;
            }
        }
    }

    cout << dp[x];
}