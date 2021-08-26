#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n;
    long long ans = 0;
    vector<long long> a;
    vector<int> appeared;

    cin >> n;
    a.resize(n, 0);
    appeared.resize(n + 1, 0);
    for(auto& i : a){
        cin >> i;
        if(i <= n && i > 0) ++appeared[i];
    }

    sort(a.begin(), a.end());

    long long j = 1;
    for(auto& i : a){
        if(i <= 0 || i > n || appeared[i] > 1){
            while(appeared[j] && j <= n) ++j;
            ans += abs(i - j);
            appeared[j] = 1;
            if(i > 0 && i <= n) --appeared[i];
            i = j;
            ++j;
        }
    }

    cout << ans << '\n';

    return 0;
}