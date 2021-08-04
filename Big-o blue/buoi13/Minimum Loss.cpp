#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, i=1;
	long long tmp, ans=1e16;
	vector<long long> a;
	set<long long> b;

	cin >> n;
	while(n--){
		cin >> tmp;
		a.push_back(tmp);
	}
	set<long long>::iterator it;

	for(int i=1; i<a.size(); ++i){	
		b.insert(a[i-1]);
		it=b.upper_bound(a[i]);
		if(it!=b.end())
			ans=min(ans, (*it)-a[i]);
	}
	cout << ans;

	return 0;
}