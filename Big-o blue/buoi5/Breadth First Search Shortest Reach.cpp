#include <bits/stdc++.h>
#include <queue>

using namespace std;

void solve(){
	int u, v;
	int s;

	cin >> u >> v;
	int t1=u;
	bool visited[u+1]={0};
	int path[u+1]={-1};
	vector<int> graph[u+1];
	queue<int> q;

	for(int i=0; i<u+1; ++i){
		path[i]=-1;
	}

	while(v--){
		int a, b;

		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	cin >> s;
	q.push(s);
	visited[s]=1;

	/*for(int i=0; i<u+1; ++i){

	}*/

	while(!q.empty()){
		int temp=q.front();
		q.pop();

		for(int i=0; i<graph[temp].size(); ++i){
			int t=graph[temp][i];
			if(!visited[t]){
				q.push(t);
				visited[t]=1;
				path[t]=temp;
			}
		}
	}
	
	for(int i=1; i<=t1; ++i){
		int ans=0;
		int j=i;
		if(j!=s){
			while(path[j]!=s && path[j]!=-1){
				ans+=6;
				j=path[j];
			}
			ans+=6;
			if(path[j]==-1){
				cout << -1 << ' ';
			}
			else{
				cout << ans << ' ';	
			}
		}
	}
	cout << '\n';
}

int main(){
	int q;

	cin >> q;
	while(q--){
		solve();
	}

	return 0;
}