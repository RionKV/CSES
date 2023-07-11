#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
 
// a new data structure defined. Please refer below
// GNU link : https://goo.gl/WVDL6g
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main() {
    int n;
    int k;
    cin >> n;
    cin >> k;

    ordered_set st;
    for(int i=0; i<n; i++) {
        st.insert(i+1);
    }

    int i = k%n;
    while(n--) {
        auto it = st.find_by_order(i);
        cout << *it << " ";
        st.erase(it);
        if(n) i = (i%n + k)%n;
    }
}