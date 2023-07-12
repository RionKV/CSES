#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    ll s = 0;
    ll e = (ll)arr[n-1] * (ll)t;
    ll m = s + (e-s)/2;
    ll ans = 0;

    while(s <= e) {
        ll sum = 0;
        for(int i=0; i<n; i++) {
            sum += (m/arr[i]);
            if(sum >= t) {
                break;
            }
        }

        if(sum >= t) {
            ans = m;
            e = m-1;
        }
        else {
            s = m+1;
        }

        m = s + (e-s)/2;
    }

    cout << ans << endl;
}