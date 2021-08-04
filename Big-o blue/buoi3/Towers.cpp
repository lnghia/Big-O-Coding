#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n, t, c=0, max=0, count=0;
	vector<int> a;
	int b[1001]={};

	cin >> n;
	while(n--){
		cin >> t;
		++b[t];
	}
	while(c++<1001){
		max=(max<b[c])?b[c]:max;
		count+=(b[c]>0);
	}
	cout << max << ' ' << count;

	return 0;
}