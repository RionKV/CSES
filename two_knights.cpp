#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    cout << 0 << endl;
    for(long long i=2; i<=n; i++) {
        long long ans = 0;

        long long totalWays = ((i*i)*(i*i - 1))/2;
        long long unsafeWays = (8*((i-1)*(i-2)))/2;   //top left corner of a 2x3 or 3x2 grid in a ixi grid

        ans = totalWays - unsafeWays;

        cout << ans<< endl;
    }
}