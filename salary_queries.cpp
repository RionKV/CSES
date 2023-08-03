#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
 
// a new data structure defined. Please refer below
// GNU link : https://goo.gl/WVDL6g
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int maxK = 1e8;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, q;
    cin >> n >> q;

    vector<int> arr(n+1);
    ordered_set st;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];

        st.insert({arr[i], i});
    }

    while(q--) {
        char ch;
        cin >> ch;

        if(ch == '!') {
            int k, x;
            cin >> k >> x;

            st.erase({arr[k], k});
            arr[k] = x;
            st.insert({arr[k], k});
        }
        else {
            int a, b;
            cin >> a >> b;

            int ans = st.order_of_key({b, maxK}) - st.order_of_key({a-1, maxK});

            cout << ans << endl;
        }
    }

}