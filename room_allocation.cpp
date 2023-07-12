#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<pair<int, int>, int>> arr;
    int start, end;
    for(int i=0; i<n; i++) {
        cin >> start >> end;

        arr.push_back({{start, end}, i});
    }

    sort(arr.begin(), arr.end());

    int trooms = 0;
    int roomNum = 0;
    vector<int> ans(n);

    priority_queue<pair<int, int>> pq;
    for(int i=0; i<n; i++) {
        if(pq.empty()) {
            roomNum++;
            pq.push({-1*arr[i].first.second, roomNum});
            ans[arr[i].second] = roomNum;
        }
        else {
            pair<int, int> mini = pq.top();

            if(-1*mini.first < arr[i].first.first) {
                pq.pop();
                pq.push({-1*arr[i].first.second, mini.second});
                ans[arr[i].second] = mini.second;
            }
            else {
                roomNum++;
                pq.push({-1*arr[i].first.second, roomNum});
                ans[arr[i].second] = roomNum;
            }
        }

        trooms = max(trooms, (int)pq.size());
    }

    cout << trooms << endl;
    for(int i=0; i<n; i++) {
        cout << ans[i] << " ";
    }
}