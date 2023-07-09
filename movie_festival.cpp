#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> arr;
    for(int i=0; i<n; i++) {
        int start, end;
        cin >> start >> end;

        arr.push_back({start, end});
    }

    sort(arr.begin(), arr.end(), [&](pair<int,int> a, pair<int,int> b) {
        return a.second < b.second;
    });

    int ans = 1;
    int v = arr[0].second;
    for(int i=1; i<n; i++) {
        if(arr[i].first >= v) {
            ans++;
            v = arr[i].second;
        }
    }

    cout << ans << endl;
}