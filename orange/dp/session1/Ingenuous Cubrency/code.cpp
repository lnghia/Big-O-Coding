#include <bits/stdc++.h>

using namespace std;

long long solve(int total, int coins[], int n){
    vector<long long> dp(total + 1);

    dp[0] = 1;
    for(int i = 0; i < n; ++i){
        for(int j = coins[i]; j <= total; ++j){
            dp[j] += dp[j - coins[i]];
        }
    }

    return dp[total];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int coins[21];

    for(int i = 0; i < 21; ++i){
        coins[i] = pow(i + 1, 3);
    }

    while(cin >> n){
        cout << solve(n, coins, 21) << '\n';
    }

    return 0;
}