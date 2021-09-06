#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& agnes, vector<int>& tom){
    vector<vector<int>> dp;

    dp.resize(agnes.size() + 1, vector<int>(tom.size() + 1, 0));

    for(int i = 1; i <= agnes.size(); ++i){
        for(int j = 1; j <= tom.size(); ++j){
            if(agnes[i - 1] == tom[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp.back().back();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, tmp;
    int ans = -1e9;
    bool isZero = 0;
    vector<int> agnes;
    vector<vector<int>> tom; 

    cin >> t;
    while(t--){
        ans = -1e9;
        if(!tom.empty()){
            for(auto& v : tom) v.clear();
            tom.clear();
            agnes.clear();
        }

        cin >> tmp;
        while(tmp){
            agnes.push_back(tmp);
            cin >> tmp;
        }
        agnes.push_back(tmp);

        tom.push_back(vector<int>());
        while(cin >> tmp){
            if(!tmp){
                if(isZero) break;
                isZero = 1;
                // tom.back().push_back(tmp);
                tom.push_back(vector<int>());

                continue;
            }
            else{
                isZero = 0;
            }

            tom.back().push_back(tmp);
        }

        for(auto& route : tom){
            ans = max(ans, solve(agnes, route));
        }
        cout << ans << '\n';
    }

    return 0;
}