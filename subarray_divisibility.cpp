#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    int n;
    cin >> n;

    vector<ll> mods(n, 0);    //contains count of all the +ve remainders, ranging from 0 to n-1
    ll v;
    ll presum = 0;
    for(int i=0; i<n; i++){
        cin >> v;

        presum += v;
        mods[(presum % n + n)%n]++;
    }

    ll ans = 0;
    for(int i=0; i<n; i++){
        if(mods[i]){
            ans += (mods[i]) * (mods[i]-1)/2;   //all unique pairs of equal remainders
        }
    }

    ans += mods[0];
    cout << ans << endl;
}