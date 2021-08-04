#include <bits/stdc++.h>

using namespace std;

void solve(int n, int q){
	int tmp;
	vector<int> marbles;
	vector<int> queries;
	vector<pair<int, int> > mark(1e9, make_pair(0, -1));

	while(n--){
		cin >> tmp;
		marbles.push_back(tmp);
	}
	while(q--){
		cin >> tmp;
		queries.push_back(tmp);
	}

	sort(marbles.begin(), marbles.end());
	for(int i=0; i<queries.size(); ++i){
		if(mark[queries[i]].first){
			if(mark[queries[i]].second!=-1)
				cout << queries[i] << " found at " << mark[queries[i]].second << '\n';
			else{
				cout << queries[i] << " not found\n";
			}

			continue;
		}

		vector<int>::iterator element=lower_bound(marbles.begin(), marbles.end(), queries[i]);
		int index=element-marbles.begin();

		if(index>=0 && index<marbles.size()){
			if(marbles[index]==queries[i]){
				cout << queries[i] << " found at " << index+1 << '\n';
				++mark[queries[i]].first;
				mark[queries[i]].second=index+1;
			}
			else{
				cout << queries[i] << " not found\n";
				++mark[queries[i]].first;
			}
		}
		else{
			cout << queries[i] << " not found\n";
			++mark[queries[i]].first;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, q, i=1;

	while(1){
		cin >> n >> q;
		if(!n && !q){
			return 0;
		}
		cout << "CASE# " << i++ << ":\n";
		solve(n, q);
	}

	return 0;
}