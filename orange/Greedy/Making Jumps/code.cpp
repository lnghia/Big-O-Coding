#include <bits/stdc++.h>

using namespace std;

vector<int> row_moving = {1, 2, 1, 2, -1, -2, -1, -2};
vector<int> column_moving = {2, 1, -2, -1, 2, 1, -2, -1};

bool isCellValid(vector<vector<int>>& board, int r, int c){
    return ((r >= 0 && r < board.size()) && (c >= 0 && c < board[r].size()) && board[r][c] == 1);
}

void dfs(vector<vector<int>>& board, int r, int c){
    stack<pair<int, int>> s;

    s.push({r, c});
    board[r][c] = 2;
    while(!s.empty()){
        int c_r = s.top().first;
        int c_c = s.top().second;

        s.pop();

        for(int i = 0; i < row_moving.size(); ++i){
            int n_r = c_r + row_moving[i];
            int n_c = c_c + column_moving[i];

            if(isCellValid(board, n_r, n_c)){
                cout << n_r << ' ' << n_c << '\n';
                s.push({n_r, n_c});
                board[n_r][n_c] = 2;
            }
        }
    }
}

int countUnreachableCells(vector<vector<int>>& board){
    int rs = 0;
    
    for(auto& r : board){
        for(auto& c : r){
            rs += (c == 1);
        }
    }

    return rs;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> board;
    int n;
    int skippedCells, cellsLeft;
    int case_num = 1;
    int startR, startC;

    while(cin >> n){
        if(!n) break;

        startR = startC = 0;
        board.resize(n);
        for(int i = 0; i < n; ++i){
            cin >> skippedCells >> cellsLeft;

            if(!i){
                startR = 0;
                startC = skippedCells;
            }

            while(skippedCells--){
                board[i].push_back(0);
            }
            while(cellsLeft--){
                board[i].push_back(1);
            }
        }

        dfs(board, startR, startC);

        for(auto& r : board){
            for(auto& c : r){
                cout << c << ' ';
            }
            cout << '\n';
        }
        cout << '\n';

        cout << "Case " << case_num++ << ", " << countUnreachableCells(board) << " squares can not be reached.\n";

        for(auto& r : board){
            r.clear();
        }
        board.clear();
    }

    return 0;
}