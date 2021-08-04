#include <bits/stdc++.h>
#include <vector>

using namespace std;

void dosth(int x, int y, queue<pair<int, int> > &q, vector<vector<bool> > &visited, vector<vector<char> > a){
	if(!visited[x][y]){
		if(a[x][y]=='.'){
			visited[x][y]=1;
			q.push(make_pair(x, y));
		}
	}
}

string solve(){
	int m, n;
	string ans="invalid";

	cin >> m >> n;
	vector<vector<char> > a;
	vector<vector<bool> > visited;
	queue<pair<int, int> > q;

	a.resize(m); visited.resize(m);
	for(int i=0; i<m; ++i){
		for(int j=0; j<n; ++j){
			char t;
			bool tmp=0;

			cin >> t;
			a[i].push_back(t);
			visited[i].push_back(tmp);
		}
	}

	if(m==1 && n==1){
		return "invalid";
	}
	vector<pair<int, int> > k;
	for(int i=0; i<m; ++i){
		for(int j=0; j<n; ++j){
			if(a[i][j]=='.'){
				if(i==0 || i==m-1 || j==0 || j==n-1){
					k.push_back(make_pair(i, j));
				}
			}
		}
	}
	if(k.size()>2 || k.size()<2){
		return "invalid";
	}
	q.push(k[0]);
	while(!q.empty()){
		pair<int, int> u=q.front();
		q.pop();
		if(u.first==k[1].first && u.second==k[1].second){
			ans="valid";
		}
		if(u.first>0){
			dosth(u.first-1, u.second, q, visited, a);
		}
		if(u.first<m-1){
			dosth(u.first+1, u.second, q, visited, a);	
		}
		if(u.second>0){
			dosth(u.first, u.second-1, q, visited, a);
		}
		if(u.second<n-1){
			dosth(u.first, u.second+1, q, visited, a);
		}
	}

	return ans;
}

int main(){
	int t;

	cin >> t;
	while(t--){
		cout << solve() << '\n';
	}

	return 0;
}