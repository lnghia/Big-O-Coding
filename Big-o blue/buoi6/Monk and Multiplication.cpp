#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<long long> ans, a;
	priority_queue<long long, vector<long long>, greater<long long> > q;
	int n;

	cin >> n;
	ans.resize(n); a.resize(n);
	for(int i=0; i<n; ++i){
		int t;

		cin >> t;
		if(i==0 || i==1){
			ans[i]=-1;
			a[i]=t;
			q.push(t);
		}
		else{
			q.push(t);
			if(i==2){
				ans[i]=t*a[0]*a[1];
				continue;
			}
			if(t==q.top()){
				ans[i]=ans[i-1];
			}
			else{
				ans[i]=t*(ans[i-1]/q.top());
			}
			q.pop();
		}
	}

	for(int i=0; i<ans.size(); ++i){
		cout << ans[i] << '\n';
	}

	return 0;
}