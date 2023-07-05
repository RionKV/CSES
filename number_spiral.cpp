#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int x;
        int y;
        cin >> x;
        cin >> y;

        long long a = x-1;
        long long b = y-1;

        if(a<=b && b%2==0) {
            long long ans = (b+1)*(b+1) - a;
            cout << ans << endl;
        }
        else if(b<=a && a%2) {
            long long ans = (a+1)*(a+1) - b;
            cout << ans << endl;
        }
        else if(a<=b && b%2) {
            long long ans = b*b + a + 1;
            cout << ans << endl;
        }
        else if(b<=a && a%2==0) {
            long long ans = a*a + b + 1;
            cout << ans << endl;
        }
    }
}