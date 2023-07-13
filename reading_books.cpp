#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ll n;
    cin >> n;

    vector<ll> arr(n);
    for(ll i=0; i<n; i++) {
        cin >> arr[i];
    }

    if(n==1) {
        cout << (ll)2*arr[0] << endl;
        return 0;
    }

    sort(arr.begin(), arr.end());

    vector<ll> pre(n);
    pre[0] = arr[0];
    for(ll i=1; i<n; i++) {
        pre[i] = arr[i] + pre[i-1];
    }

    vector<ll> suff(n);
    suff[n-1] = arr[n-1];

    for(ll i=n-2; i>=0; i--) {
        suff[i] = arr[i] + suff[i+1];
    }

    ll ans = 0;
    for(ll i=n-1; i>=1; i--) {
        if(suff[i] >= pre[i-1]) {
            if(suff[i]==arr[i]) {
                ans = 2*suff[i];
            }
            else {
                ans = suff[i] + pre[i-1];
            }
            break;
        }
    }

    cout << ans << endl;
}