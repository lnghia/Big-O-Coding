#include <bits/stdc++.h>

using namespace std;

struct road{
	int s;
	int d;
	double p;

	road(int a, int b, double c){
		s=a;
		d=b;
		p=c;
	}
};

void bmf(vector<road> &map, vector<double> &possibility){
	int u, v;
	double p;

	possibility[1]=1;
	for(int i=1; i<possibility.size(); ++i){
		for(int j=0; j<map.size(); ++j){
			u=map[j].s;
			v=map[j].d;
			p=map[j].p*possibility[u];
			if(possibility[u]!=1e9 && p>possibility[v]){
				possibility[v]=p;
			}
		}
	}
}

double solve(int n, int m){
	double ans, p;
	int a, b;
	vector<road> map;
	vector<double> possibility;

	possibility.resize(n+1, 0);
	for(int i=0; i<m; ++i){
		cin >> a >> b >> p;
		map.push_back(road(a, b, p/100));
		map.push_back(road(b, a, p/100));
	}
	bmf(map, possibility);
	ans=possibility[n];

	return ans*100;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;

	while(1){
		cin >> n;
		if(!n){
			return 0;
		}
		cin >> m;
		cout << std::fixed << std::setprecision(6) << solve(n, m) << " percent" << '\n';
	}

	return 0;
}