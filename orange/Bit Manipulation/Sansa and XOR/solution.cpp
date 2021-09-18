#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int tmp, res = 0;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            if (((long long)n - i) * (i + 1) % 2 == 1) res ^= tmp;
        }
        cout << res << endl;
    }
    return 0;
}