#include <iostream>
using namespace std;
const int MAX = 15;
int a[MAX], res[6];

void permutation(int i, int p, int k, int lotto_len) {
    if (i == lotto_len) {
        for (int& ele : res) {
            cout << ele << " ";
        }
        cout << endl;
        return;
    }

    for (int j = p; j < k; j++) {
        res[i] = a[j];
        permutation(i + 1, j + 1, k, lotto_len);
    }
}

int main() {
    int k;
    bool blank_line = false;

    while (true) {
        cin >> k;
        if (k == 0) {
            break;
        }

        for (int i = 0; i < k; i++) {
            cin >> a[i];
        }

        if (blank_line) {
            cout << endl;
        }

        permutation(0, 0, k, 6);
        blank_line = true;
    }
}