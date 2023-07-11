#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<pair<int,int>,int>> arr;
    int x, y;
    for(int i=0; i<n; i++) {
        cin >> x >> y;

        arr.push_back({{x, y}, i});
    }

    vector<int> ans1(n, 0);
    vector<int> ans2(n, 0);

    sort(arr.begin(), arr.end(), [&](pair<pair<int,int>,int> &p1, pair<pair<int,int>,int> &p2) {
        if(p1.first.first == p2.first.first) {
            return p1.first.second > p2.first.second;
        }
        else {
            return p1.first.first < p2.first.first;
        }
    });

    int maxEnd = 0;
    for(int i=0; i<n; i++) {
        if(arr[i].first.second <= maxEnd) {
            ans2[arr[i].second] = 1;
        }

        maxEnd = max(maxEnd, arr[i].first.second);
    }

    int minEnd = 1e9 + 1;
    for(int i=n-1; i>=0; i--) {
        if(arr[i].first.second >= minEnd) {
            ans1[arr[i].second] = 1;
        }

        minEnd = min(minEnd, arr[i].first.second);
    }

    for(int i=0; i<n; i++) {
        cout << ans1[i] << " ";
    }
    cout << endl;
    for(int i=0; i<n; i++) {
        cout << ans2[i] << " ";
    }
    cout << endl;
    return 0;

}