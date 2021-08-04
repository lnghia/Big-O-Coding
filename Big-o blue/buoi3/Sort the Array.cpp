#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<int> a){
	for(int i=0; i<a.size()-1; ++i){
		if(a[i]<a[i+1]){
			return 0;
		}
	}

	return 1;
}

int main(){
	int n, t, l, r;
	vector<int> a, b, c;

	cin >> n;
	r=n-1;
	l=0;
	for(int i=0; i<n; ++i){
		cin >> t;
		a.push_back(t);
	}
	b=a;
	sort(b.begin(), b.end());
	while(a[l]==b[l] && l<n){
		++l;
	}
	while(a[r]==b[r] && r>=0){
		--r;
	}
	if(l>r){
		cout << "yes" << '\n';
		cout << 1 << ' ' << 1;

		return 0;
	}
	for(int i=l; i<=r; ++i){
		c.push_back(a[i]);
	}

	if(check(c)){
		cout << "yes" << '\n';
		cout << l+1 << ' ' << r+1; 

		return 0;
	}
	cout << "no";

	return 0;
}