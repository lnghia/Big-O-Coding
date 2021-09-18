#include <bits/stdc++.h> 

using namespace std;

int n; 

int main () {
	while (1) {
		cin >> n; 
		if (n == 0) {
			break; 
		}

		int a = 0;
		int b = 0; 

		int flag = 0; 

		for (int i = 0; i <= 30; i++) {
			if ((n & (1 << i)) > 0) {
				(flag == 0 ? a += 1 << i : b += 1 << i);
				flag = !flag; 	
			}
		}

		cout << a << ' ' << b << endl;
	} 
	return 0; 
}