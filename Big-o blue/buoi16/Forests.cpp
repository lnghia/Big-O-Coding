#include <bits/stdc++.h>

using namespace std;

pair<int, int> getIndex(string temp){
	int i=0;
	string _a="", _b="";

	while(temp[i]!=' '){
		_a+=temp[i++];
	}
	++i;
	while(i<temp.length()){
		_b+=temp[i++];
	}

	return make_pair(atoi(_a.c_str()), atoi(_b.c_str()));
}

void makeSet(vector<int> &parent){
	for(int i=0; i<parent.size(); ++i){
		parent[i]=i;
	}
}

int findSet(int t, vector<int> &parent){
	if(parent[t]!=t){
		parent[t]=findSet(parent[t], parent);
	}

	return parent[t];
}

void uniteSet(int u, int v, vector<int> &parent, vector<int> &rank){
	int up=findSet(u, parent);
	int vp=findSet(v, parent);

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

int solve(int p, int t){
	int ans=0, i, j;
	string tmp;
	vector<vector<int> > parent(p+1, vector<int>(t+1, 0));
	vector<int> parents(p+1);
	vector<int> rank(p+1, 0);

	makeSet(parents);
	cin.ignore(); 
	while(getline(cin, tmp)){
		if(tmp==""){
			break;
		}
		pair<int, int> temp=getIndex(tmp);
		parent[temp.first][temp.second]=1;
	}

	for(int i=1; i<parent.size()-1; ++i){
		for(int j=i+1; j<parent.size(); ++j){
			bool t=1;

			for(int k=1; k<parent[i].size(); ++k){
				if((parent[i][k]==0 && parent[j][k]==1) || (parent[i][k]==1 && parent[j][k]==0)){
					t=0;

					break;
				}
			}
			if(t){
				
				uniteSet(i, j, parents, rank);
			}
		}
	}
	for(int i=1; i<parents.size(); ++i){
		ans+=(parents[i]==i);
	}

	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, p, t;

	cin >> n;
	while(n--){
		cin >> p >> t;
		cout << solve(p, t);
		if(n>=1){
			cout << '\n' << '\n';
		}
	}

	return 0;
}