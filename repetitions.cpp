#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    long long n = s.length();
    if(n == 1) {
        cout << 1;
    }
    else {
        long long ans = 0;
        long long cnt = 1;
        for(int i = 0; i<n-1; i++) {
            if(s[i] == s[i+1]) {
                cnt++;
            }
            else {
                cnt = 1;
            }

            ans = max(ans, cnt);
        }

        cout << ans;
    }
}