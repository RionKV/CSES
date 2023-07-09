#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> arr;

    for(int i=0; i<n; i++) {
        int in, out;
        cin >> in >> out;

        arr.push_back({in, 1});
        arr.push_back({out, -1});
    }

    sort(arr.begin(), arr.end());

    int ans = 0;
    int cnt = 0;

    for(pair<int,int> p : arr) {
        cnt += p.second;
        ans = max(ans, cnt);
    }

    cout << ans << endl;
    return 0;
}