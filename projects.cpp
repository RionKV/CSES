#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    int n;
    cin >> n;

    vector<pair<pair<int, int>, int>> arr(n);
    for(int i=0; i<n; i++) {
        int s, e, v;
        cin >> s >> e >> v;
        arr[i] = {{e, s}, v};
    }

    sort(arr.begin(), arr.end());

    vector<ll> dp(n+1, 0);

    for(int i=1; i<n+1; i++){
        int j = lower_bound(arr.begin(), arr.end(), make_pair(make_pair(arr[i-1].first.second, 0), 0)) - arr.begin();

        dp[i] = max(dp[i-1], dp[j] + arr[i-1].second);
    }

    cout << dp[n];
}