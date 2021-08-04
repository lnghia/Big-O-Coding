#include <bits/stdc++.h>

using namespace std;

int solve(int f, int p){
	vector<int> money;
	int tmp, count=0;

	for(int i=0; i<f; ++i){
		cin >> tmp;

		money.push_back(tmp); 
	}

	sort(money.begin(), money.end());
	for(int i=0; i<f; ++i){
		int o=p-money[i];

		count+=binary_search(money.begin(), money.end(), o);
	}

	return count/2;
}

int main(){
	int n;

	cin >> n;
	while(n--){
		int f, p;

		cin >> f >> p;
		cout << solve(f, p) << '\n';
	}

	return 0;
}