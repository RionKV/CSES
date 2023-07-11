#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    queue<int> q;
    for(int i=0; i<n; i++) {
        q.push(i+1);
    }

    while(!q.empty()) {
        int a = q.front();
        q.pop();
        q.push(a);

        int b = q.front();
        q.pop();
        cout << b << " ";
    }
}
