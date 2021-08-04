#include <bits/stdc++.h>

using namespace std;

struct option{
	bool operator()(pair<int, int> a, pair<int, int> b){
		return a.second>b.second;
	}
};

int solve(int u, int v, vector<vector<pair<int, int> > > &graph){
	priority_queue<pair<int, int>, vector<pair<int, int> >, option> q;
	int ans=0;
	vector<int> dist(graph.size(), 1e9);

	q.push(make_pair(u, 0));
	dist[u]=0;
	while(!q.empty()){
		pair<int, int> tmp=q.top();

		q.pop();
		for(int i=0; i<graph[tmp.first].size(); ++i){
			pair<int, int> t=graph[tmp.first][i];

			if(tmp.second+t.second<dist[t.first]){
				dist[t.first]=tmp.second+t.second;
				q.push(make_pair(t.first, dist[t.first]));
			}
		}
	}

	ans=dist[v];

	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int s, n, p, nr, cost, r, v, w;
	string name1, name2; 
	map<string, int> m;

	cin >> s;
	while(s--){
		int i=1;
		map<string, int> m;
		vector<vector<pair<int, int> > > graph;

		cin >> n;
		graph.resize(n+1);
		while(n--){
			cin >> name1 >> p;
			m[name1]=i;
			while(p--){
				cin >> nr >> cost;
				graph[i].push_back(make_pair(nr, cost));
				graph[nr].push_back(make_pair(i, cost));
			}
			++i;
		}
		cin >> r;
		while(r--){
			cin >> name1 >> name2;
			cout << solve(m[name1], m[name2], graph) << '\n';
		}
	}

	return 0;
}