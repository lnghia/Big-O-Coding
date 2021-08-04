#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
	int n, q;
	vector<int> a;
	int t1;
	double t;

	cin >> n >> q;
	int tmp=n*2;
	while(tmp--){
		cin >> t1;
		a.push_back(t1);
	}
	sort(a.begin(), a.end());
	t=min((double)a[0], double(a[n])/2);
	t=min(t, (double)q/(double)(3*n));

	cout << fixed << setprecision(1) << 3*(double)t*(double)n;

	return 0;
}