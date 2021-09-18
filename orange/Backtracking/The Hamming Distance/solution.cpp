#include <iostream>
#include <string>

using namespace std;

void check(int n, int h, int idx, int start, string res) {
    if (idx == h) {
        cout << res << endl;
        return;
    }

    for (int i = n - h + idx; i > start - 1; --i) {
        res[i] = '1';
        check(n, h, idx + 1, i + 1, res);
        res[i] = '0';
    }
}

void solve() {
    int n, h;
    cin >> n >> h;
    string res(n, '0');
    check(n, h, 0, 0, res); 
}

int main() {
    int t;
    cin >> t;
    
    for (int tc = 0; tc < t; ++tc) {
        solve();
        if (tc < t - 1) {
            cout << endl;
        }
    }

    return 0;
}