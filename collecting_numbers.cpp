#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    unordered_map<long long, long long> mp;
    for(long long i=0; i<n; i++) {
        long long v;
        cin >> v;
        mp[v] = i;
    }

    long long ans = 0;
    for(long long i=1; i<=n; i++) {
        long long j=i+1;
        while((j<=n) && (mp[j] > mp[j-1])) {
            j++;
        }
        ans++;
        i = j-1;
    }

    cout << ans << endl;
}