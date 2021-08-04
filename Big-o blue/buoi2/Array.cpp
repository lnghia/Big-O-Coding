#include <iostream>

using namespace std;

int main(){
	int n, k;
	//two pointers
	int a[100000]={};
	int t, count=0, l=0, r=0;

	cin >> n >> k;
	while(n--){
		cin >> t;
		++a[t];
		count+=(a[t]==1);
		if(count==k){
			while(a[l]>1){
				--a[l];
				++l;
			}
			cout << l+1 << ' ' << r+1;
			return 0;
		}
		++r;
	}
	cout << -1 << ' ' << -1;

	return 0;
}