#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;

    int k;
    multiset<int> st;

    for(int i=0; i<n; i++) {
        cin >> k;

        auto it = st.upper_bound(k);
        if(it == st.end()) {
            st.insert(k);
        }
        else {
            st.erase(it);
            st.insert(k);
        }
    }

    cout << st.size() << endl;
    return 0;
}