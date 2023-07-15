#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i].first;
        cin >> arr[i].second;
    }

    sort(arr.begin(), arr.end(), [&](pair<int, int> &a, pair<int, int> &b){
        return a.second < b.second;
    });

    multiset<int> st;
    for(int i=0; i<k; i++){
        st.insert(0);
    }

    int cnt = 0;
    for(int i=0; i<n; i++) {
        int a = arr[i].first;
        int b = arr[i].second;

        auto it = st.upper_bound(a);

        if(it == st.begin()) {   //no end time less than or equal to a
            continue;
        }

        it--;
        st.erase(it);
        st.insert(b);
        cnt++;
    }

    cout << cnt;
}
