#include <bits/stdc++.h>
#include <vector>

using namespace std;

bool isRestaurent(int k, vector<int> &des){
	for(int i=0; i<des.size(); ++i){
		if(des[i]==k){
			return 1;
		}
	}

	return 0;
}

int solve(int m, int n){
	int t;
	queue<int> q;
	vector<int> b;
	vector<int> des;
	vector<vector<int> > a;
	vector<bool> visited;
	vector<int> path;
	int ans=0;

	a.resize(m+1); b.resize(m+1); visited.resize(m+1);
	path.resize(m+1); path[0]=-1; 
	for(int i=1; i<=m; ++i){
		cin >> t;
		b[i]=t;
		visited[i]=0;
		path[i]=-1;
	}
	for(int i=0; i<m-1; ++i){
		int k, l;

		cin >> k >> l;
		a[k].push_back(l);
		a[l].push_back(k);
	}
	for(int i=1; i<=m; ++i){
		if(a[i].size()==1 && i!=1){
			des.push_back(i);
		}
	}
	q.push(1);
	visited[1]=1;
	while(!q.empty()){
		int temp=q.front();
		q.pop();
		for(int j=0; j<a[temp].size(); ++j){
			if(!visited[a[temp][j]]){
				if(b[a[temp][j]]==1){
					b[a[temp][j]]+=b[temp];
				}
				if(b[a[temp][j]]>n){
					continue;
				}
				if(isRestaurent(a[temp][j], des)){
					++ans;
				}
				visited[a[temp][j]]=1;
				q.push(a[temp][j]);
				path[a[temp][j]]=temp;
			}
		}
	}

	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int m, n;

	cin >> m >> n;
	cout << solve(m, n);

	return 0;
}