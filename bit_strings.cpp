#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long mod = 1e9 + 7;
    long long ans = 1;
    for(int i=1; i<=n; i++) {
        ans = (ans*2)%mod;
    }
    cout << ans%mod << endl;
    return 0;
}