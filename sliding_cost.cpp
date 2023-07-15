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
        for(int i=0; i<n; i++){
            cout << 0 << " ";
        }
        return 0;
    }
    if(k==2) {
        for(int i=0; i<n-1; i++) {
            cout << max(arr[i], arr[i+1]) - min(arr[i], arr[i+1]) << " ";
        }
        return 0;
    }

    vector<pair<int, int>> temp;
    for(int i=0; i<k; i++) {
        temp.push_back({arr[i], i});
    }

    sort(temp.begin(), temp.end());

    set<pair<int,int>> left;
    set<pair<int, int>> right;
    long long lsum = 0;
    long long rsum = 0;

    for(int i=0; i<(k/2)+(k%2); i++) {
        left.insert(temp[i]);
        lsum += temp[i].first;
    }
    for(int i=(k/2)+(k%2); i<k; i++){
        right.insert(temp[i]);
        rsum += temp[i].first;
    }

    int v = (*(left.rbegin())).first;
    cout << (v*left.size() - lsum) + (rsum - v*right.size()) << " ";

    for(int i=1; i<n-k+1; i++){
        if(left.count({arr[i-1], i-1})) {
            left.erase({arr[i-1], i-1});
            lsum -= arr[i-1];
        }
        else {
            right.erase({arr[i-1], i-1});
            rsum -= arr[i-1];
        }

        if((*(left.rbegin())) > make_pair(arr[k-1+i], k-1+i)) {
            left.insert({arr[k-1+i], k-1+i});
            lsum += arr[k-1+i];
        }
        else {
            right.insert({arr[k-1+i], k-1+i});
            rsum += arr[k-1+i];
        }

        while(left.size() < (k/2)+(k%2)) {
            pair<int,int> p = (*(right.begin()));
            right.erase(p);
            left.insert(p);
            rsum -= p.first;
            lsum += p.first;
        }
        while(left.size() > (k/2)+(k%2)) {
            pair<int,int> p = (*(left.rbegin()));
            left.erase(p);
            right.insert(p);
            lsum -= p.first;
            rsum += p.first;
        }

        v = (*(left.rbegin())).first;
        cout << (v*left.size() - lsum) + (rsum - v*right.size()) << " ";
    }

}