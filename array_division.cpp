#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    int n, k;
    cin >> n >> k;

    vector<ll> arr(n);
    ll e = 0;
    ll s = 0;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        e += arr[i];
        s = max(s, arr[i]);
    }

    ll ans = e;
    ll m = s + (e-s)/2;

    while(s <= e) {
        ll sum = 0;
        ll divs = 1;
        for(int i=0; i<n; i++) {
            if(sum + arr[i] > m) {
                divs++;
                sum = 0;
            }
            sum += arr[i];
        }

        if(divs > k){
            s = m + 1;
        }
        else {
            e = m - 1;
            if(m < ans){
                ans = m;
            }
        }

        m = s + (e-s)/2;
    }

    cout << ans << endl;

}