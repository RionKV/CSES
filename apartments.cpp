#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> applicants(n);
    for (ll i = 0; i < n; ++i) {
        cin >> applicants[i];
    }

    vector<ll> apartments(m);
    for (ll i = 0; i < m; ++i) {
        cin >> apartments[i];
    }

    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    ll count = 0; 
    ll i = 0;    
    ll j = 0;   

    while(i < n && j < m) {
        if(abs(applicants[i] - apartments[j]) <= k) {
            count++;
            i++;
            j++;
        }
        else if(apartments[j] < applicants[i]) {
            j++;
        }
        else {
            i++;
        }
    }

    cout << count << endl;

    return 0;
}
