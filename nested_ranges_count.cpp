#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
 
// a new data structure defined. Please refer below
// GNU link : https://goo.gl/WVDL6g
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main() {
    int n;
    cin >> n;

    vector<pair<pair<int,int>,int>> arr;
    int start, end;
    for(int i=0; i<n; i++) {
        cin >> start >> end;

        arr.push_back({{start, end}, i});
    }

    sort(arr.begin(), arr.end(), [&](pair<pair<int,int>,int> &p1, pair<pair<int,int>,int> &p2) {
        if(p1.first.first == p2.first.first) {
            return p1.first.second > p2.first.second;
        }
        else {
            return p1.first.first < p2.first.first;
        }
    });

    vector<int> ans1(n, 0);
    vector<int> ans2(n, 0);

    ordered_set st;
    for(int i=0; i<n; i++) {
        st.insert({arr[i].first.second, -1*i});
        ans2[arr[i].second] = st.size() - st.order_of_key({arr[i].first.second, -1*i}) - 1;
    }
    st.clear();

    for(int i=n-1; i>=0; i--) {
        st.insert({arr[i].first.second, -1*i});
        ans1[arr[i].second] = st.order_of_key({arr[i].first.second, -1*i});
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