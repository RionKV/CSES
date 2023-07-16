#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    vector<ll> dp(x+1, INT_MAX);
    dp[0] = 0;

    for(int i=1; i<x+1; i++) {
        for(int j=n-1; j>=0; j--){
            if(i-arr[j] >= 0) {
                dp[i] = min(1 + dp[i-arr[j]], dp[i]);
            }
        }
    }

    if(dp[x] != INT_MAX) cout << dp[x];
    else cout << -1;
}