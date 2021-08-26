#include <bits/stdc++.h>

using namespace std;

bool check(vector<vector<bool>>& board2, int i, int j){
    for(int r = 0; r < 8; ++r){
        if(board2[r][j])
            return 0;
    }

    for(int r = i, c = j; c >= 0 && r >= 0; --r, --c){
        if(board2[r][c])
            return 0;
    }

    for(int r = i, c = j; c < 8 && r >= 0; --r, ++c){
        if(board2[r][c])
            return 0;
    }

    return true;
}

void backtrack(vector<vector<int>>& board, vector<vector<bool>>& board2, int i, int& maxScore, int sum){
    if(i == 8){
        maxScore = max(maxScore, sum);
        return;
    }

    for(int j = 0; j < 8; ++j){
        if(check(board2, i, j)){
            sum += board[i][j];
            board2[i][j] = 1;
            backtrack(board, board2, i + 1, maxScore, sum);
            board2[i][j] = 0;
            sum -= board[i][j];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k, tmp, ans;
    vector<vector<int>> board;
    vector<vector<bool>> board2;

    cin >> k;
    board.resize(8);
    board2.resize(8, vector<bool>(8, 0));
    while(k--){
        ans = -1;
        if(board[0].size()){
            for(int i = 0; i < 8; ++i){
                board[i].clear();
            }
        }

        for(int i = 0; i < 8; ++i){
            for(int j = 0; j < 8; ++j){
                cin >> tmp;
                board[i].push_back(tmp);
            }
        }

        backtrack(board, board2, 0, ans, 0);

        printf("%5d\n", ans);
    }

    return 0;
}