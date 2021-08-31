#include <bits/stdc++.h>

using namespace std;

int main(){
  	ios::sync_with_stdio(false);
  	cin.tie(NULL);
  	cout.tie(NULL);
  
    vector<vector<int>> dp;
    int n, k;

    cin >> n >> k;
    if(n == 1){
        cout << n;

        return 0;
    }

    int curr = 1;

    dp.push_back({1, k - 1});
    while(curr < n - 1){
        dp.push_back({0, 0});
        dp[curr][0] = dp[curr - 1][1];
        dp[curr][1] = (dp[curr - 1][0] + dp[curr - 1][1]) * (k - 1);
        ++curr;
    }

    cout << dp[curr-1][0] * (k - 1) + dp[curr - 1][1] * (k - 1);

    return 0;
}