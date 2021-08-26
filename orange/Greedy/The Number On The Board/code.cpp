#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string n;
    int k;
    int sum = 0;
    int ans = 0;
    int i = 0;
    vector<int> digits;

    cin >> k >> n;
    for(auto& c : n){
        digits.push_back(c - '0');
        sum += (c - '0');
    }

    sort(digits.begin(), digits.end());
    i = 0;

    while(sum < k){
        ans += (digits[i] < 9);
        sum -= digits[i];
        sum += 9;
        digits[i] = 9;
        ++i;
    }

    cout << ans;

    return 0;
}