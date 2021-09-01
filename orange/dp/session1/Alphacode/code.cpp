#include <bits/stdc++.h>

using namespace std;

long long solve(string& n){
    vector<long long> dp(n.length() + 1, 0);
    long long temp = 0;
    int tmp = 0;

    dp[0] = dp[1] = 1;
    for(int i = 2; i <= n.length(); ++i){
        tmp = (n[i - 2] - '0') * 10 + (n[i - 1] - '0');
        if(n[i - 1] != '0') dp[i] = dp[i - 1];
        if(tmp <= 26 && tmp >= 10) dp[i] += dp[i - 2];
    }

    return dp.back();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string n;

    while(cin >> n){
        if(n == "0") break;
        cout << solve(n) << '\n';
    }

    return 0;
}