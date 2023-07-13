#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack<pair<int, int>> s;
    s.push({0, 0});
    int v;

    for(int i=1; i<=n; i++){
        cin >> v;

        while(!s.empty() && s.top().first>=v) {
            s.pop();
        }

        cout << s.top().second << " ";
        s.push({v, i});
    }

    
}