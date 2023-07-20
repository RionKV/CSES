#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
string dir = "URDL";

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> arr(n, vector<char>(m));
    int i_s, j_s, i_e, j_e;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'A') {
                i_s = i;
                j_s = j;
            }
            if (arr[i][j] == 'B') {
                i_e = i;
                j_e = j;
            }
        }
    }

    vector<vector<int>> dist(n, vector<int>(m, -1));
    vector<vector<int>> parent(n, vector<int>(m, -1));

    queue<pair<int, int>> q;
    q.push({i_s, j_s});
    dist[i_s][j_s] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == i_e && y == j_e) break;

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] != '#' && dist[nx][ny] == -1) {
                q.push({nx, ny});
                dist[nx][ny] = dist[x][y] + 1;
                parent[nx][ny] = k;
            }
        }
    }

    if (dist[i_e][j_e] == -1) {
        cout << "NO";
        return 0;
    }

    cout << "YES" << endl;
    cout << dist[i_e][j_e] << endl;

    string ans;
    int x = i_e, y = j_e;
    while (x != i_s || y != j_s) {
        int d = parent[x][y];
        ans.push_back(dir[d]);
        x -= dx[d];
        y -= dy[d];
    }

    reverse(ans.begin(), ans.end());
    cout << ans;

    return 0;
}
