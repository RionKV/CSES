#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int mod = 1e9 + 7;

int main() {
    int n, x;
    cin >> n >> x;

    vector<ll> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr.rbegin(), arr.rend());

    vector<ll> dp(x+1, 0);
    dp[0] = 1;

    for(int i=1; i<x+1; i++){
        for(int j=n-1; j>=0; j--){
            if(i - arr[j] >= 0) { 
                dp[i] = (dp[i] + dp[i - arr[j]])%mod;
            }
            else break;
        }
    }

    cout << dp[x]%mod;

}
