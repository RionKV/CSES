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

    int i=0; 
    int j=0;
    ll sum = 0;
    ll ans = 0;
    sum += arr[i];
    while(j<n) {
        if(sum == x) {
            ans++;
            sum -= arr[i];
            i++;
            j++;
            if(j<n) {
                sum += arr[j];
            }
        }
        else if(sum < x) {
            j++;
            sum += arr[j];
        }
        else {
            sum -= arr[i];
            i++;
        }
    }

    cout << ans << endl;
}
