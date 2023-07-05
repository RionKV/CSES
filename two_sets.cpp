#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n;
    cin >> n;

    // Calculate the total sum
    long long tsum = n * (n + 1) / 2;

    // Check if the sum is odd
    if (tsum % 2 != 0) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    // Calculate the target sum for each set
    long long targetSum = tsum / 2;

    vector<long long> set1, set2;
    long long sum1 = 0, sum2 = 0;

    for (long long i = n; i >= 1; i--) {
        if (sum1 + i <= targetSum) {
            sum1 += i;
            set1.push_back(i);
        } else {
            sum2 += i;
            set2.push_back(i);
        }
    }

    // Output the sets
    cout << set1.size() << endl;
    for (long long num : set1) {
        cout << num << " ";
    }
    cout << endl;

    cout << set2.size() << endl;
    for (long long num : set2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
