#include <bits/stdc++.h>

using namespace std;

int findSet(vector<int> &parent, int i){
	if(parent[i]!=i){
		parent[i]=findSet(parent, parent[i]);
	}

	return parent[i];
}

void unite(vector<int> &parent, vector<int> rank, int i, int j){
	int u=findSet(parent, i);
	int v=findSet(parent, j);

	if(u==v){
		return;
	}

	if(rank[u]<rank[v]){
		parent[u]=v;
	}
	else if(rank[u]>rank[v]){
		parent[v]=u;
	}
	else{
		parent[v]=u;
		++rank[u];
	}
}

int solve(int n, int m){
	int ans=0, i, j;
	vector<int> parent(n+1);
	vector<int> rank(n+1, 0);

	for(int i=1; i<n+1; ++i){
		parent[i]=i;
	}
	while(m--){
		cin >> i >> j;
		unite(parent, rank, i, j);
	}

	for(int i=1; i<parent.size(); ++i){
		ans+=(parent[i]==i);
	}

	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	int i=1;

	while(cin >> n >> m){
		if(n==0 && m==0){
			break;
		}
		cout << "Case " << i++ << ": " << solve(n, m) << '\n';
	}

	return 0;
}