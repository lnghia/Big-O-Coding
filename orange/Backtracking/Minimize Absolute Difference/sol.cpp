#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

bool cmp(long long num, long long denom, long long _num, long long _denom) { 
    long long a = num * _denom;
    long long b = _num * denom;
    return (a < b);
}

void check(long long(&c)[5], long long(&a)[5], long long(&minn)[2], long long(&ans)[4]) {
    long long num = abs(c[a[0]] * c[a[3]] - c[a[1]] * c[a[2]]), denom = c[a[1]] * c[a[3]];
    if (cmp(num, denom, minn[0], minn[1])) {
        minn[0] = num;
        minn[1] = denom;
        for (long long i = 0; i < 4; i++) ans[i] = a[i];
    }
}

void permutation(long long(&c)[5], long long(&a)[5], bool(&b)[5], long long j, long long(&minn)[2], long long(&ans)[4]) {
    for (long long i = 0; i < 5; i++) {
        if (b[i]) {
            a[j] = i;
            b[i] = false;
            if (j == 3) {
                check(c, a, minn, ans);
            }
            else permutation(c, a, b, j + 1, minn, ans);
            b[i] = true;
        }
    }
}
int main() {
    long long a[5], c[5], ans[4];
    for (long long i = 0; i < 5; i++) cin >> c[i];
    long long minn[2];
    minn[0] = 10000000007; minn[1] = 1;
    for (int i = 0; i < 5; i++) a[i] = i;
    for (int i = 0; i < 4; i++) ans[i] = 0;

    bool b[5];
    for (long long i = 0; i < 5; i++) b[i] = true;
    permutation(c, a, b, 0, minn, ans);
    cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << endl;

    return 0;
}