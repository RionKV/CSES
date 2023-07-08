#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    vector<long long> arr(n);
    for(long long i=0; i<n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    long long ans = 1;
    for(long long i=1; i<n; i++) {
        if(arr[i] != arr[i-1]) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}