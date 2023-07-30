#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    vector<int> suff(n);
    suff[0] = arr[0];

    for(int i=1; i<n; i++) {
        suff[i] = arr[i] + suff[i-1];
    }

    while(q--) {
        int i, j;
        cin >> i >> j;

        i--;
        j--;

        if(i==j) {
            cout << arr[i] << endl;
        }
        else if(i==0) {
            cout << suff[j] << endl;
        }
        else {
            cout << suff[j] - suff[i-1] << endl;
        }
    }
}