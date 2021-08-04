#include <bits/stdc++.h>

using namespace std;

struct door{
	int start;
	int des;

	door(int s, int d){
		start=s;
		des=d;
	}
};

bool bmf(vector<door> &map, vector<int> &energy, vector<int> &energylevel){
	int s, d, e;
	energylevel[1]=100;

	for(int i=1; i<=energy.size()-1; ++i){
		for(int j=0; j<map.size(); ++j){
			s=map[j].start;
			d=map[j].des;
			e=energylevel[s]+energy[d];	
			if(energylevel[s]!=1e9 && e>0){
				energylevel[d]=e;
			}
		}
	}

	/*for(int i=0; i<map.size(); ++i){
		s=map[i].start;
		d=map[i].des;
		e=energy[s]+energy[d];
		if(energylevel[s]!=1e9 && e<energylevel[d]){
			return false;
		}
	}*/

	return true;
}

string solve(int n){
	vector<int> energy;
	vector<door> map;
	vector<int> energylevel; 
	string ans="hopeless";

	energy.resize(n+1); energylevel.resize(n+1);
	for(int i=1; i<=n; ++i){
		int t, t1, t2;

		cin >> t >> t1;
		energy[i]=t;
		energylevel[i]=1e9;
		while(t1--){
			cin >> t2;
			map.push_back(door(i, t2));
		}
	}

	bmf(map, energy, energylevel);
	if(energylevel[n]!=1e9 && energylevel[n]>0){
		ans="winnable";
	}

	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;

	while(1){
		cin >> n;
		if(n==-1){
			return 0;
		}
		cout << solve(n) << '\n';
	}


	return 0;
}