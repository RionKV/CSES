#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<char>> &board, int i, int j) {
    int r = i;
    int c = j;
    if(board[r][c]=='*') return false;

    while(r>=0 && c>=0)  {
        if(board[r][c] == 'q') {
            return false;
        }
        r--;
        c--;
    }

    r=i;
    c=j;
    while(c>=0) {
        if(board[r][c]=='q') {
            return false;
        }
        c--;
    }
    r=i;
    c=j;
    while(r<8 && c>=0) {
        if(board[r][c]=='q') {
            return false;
        }
        r++;
        c--;
    }

    return true;
    
}
void solve(int col, vector<vector<char>> &board, int &ans, int n) {
    if(col == n) {
        ans++;
        return;
    }

    for(int row=0; row<8; row++){
        if(isSafe(board, row, col)) {
            board[row][col] = 'q';
            solve(col+1, board, ans, n);
            board[row][col] = '.';
        }
    }
}

int main() {
    vector<vector<char>> board(8, vector<char>(8));

    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            cin >> board[i][j];
        }
    }

    int ans = 0;
    solve(0, board, ans, 8);
    cout << ans << endl;
    return 0;


}