#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ll x, n;
    cin >> x >> n;

    ll p;
    set<ll> lights; // Using a set to store the positions of traffic lights
    lights.insert(0); // Insert the start position of the street
    lights.insert(x); // Insert the end position of the street

    multiset<ll> diffs; // Using a multiset to store the differences between adjacent lights
    diffs.insert(x); // Initialize with the original passage length without lights

    for(ll i=0; i<n; i++) {
        cin >> p;
        lights.insert(p);

        // Find the iterators to the newly added position and its adjacent positions
        auto it = lights.find(p);
        auto prev_it = prev(it);
        auto next_it = next(it);

        // Calculate the differences for the adjacent positions
        ll diff1 = *it - *prev_it;
        ll diff2 = *next_it - *it;

        // Remove the old differences and insert the new ones
        diffs.erase(diffs.find(*next_it - *prev_it));
        diffs.insert(diff1);
        diffs.insert(diff2);

        // Output the length of the longest passage
        cout << *diffs.rbegin() << " ";
    }
}
