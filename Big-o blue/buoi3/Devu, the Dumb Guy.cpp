#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n, x, t;
	long long ans=0;
	vector<int> a;

	cin >> n >> x;
	for(int i=0; i<n; ++i){
		cin >> t;
		a.push_back(t);
	}
	sort(a.begin(), a.end());
	for(int i=0; i<n; ++i){
		if(x>1){
			ans+=(long long)x--*(long long)a[i];
		}
		else{
			ans+=(long long)x*(long long)a[i];
		}
	}
	cout << ans;

	return 0;
}