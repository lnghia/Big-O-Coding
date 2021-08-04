#include <bits/stdc++.h>
#include <vector>

using namespace std;

void dosth(int i, int j, vector<vector<bool> > &visited, queue<pair<int, int> > &q, vector<vector<int> > &a, int &size, int &count){
	if(!visited[i][j]){
		if(a[i][j]==1){
			--count;
			q.push(make_pair(i, j));
			visited[i][j]=1;
			++size;
		}
	}
}

void solve(int m, int n){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<vector<int> > a;
	vector<vector<bool> > visited;
	vector<pair<int, int> > pos;
	queue<pair<int, int> > q;
	int t, x=-1, y; bool tmp=0;
	int ans[62501]={}, total=0, count=0;

	a.resize(m); visited.resize(m);
	for(int i=0; i<m; ++i){
		for(int j=0; j<n; ++j){
			cin >> t;
			if(t==1){
				pos.push_back(make_pair(i, j));
				++count;
			}
			a[i].push_back(t);
			visited[i].push_back(tmp);
		}
	}
	for(int i=0; i<pos.size(); ++i){
		int size=0;
		if(count==0){
			break;
		}
		if(!visited[pos[i].first][pos[i].second]){
			q.push(make_pair(pos[i].first, pos[i].second));
			--count;
			visited[pos[i].first][pos[i].second]=1;
			++size;
			while(!q.empty()){
				pair<int, int> temp=q.front();
				q.pop();
				if(temp.first>0){
					dosth(temp.first-1, temp.second, visited, q, a, size, count);
				}
				if(temp.first<m-1){
					dosth(temp.first+1, temp.second, visited, q, a, size, count);
				}
				if(temp.second>0){
					dosth(temp.first, temp.second-1, visited, q, a, size, count);
				}
				if(temp.second<n-1){
					dosth(temp.first, temp.second+1, visited, q, a, size, count);
				}
			}
			++ans[size];
			++total;
		}
	}
	cout << total << '\n';
	for(int i=1; i<62501; ++i){
		if(!total){
			break;
		}
		if(ans[i]){
			cout << i << ' ' << ans[i] << '\n';
			--total;
		}
	}
}

int main(){
	while(1){
		int m, n;
		
		cin >> m >> n;
		if(m==0){
			break;
		}
		solve(m, n);
	}

	return 0;
}