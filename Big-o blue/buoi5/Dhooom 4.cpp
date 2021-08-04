#include <bits/stdc++.h>

using namespace std;

int main(){
	long long n, s, f;
	long long t;
	vector<long long> a;
	vector<bool> b;
	queue<long long> c;
	vector<long long> path;

	cin >> s >> f >> n;
	for(long long i=0; i<n; ++i){
		cin >> t;
		a.push_back(t);
	}
	for(long long i=0; i<=100001; ++i){
		bool tmp=0;
		path.push_back(-1);
		b.push_back(tmp);
	}
	c.push(s);	
	b[s]=1;
	while(!c.empty()){
		long long temp=c.front();
		c.pop();
		if(temp==f){
			break;
		}
		for(long long i=0; i<n; ++i){
			long long tmp=temp*a[i];
			tmp%=100000;
			if(!b[tmp]){
				c.push(tmp);
				path[tmp]=temp;
				b[tmp]=1;
			}
		}
	}
	long long count=0;
	if(path[f]==-1){
		cout << -1;

		return 0;
	}
	while(path[f]!=s){
		++count;
		f=path[f];
	}
	cout << count+1;

	return 0;
}