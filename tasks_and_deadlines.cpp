#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ll n;
    cin >> n;

    vector<pair<ll, ll>> arr(n);
    for(ll i=0; i<n; i++) {
        cin >> arr[i].first;
        cin >> arr[i].second;
    }

    sort(arr.begin(), arr.end());

    ll time  = 0;
    ll ans = 0;
    for(ll i=0; i<n; i++) {
        time += arr[i].first;
        ans += arr[i].second - time;
    }

    cout << ans << endl;
    return 0;
}