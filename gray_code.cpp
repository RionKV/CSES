#include<bits/stdc++.h>
using namespace std;

vector<string> solve(int n) {
    if(n<=0) {
        return {"0"};
    }
    if(n==1) {
        return {"0", "1"};
    }

    vector<string> prev = solve(n-1);
    vector<string> res;

    for(int i=0; i<prev.size(); i++) {
        res.push_back("0"+prev[i]);
    }
    for(int i=prev.size()-1; i>=0; i--) {
        res.push_back("1"+prev[i]);
    }

    return res;
}

int main() {
    int n;
    cin >> n;
    
    vector<string> ans = solve(n);
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << endl;
    }

    return 0;
}