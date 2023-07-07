#include<bits/stdc++.h>
using namespace std;

void tower_of_hanoi(int n, int source, int target, int auxiliary) {
    if (n > 0) {
        // Move n-1 disks from source to auxiliary stack
        tower_of_hanoi(n-1, source, auxiliary, target);

        // Move the largest disk from source to target stack
        cout << source << " " << target << endl;

        // Move the n-1 disks from auxiliary to target stack
        tower_of_hanoi(n-1, auxiliary, target, source);
    }
}

int main() {
    int n;
    cin >> n;
    cout << (1 << n) - 1 << endl;  // Minimum number of moves is 2^n - 1
    tower_of_hanoi(n, 1, 3, 2);
    return 0;
}
