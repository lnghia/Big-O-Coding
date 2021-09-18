#include<iostream>
using namespace std;

bool IsPowerOfTwo(int x) {
	return (x & (x - 1)) == 0;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;      
		bool flag = false;
		int* arr = new int[n];

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		for (int i = 0, e = 1; i < 31; i++, e <<= 1) {
			int and_sub_array = 0xFFFFFFFF;
			for (int j = 0; j < n; j++) {
				if (arr[j] & e) {
					and_sub_array &= arr[j];
				}
			}
			if (IsPowerOfTwo(and_sub_array)) {
				flag = true;
				break;
			}
		}

		cout << (flag ? "YES" : "NO") << endl;
	}
	return 0;
}