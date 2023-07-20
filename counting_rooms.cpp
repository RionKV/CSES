#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>> &arr, vector<vector<bool>> &vis, int i, int j){
    if(i<0 || j<0 || i>=arr.size() || j>=arr[0].size() || vis[i][j] || arr[i][j]=='#') {
        return;
    }

    vis[i][j] = true;
    dfs(arr, vis, i+1, j);
    dfs(arr, vis, i-1, j);
    dfs(arr, vis, i, j+1);
    dfs(arr, vis, i, j-1);
}
int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> arr(n, vector<char>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }

    vector<vector<bool>> vis(n, vector<bool>(m, false));

    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(arr[i][j]=='.' && !vis[i][j]) {
                dfs(arr, vis, i, j);
                ans++;
            }
        }
    }

    cout << ans;
}