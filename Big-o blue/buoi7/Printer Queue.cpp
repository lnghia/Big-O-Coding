#include <bits/stdc++.h>

using namespace std;

struct job{
	int p;
	int pos;

	job(int a, int b){
		p=a;
		pos=b;
	}

	bool operator <(const job &a) const {
		return p<a.p || pos<a.pos;
	}
};

int solve(int a, int b){
	int ans=0, t;
	priority_queue<int> q;
	queue<pair<int, int> > q1;
	vector<pair<int, int> > k;

	for(int i=0; i<a; ++i){
		cin >> t;
		q.push(t);
		q1.push(make_pair(t, i));
		k.push_back(make_pair(t, i));
	}

	while(!q1.empty()){
		pair<int, int> tmp=q1.front();
		q1.pop();

		if(tmp.first==q.top()){
			++ans;
			q.pop();
			if(tmp.second==b){
				return ans;
			}
		}
		else{
			q1.push(tmp);
		}
	}

	return ans;
}

int main(){
	int n;

	cin >> n;
	while(n--){
		int a, b;

		cin >> a >> b;
		cout << solve(a, b) << '\n';
	}

	return 0;
}