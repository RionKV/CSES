#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    int n, k;
    cin >> n >> k;

    vector<ll> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int l=0, r=0;
    ll cnt = 0, ans = 0;  //cnt is the count of distinct values in the subarray
    unordered_map<ll, ll> mp;

    while(l<n) {
        while(r<n && (cnt + (mp[arr[r]]==0))<=k) {
            mp[arr[r]]++;
            if(mp[arr[r]]==1) cnt++;
            r++;
        }

        ans += r-l;
        cnt -= (mp[arr[l]]==1);
        mp[arr[l]]--;
        l++;
    }

    cout << ans << endl;
    return 0;
}