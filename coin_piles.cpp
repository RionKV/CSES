#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        long long a, b;
        cin >> a >> b;
        
        long long val1 = 2*b - a;
        long long val2 = 2*a - b;
        if(a==0 && b==0) {
            cout << "YES" << endl;
        }
        else if((a==0 && b!=0) || (a!=0 && b==0)) {
            cout << "NO" << endl;
        }
        else if(val1>=0 && val1%3==0 && val2>=0 && val2%3==0) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}