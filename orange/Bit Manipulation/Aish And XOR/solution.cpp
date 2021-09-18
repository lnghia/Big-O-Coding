#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q, l, r;
    cin >> n;
    vector<int> a(n + 1, 0), f(n + 1, 0);

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
        if (a[i] == 0) f[i] = f[i - 1] + 1;
        else f[i] = f[i - 1];
    cin >> q;
    while (q--) {
        cin >> l >> r;
        int nZero = f[r] - f[l - 1];
        int nOne = r - l + 1 - nZero;
        if (nOne % 2 == 0) cout << 0 << " " << nZero << endl;
        else cout << 1 << " " << nZero << endl;
    }
    return 0;
}