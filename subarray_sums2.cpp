#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    int n;
    ll x;
    cin >> n >> x;

    vector<ll> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    unordered_map<ll, ll> mp;
    mp[0] = 1;

    vector<ll> pre(n);
    pre[0] = arr[0];
    for(int i=1; i<n; i++) {
        pre[i] = arr[i] + pre[i-1];
    }

    ll ans = 0;
    for(int i=0; i<n; i++) {
        if(mp[pre[i]-x] >= 1) {
            ans += mp[pre[i] - x];
        }
        mp[pre[i]]++;
    }

    cout << ans << endl;


    return 0;
}