#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    long long n, m;
    vector<int> pos_one;
    cin >> t;

    for (int tc = 0; tc < t; tc++) {
        cin >> n >> m;
        
        int i = 0;
        while (m != 0) {
            if (m & 1) {
                pos_one.push_back(i);
            }
            m >>= 1;
            i++;
        }

        for (int i = pos_one.size() - 1; i >= 0; i--) {
            if (i != pos_one.size() - 1) {
                cout << " + ";
            }
            cout << "(" << n << "<<" << pos_one[i] << ")";
        }
        cout << endl;
        pos_one.clear();
    }

    return 0;
}