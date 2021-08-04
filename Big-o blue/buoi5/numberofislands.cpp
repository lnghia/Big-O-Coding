#include <bits/stdc++.h>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<pair<int, int>> pos;
        queue<pair<int, int>> q;
        int m=grid.size(), n=(m)?grid[0].size():0;
        int ans=0;
        int d1[]={0, 0, 1, -1};
        int d2[]={1, -1, 0, 0};
        
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j]=='1'){
                    pos.push_back({i, j});
                }
            }
        }
        
        for(int i=0; i<pos.size(); ++i){
            int x=pos[i].first, y=pos[i].second;
            
            if(grid[x][y]=='1'){
                q.push({x, y});
                grid[x][y]='2';
                while(!q.empty()){
                    pair<int, int> tmp=q.front();
                    
                    q.pop();
                    for(int j=0; j<4; ++j){
                        int _x=tmp.first+d1[j], _y=tmp.second+d2[j];
                        
                        if(_x>=0 && _x<m && _y>=0 && _y<n && grid[_x][_y]=='1'){
                            q.push({_x, _y});
                            grid[_x][_y]='2';
                        }
                    }
                }
                ++ans;
            }
        }
        
        return ans;
    }
};

int main(){
    Solution sol;
    int m, n;
    char tmp;
    vector<vector<char>> a;

    cin >> m >> n;
    a.resize(m);
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            cin >> tmp;
            a[i].push_back(tmp);
        }
    }

    cout << sol.numIslands(a) << '\n';

    return 0;
}