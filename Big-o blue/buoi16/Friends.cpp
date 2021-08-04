#include <bits/stdc++.h>

using namespace std;

int findSet(int temp, vector<int> &parent){
	if(parent[temp]!=temp){
		parent[temp]=findSet(parent[temp], parent);
	}

	return parent[temp];
}

void uniteSet(int a, int b, vector<int> &parent, vector<int> &rank){
	int up=findSet(a, parent);
	int vp=findSet(b, parent);

	if(up==vp){
		return;
	}
	if(rank[up]>rank[vp]){
		parent[vp]=up;
	}
	else if(rank[up]<rank[vp]){
		parent[up]=vp;
	}
	else{
		parent[up]=vp;
		++rank[vp];
	}
}

int solve(int n, int m){
	int ans=0, a, b;
	vector<int> parent(n);
	vector<int> rank(n, 0);
	vector<int> count(n, 0);

	for(int i=0; i<parent.size(); ++i){
		parent[i]=i;
	}

	while(m--){
		cin >> a >> b;
		uniteSet(a-1, b-1, parent, rank);
	}

	for(int i=0; i<parent.size(); ++i){
		int tmp=findSet(i, parent);

		++count[tmp];
		ans=max(ans, count[tmp]);
	}

	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n, m;

	cin >> t;
	while(t--){
		cin >> n >> m;
		cout << solve(n, m) << '\n';
	}

	return 0;
}