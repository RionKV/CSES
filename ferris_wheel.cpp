#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    int n,x;
    cin >> n >> x;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int ans = 0;
    int i = 0;
    int j = n-1;
    while(i<=j && j>=0 && i<n) {
        if(arr[i]+arr[j] <=x) {
            i++;
            j--;
            ans++;
        }
        else {
            j--;
            ans++;
        }
    }

    cout << ans << endl;
    return 0;

}