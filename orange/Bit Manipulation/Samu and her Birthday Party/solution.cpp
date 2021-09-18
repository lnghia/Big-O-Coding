#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int Count1(int x) {
	int cnt = 0;
	while (x) {
		if (x & 1) ++cnt;
		x >>= 1;
	}
	return cnt;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<string> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		int max_value = 1 << k;
		int ans = n;
		for (int i = 1; i < max_value; i++) {
			bool satisfied_choice = true;
			for (int v = 0; v < n; v++) {
				bool flag = false;
				for (int u = 0; u < k; u++) {
					if (arr[v][u] == '1' && (i & (1 << u))) {
						flag = true;
						break;
					}
				}
				if (!flag) {
					satisfied_choice = false;
					break;
				}
			}
			if (satisfied_choice) {
				ans = min(ans, Count1(i));
			}
		}

		cout << ans << endl;
	}
	return 0;
}