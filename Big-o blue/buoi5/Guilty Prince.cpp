#include <bits/stdc++.h>
#include <vector>

using namespace std;

void dosth(int x, int y, queue<pair<int, int> > &q, vector<vector<bool> > &visited, vector<vector<char> > a, int &ans){
	if(!visited[x][y]){
		if(a[x][y]=='.'){
			visited[x][y]=1;
			q.push(make_pair(x, y));
			++ans;
		}
	}
}

int solve(){
	int m, n, ans=0, x, y;
	char t;
	vector<vector<char> > a;
	queue<pair<int, int> > q;
	vector<vector<bool> > visited;

	cin >> m >> n;
	a.resize(n); visited.resize(n);
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			cin >> t;
			if(t=='@'){
				x=i;
				y=j;
			}
			a[i].push_back(t);
			bool t=0;
			visited[i].push_back(t);
		}
	}
	q.push(make_pair(x, y));
	visited[x][y]=1;

	while(!q.empty()){
		pair<int, int> p=q.front();
		q.pop();
		if(p.first>0){
			dosth(p.first-1, p.second, q, visited, a, ans);
		}
		if(p.first<(n-1)){
			dosth(p.first+1, p.second, q, visited, a, ans);
		}
		if(p.second>0){
			dosth(p.first, p.second-1, q, visited, a, ans);
		}
		if(p.second<(m-1)){
			dosth(p.first, p.second+1, q, visited, a, ans);
		}
	}

	return ans+1;
}

int main(){
	int n, i=1;

	cin >> n;
	while(n--){
		cout << "Case " << i++ << ": " << solve() << '\n';
	}

	return 0;
}