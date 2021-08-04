#include <iostream>
#include <vector>

using namespace std;

string solve(vector<int> a, vector<int> b, int k, int m){
	int i=k-1, j=b.size()-m;

	//cout << a[i] << ' ' << b[j] << '\n';

	if(a[i]<b[j]){
		return "YES";
	}

	return "NO";
}

int main(){
	int na, nb, k, m, tmp;
	vector<int> a, b;

	cin >> na >> nb;
	cin >> k >> m;
	while(na--){
		cin >> tmp;
		a.push_back(tmp);
	}
	while(nb--){
		cin >> tmp;
		b.push_back(tmp);
	}

	cout << solve(a, b, k, m);

	return 0;
}