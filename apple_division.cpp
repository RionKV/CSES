#include<bits/stdc++.h>
using namespace std;

long long solve(vector<long long> &arr, long long currSum, long long tsum, int i) {
    if(i==0) {
        return abs((tsum - currSum) - currSum);
    }

    return min(solve(arr, currSum+arr[i], tsum, i-1), solve(arr, currSum, tsum, i-1));
}

int main() {
    int n;
    cin >> n;

    vector<long long> arr(n);
    long long tsum = 0;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        tsum += arr[i];
    }

    long long ans = solve(arr, 0, tsum, n-1);
    cout << ans << endl;

    return 0;
}
