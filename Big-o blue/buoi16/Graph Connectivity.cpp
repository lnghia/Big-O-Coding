#include <bits/stdc++.h>

using namespace std;

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

int solve(char temp){
	int ans=0;
	string e;
	vector<int> rank(26, 0);
	vector<int> parent(26);

	makeSet(parent);
	cin.ignore();
	while(getline(cin, e)){
		if(e==""){
			break;
		}
		uniteSet(e[0]-65, e[1]-65, parent, rank);
	}

	for(int i=0; i<parent.size(); ++i){
		ans+=(parent[i]==i && i<=temp-65);
	}

	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	char temp;

	cin >> n;
	while(n--){
		cin >> temp;
		cout << solve(temp);
		if(n>=1){
			cout << '\n';
			cout << '\n';
		}
	}

	return 0;
}