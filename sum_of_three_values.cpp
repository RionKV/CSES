#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    int n;
    ll x;
    cin >> n >> x;

    vector<pair<ll, int>> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }

    if(n <= 2) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    sort(arr.begin(), arr.end());

    int i = 0;
    int j = 1;
    int k = n - 1;

    while (i < k) {
        ll sum = arr[i].first + arr[j].first + arr[k].first;
        if (sum == x) {
            cout << arr[i].second+1 << " " << arr[j].second+1 << " " << arr[k].second+1;
            return 0;
        } 
        else if (sum > x) {
            k--;
        } 
        else {
            j++;
        }
        if (j >= k) {
            i++;
            j = i + 1;
            k = n - 1;
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
