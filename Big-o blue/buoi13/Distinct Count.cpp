#include <bits/stdc++.h>

using namespace std;

int main(){
	int t, n, x;

	cin >> t;
	while(t--){
		set<int> a;
		int tmp;

		cin >> n >> x;
		while(n--){
			cin >> tmp;
			a.insert(tmp);
		}
		if(a.size()<x){
			cout << "Bad\n";
		}
		else if(a.size()==x){
			cout << "Good\n";
		}
		else{
			cout << "Average\n";
		}
	}

	return 0;
}