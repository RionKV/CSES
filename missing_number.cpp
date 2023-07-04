#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    vector<long long> arr(n-1);
    for(int i=0; i<n-1; i++) {
        cin >> arr[i];
    }


    int ans = 0;
    for(int i=0; i<n-1; i++) {
        ans += ((i+1) - arr[i]);
    }

    ans += n;
    cout << ans;

}