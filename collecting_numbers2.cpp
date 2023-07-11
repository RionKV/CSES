#include<bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n+1);
    vector<int> pos(n+1);

    for(int i=1; i<=n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    int ans = 1;
    for(int i=1; i<n; i++) {
        if(pos[i] > pos[i+1]) {
            ans++;
        }
    }

    int l,r;
    set<pair<int, int>> st;
    while(m--) {
        cin >> l >> r;

        if(arr[l]-1>=1) {
            st.insert({arr[l]-1, arr[l]});
        }
        if(arr[l]+1 <=n) {
            st.insert({arr[l], arr[l]+1});
        }
        if(arr[r]-1>=1) {
            st.insert({arr[r]-1, arr[r]});
        }
        if(arr[r]+1 <=n) {
            st.insert({arr[r], arr[r]+1});
        }

        for(pair<int,int> p : st) {
            if(pos[p.first] > pos[p.second]) ans--;
        }

        swap(arr[l], arr[r]);
        pos[arr[l]] = l;
        pos[arr[r]] = r;

        if(arr[l]-1>=1) {
            st.insert({arr[l]-1, arr[l]});
        }
        if(arr[l]+1 <=n) {
            st.insert({arr[l], arr[l]+1});
        }
        if(arr[r]-1>=1) {
            st.insert({arr[r]-1, arr[r]});
        }
        if(arr[r]+1 <=n) {
            st.insert({arr[r], arr[r]+1});
        }

        for(pair<int,int> p : st) {
            if(pos[p.first] > pos[p.second]) ans++;
        }

        cout << ans << endl;
        st.clear();
    }
}