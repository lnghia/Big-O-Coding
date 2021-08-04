#include <bits/stdc++.h>

using namespace std;

void solve(long long n){
	priority_queue<long long, vector<long long>, greater<long long> > q;
	long long tmp, temp=0, i=0;

	while(n--){
		cin >> tmp;

		q.push(tmp);
	}
	while(q.size()>1){
		int a=q.top();
		q.pop();
		int b=q.top();
		q.pop();
		temp+=a+b;
		q.push(a+b);
	}

	cout << temp << '\n';
}

int main(){
	while(1){
		long long n;

		cin >> n;
		if(n==0){
			return 0;
		}
		solve(n);
	}

	return 0;
}