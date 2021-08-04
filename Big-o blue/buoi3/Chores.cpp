#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n, a, b;
	int t;
	vector<int> t1;

	cin >> n >> a >> b;
	while(n--){
		cin >> t;
		t1.push_back(t);
	}
	sort(t1.begin(), t1.end());

	cout << (t1[b]-t1[b-1]);

	return 0;
}