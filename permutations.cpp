#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    if(n==1) {
        cout << 1;
    }
    else if(n==2 || n==3) {
        cout << "NO SOLUTION";
    }
    else if(n==4) {
        cout << 2 << " " << 4 << " " << 1 << " " << 3;
    }
    else {
        int sum = n + 1;
        vector<int> arr(n);
        if(n%2 == 0) {
            int val = n;
            for(int i=0; i<n/2; i++) {
                arr[i] = val;
                val -= 2;
            }

            for(int i=n/2; i<n; i++) {
                arr[i] = sum - arr[n - i - 1];
            }
        }
        else {
            sum = n;
            int val = n-1;
            for(int i=0; i<n/2; i++) {
                arr[i] = val;
                val -=2;
            }
            arr[n/2] = n;
            for(int i=n-1; i>=(n/2)+1; i--) {
                arr[i] = sum - arr[n-i-1];
            }
        }

        for(int i=0; i<n; i++) {
            cout << arr[i] << " ";
        }
    }
}