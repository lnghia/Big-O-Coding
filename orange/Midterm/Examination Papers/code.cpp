#include <bits/stdc++.h>

using namespace std;

long long modularEx(long long a, long long b, long long m){
    long long result = 1;

    a %= m;
    while(b > 0){
        if (b % 2 == 1){
            result = (result * a) % m;
        }
        b /= 2;
        a = (a * a) % m;
    }

    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    long long n;

    cin >> t;
    while(t--){
        cin >> n;

        long long rs = modularEx(2, n, (long long)(1e9 + 7));
        --rs;
        rs %= (long long)(1e9 + 7);
        cout << rs << '\n';
    }

    return 0;
}