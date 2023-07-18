#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    int tsum = 0;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        tsum += arr[i];
    }

    vector<vector<bool>> dp(n+1, vector<bool>(tsum+1, 0));
    for(int i=0; i<tsum+1; i++) dp[0][i] = false;
    for(int i=0; i<n+1; i++) dp[i][0] = true;

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<tsum+1; j++) {
            if(j >= arr[i-1]) {
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    vector<int> ans;
    for(int i=1; i<tsum+1; i++) {
        if(dp[n][i]) ans.push_back(i);
    }

    cout << ans.size() << endl;
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
}