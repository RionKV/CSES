#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int mod = 1e9 + 7;

int main() {
    int t;
    cin >> t;

    vector<int> arr(t);
    int val = 0;
    for(int i=0; i<t; i++) {
        cin >> arr[i];
        val = max(val, arr[i]);
    }

    vector<vector<ll>> dp(val, vector<ll>(8, 0));
    for(int i=0; i<8; i++) {
        dp[0][i] = 1;
    }

    for(int i=1; i<val; i++) {
        for(int j=0; j<8; j++) {
            if(j==0 || j==2 || j==3 || j==4 || j==5){    //if a height 2 block has a vertical stick in below part
                dp[i][j] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][3] + dp[i-1][4] + dp[i-1][5])%mod; //it implies there must be a block with vertical stick in its upper part
            }
            else {  //no vertical stick in below part
                dp[i][j] = (dp[i-1][2] + dp[i-1][6] + dp[i-1][7])%mod;  //implies no vertical stick in upper part
            }
        }
    }

    for(int i=0; i<t; i++) {
        cout << (dp[arr[i]-1][2] + dp[arr[i]-1][6])%mod << endl;    //last block has to be of type 2 or 6 where no vertical stick is there at top part, but it cannot be of type 7 which has no division sticks at all
    }


}