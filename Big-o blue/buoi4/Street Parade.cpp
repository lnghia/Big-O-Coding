#include <bits/stdc++.h>
#include <stack>
#include <vector>

using namespace std;

string solve(vector<int> a){
	int i=1;
	stack<int> b;
	//vector<int> ans;

	for(int j=0; j<a.size(); ++j){
		while(!b.empty()){
			int tmp=b.top();
			if(tmp==i){
				b.pop();
				++i;
				//ans.push_back(tmp);
			}
			else{
				break;
			}
		}
		if(a[j]!=i){
			b.push(a[j]);
		}
		else{
			++i;
		}
	}

	while(!b.empty()){
		if(b.top()==i){
			b.pop();
			++i;
		}
		else{
			return "no";
		}
	}

	return "yes";
}

int main(){
	int n, t;

	while(1){
		vector<int> a;
		cin >> n;
		if(n==0){
			return 0;
		}
		for(int i=0; i<n; ++i){
			cin >> t;
			a.push_back(t);
		}
		cout << solve(a) << '\n';
	}

	return 0;
}