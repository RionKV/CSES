#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    if(k==1) {
        for(int i=0; i<n; i++) {
            cout << arr[i] << " ";
        }
        return 0;
    }
    if(k==2) {
        for(int i=0; i<n-1; i++) {
            cout << min(arr[i], arr[i+1]) << " ";
        }
        return 0;
    }

    vector<pair<int, int>> temp(k);
    for(int i=0; i<k; i++) {
        temp[i] = {arr[i], i};
    }
    sort(temp.begin(), temp.end());

    set<pair<int, int>> left;
    set<pair<int, int>> right;

    for(int i=0; i<(k/2)+(k%2); i++) {
        left.insert(temp[i]);
    }
    for(int i=(k/2)+(k%2); i<k; i++) {
        right.insert(temp[i]);
    }

    cout << (*(left.rbegin())).first << " ";

    for(int i=1; i<n-k+1; i++) {
        if(left.count({arr[i-1], i-1})) {
            left.erase({arr[i-1], i-1});
        }
        else {
            right.erase({arr[i-1], i-1});
        }

        if((*(left.rbegin())) < make_pair(arr[k-1+i], k-1+i)) {
            right.insert({arr[k-1+i], k-1+i});
        }
        else {
            left.insert({arr[k-1+i], k-1+i});
        }

        while(left.size() < (k/2)+(k%2)) {
            pair<int, int> p = (*(right.begin()));
            left.insert(p);
            right.erase(p);
        }
        while(left.size() > (k/2)+(k%2)) {
            pair<int, int> p = (*(left.rbegin()));
            right.insert(p);
            left.erase(p);
        }

        cout << (*(left.rbegin())).first << " ";
    }
}