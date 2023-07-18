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

    vector<ll> ans;

    for(ll i=0; i<n; i++) {
        auto it = lower_bound(ans.begin(), ans.end(), arr[i]);

        if(it == ans.end()) {
            ans.push_back(arr[i]);
        }
        else {
            *it = arr[i];
        }
    }

    cout << ans.size(); //ans does not contain the actual subsequence but helps in finding LIS
}