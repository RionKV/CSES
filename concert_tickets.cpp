#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    multiset<int> mp;
    for(int i=0; i<n; i++) {
        int h;
        cin >> h;
        mp.insert(h);
    }

    for(int i=0; i<m; i++) {
        int t;
        cin >> t;

        auto it = mp.upper_bound(t);

        if(it == mp.begin()) {
            cout << -1 << endl;
        }
        else {
            it--;
            cout << *it << endl;
            mp.erase(it);
        }
    }
}
