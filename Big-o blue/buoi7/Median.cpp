#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	vector<int> a;

	cin >> n;
	while(n--){
		int t;

		cin >> t;
		a.push_back(t);
	}
	sort(a.begin(), a.end());

	int i=0, j=2;
	while(j<=a.size()-1){
		++i;
		j+=2;
	}
	cout << a[i];

	return 0;
}