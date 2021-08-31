#include <bits/stdc++.h>

using namespace std;

long long solve(vector<long long> &dp, long long n)
{
    if (n <= 10)
    {
        return dp[n] = n;
    }

    if (n < 1e7)
    {
        if (!dp[n])
        {
            int tmp = max(n, solve(dp, n / 2) + solve(dp, n / 3) + solve(dp, n / 4));
            dp[n] = tmp;
        }
        else
        {
            return dp[n];
        }
    }

    return max(n, solve(dp, n / 2) + solve(dp, n / 3) + solve(dp, n / 4));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<long long> dp(1e7, 0);
    long long n;

    while (cin >> n)
    {
        cout << solve(dp, n) << '\n';
    }

    return 0;
}