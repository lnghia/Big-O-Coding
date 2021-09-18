#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> dp;

int solve(vector<int>& a, int l){
    dp.assign(a.size() + 1, vector<pair<int, int>>(l + 1, {a[0], 1}));
    for(int i = 2; i <= a.size(); ++i){
        for(int j = 1; j <= l; ++j){
            if(a[i - 1] <= dp[i - 1][j - 1].first){
                int tmp1 = dp[i - 1][j - 1].second + 1;
                int tmp2 = dp[i - 1][j].second;

                if(tmp1 > tmp2){
                    dp[i][j] = {a[i], tmp1};
                }
                else{
                    dp[i][j] = {a[i], tmp2};
                }
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp.back().back().second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    int n;
    int tmp;

    cin >> t;
    while(t--){
        vector<int> a;

        cin >> n;
        for(int i = 0; i < n; ++i){
            cin >> tmp;
            a.push_back(tmp);
        }

        cout << solve(a, n) << '\n';
    }

    return 0;
}