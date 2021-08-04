#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n, t1, t2, count=0;
	vector<int> a, b, a1, b1;

	cin >> n;
	while(n--){
		cin >> t1 >> t2;
		a.push_back(t1);
		b.push_back(t2);
		a1.push_back(t1);
		b1.push_back(t2);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	for(int i=0; i<a.size(); ++i){
		if(a1[i]==a[0] && b1[i]==b[b.size()-1]){
			cout << i+1;
			return 0;
		}
	}
	cout << -1;

	return 0;
}
