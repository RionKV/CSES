#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
struct DSU {
    vector<int> parent, size;
 
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }
 
    int find(int v) {
        if (v == parent[v]) {
            return v;
        }
        return parent[v] = find(parent[v]);
    }
 
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a != b) {
            if (size[a] < size[b]) {
                swap(a, b);
            }
    
            parent[b] = a;
            size[a] += size[b];  
        }
    }
 
    int getSize(int v) {
        return size[find(v)];
    }
};
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
 
    DSU dsu(n);
    int numComponents = n;
    int largestComponent = 1;
 
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
 
        if (dsu.find(a) != dsu.find(b)) {
            dsu.unite(a, b);
            numComponents--;
        }
     
        // Update the largest component size
        largestComponent = max(largestComponent, dsu.getSize(a));
 
        // Output the number of components and the size of the largest component
        cout << numComponents << " " << largestComponent << '\n';
    }
 
    return 0;
}
