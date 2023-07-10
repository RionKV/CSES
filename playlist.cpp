#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ll n;
    cin >> n;

    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    set<ll> st;
    ll start = 0;
    ll ans = 0;

    for(ll i=0; i<n; i++) {
        while(st.count(arr[i])) {
            st.erase(arr[start]);
            start++;
        }

        st.insert(arr[i]);
        ans = max(ans, (ll)st.size());
    }

    cout << ans << endl;

    return 0;
}
