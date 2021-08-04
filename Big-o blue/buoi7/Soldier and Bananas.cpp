#include <bits/stdc++.h>

using namespace std;

int main(){
	long long a, b, c, sum=0;

	cin >> a >> b >> c;
	for(long long i=1; i<=c; ++i){
		sum+=i*a;
	}
	if(sum-b<=0){
		cout << 0;

		return 0;
	}
	cout << sum-b;

	return 0;
}