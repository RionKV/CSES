#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    int i = 1;
    long long ans = 0;

    while(pow(5,i) <= n) {
        ans += n/pow(5, i);
        i++;
    }

    cout << ans << endl;
}